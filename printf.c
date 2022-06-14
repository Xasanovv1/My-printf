#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
void my_putchar(char s){
    write(1, &s,1);
}
int putss(char* arr){
   int i =0;
   while(i <strlen(arr)){
       my_putchar(arr[i]);
       i++;
   }
    return i;
}

 char* intdanCHarga( int p1 ,int p2){

       int arr[10000];
    int arr_ind = 0;
    int neg=0;
    if(p1 < 0){
        p1 = p1*(-1);
        neg++;
    }
    while(p1 > 0){
        arr[arr_ind] = p1 % 10;
        p1 = p1 / 10;
        arr_ind++;
    }
    char *res;
    res = malloc(arr_ind);
    char * negres;
    negres = malloc(arr_ind+1);
    int res_ind = 0;
    for(int i = arr_ind - 1; i >= 0; i--){
        res[res_ind] = arr[i] + '0';
        res_ind++;
    }
    if(neg > 0){
        if(p2 == 0){
            negres[0]= '-';
            for(int i = 0 ; i < strlen(res); i++ ){
                negres[i+1] = res[i] ;
            }
        return negres;
        }
        else{
        return res;
        }
    }
    return res;
}
char* INNadres(int base, unsigned long number)
{
    char* output;
    int last_index = 0;
    if (number == 0)
    {
        return "0";
    }

    char ch;
    unsigned long digit, num_copy = number;
    int size_of_output = 0;
    while (number != 0)
    {
        number = number / base;
        size_of_output++;
    }

    output = (char*)malloc(sizeof(output) * size_of_output);
    last_index = --size_of_output;

    while (num_copy != 0)
    {
        digit = num_copy % base;
        if (digit > 9 && digit < 16 && base == 16)
        
        {
            ch = digit + '0' + 7;
        }
        else
        {
            ch = digit + '0';
        }
        output[last_index] = ch;
        last_index--;
        num_copy = num_copy / base;
    }

    return output;
    free(output);
}



int my_printf(char* str, ...){
    va_list List;
    va_start(List, str);
    int retInt=0;
    char a;
    char* arr1;
    unsigned long inAdress;
    int inTeger =0;
 for(int i =0; i <strlen(str); i++){
        if(str[i]=='%'){
            i++;
            switch (str[i]) {
            case 'c':
                a=(char)va_arg(List, int);
                my_putchar(a);
                retInt++;
            break;
            case 's':
                 arr1=va_arg(List, char*);
                if(arr1==(char*)NULL){
                    arr1="(null)";
                }
              retInt += putss(arr1);
            break;
            case 'd':
                inTeger=va_arg(List, int);
                 if(inTeger == 0){
                        char CH = inTeger + '0';
                        my_putchar(CH);
                        retInt++;
                    }else{
                        putss(intdanCHarga(inTeger,0));
                        retInt += strlen(intdanCHarga(inTeger,0));
                    }
            break;

            case 'u':
             inTeger=va_arg(List, int);
                 if(inTeger == 0){
                        char Xz = inTeger + '0';
                        my_putchar(Xz);
                        retInt++;
                    }else{
                        putss(intdanCHarga(inTeger,0));
                        retInt += strlen(intdanCHarga(inTeger,0));
                    }

            break;
              case 'o': 
                    inTeger = va_arg(List, int);
                    char Num[10000], i = 0;
                    while (inTeger != 0){
                        Num[i++] = inTeger % 8 + '0';
                        inTeger = inTeger / 8;
                        retInt++;
                    }
                    for(int i =strlen(Num)-1 ; i >= 0; i--){
                        my_putchar(Num[i]);
                    }

                    break;;
            case 'x': 
                  inTeger = va_arg(List, int);
                    int in;
                    int T = 0;
                    char num[100];

                    while (inTeger != 0)
                    {
                        retInt++;
                        in = inTeger % 16;
                        if (in < 10)
                           num[T++] = 48 + in;
                        else
                            num[T++] = 55 + in;
                        inTeger = inTeger / 16;
                    }
                    putss(num);
           
            break;

            case 'p':
                inAdress = (unsigned long)va_arg(List, void*);
                my_putchar('0');
                my_putchar('x');
                retInt += 2;
                putss(INNadres(16, inAdress));
                arr1=INNadres(16, inAdress);
                while(*arr1 != '\0'){
                    retInt++;
                    arr1++;
                }
            break;             
            }
        }else{
            my_putchar(str[i]);
     retInt++;
        }
 }
 return retInt;
}

//  int main(){
//     int i = my_printf("%d!\n", 1337);
//     printf("%d", i);
//  }