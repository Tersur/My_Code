/* \file Lab5_1.c
	  \Basil Gaji
	  \date 02/24/2019
*/

#include<stdio.h>
#define int_len 100

void sort(double *, int);
void printarray(double *, int);
void swap(double *, double *);

int main(void){

    double numbers[int_len];
    float num;
    int status;

    
    printf("Enter numbers (q to exit)\n");

    int i = 0;
    int j = 1;
    do{

        printf("#%d: ", j++ );
        status = scanf("%f", &num);
        while(getchar()!='\n'){}
        if (status == 1){
            numbers[i] = num;
            i++;
            continue;
        }
        else{
            break;
        }
    
        }while(j < 100);

        if (i == 0){
            printf("No number(s) in the array");
        }


        printf("\n");
        printf("The unsorted array is:\n");
        printarray(numbers, i);
        sort(numbers, i);
        printf("\n");
        printf("The sorted array is:\n");
        printarray(numbers, i);

    return 0;
}

void sort(double *aPtr, int len){
    for (int i = 0; i < len -1; i++){
        for (int j = 0; j<(len-1-i); j++){
            if(aPtr[j]>aPtr[j+1]){
                swap(aPtr + j, aPtr + j + 1);
            }
        }
    }
}

void printarray(double *aPtr, int len){
    for(int i = 0; i < len; i++)
    {
        printf("%.2lf\t", *(aPtr + i));
    }
    printf("\n");
}

void swap(double *a, double *b){
    double val;
    val = *a;
    *a = *b;
    *b = val;
}


    