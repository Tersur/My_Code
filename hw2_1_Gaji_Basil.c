//hw2_1_Gaji_Basil.c by Basil Gaji

#include<stdio.h>
#include<string.h>
#include<math.h>
#define pi 3.14159265358979323846

  int main(void){

    char name[100];
    int len, pow_result;
    float volume;


    printf("Please enter the name: ");
    scanf("%s", name);


    //volume of sphere
    
    len = strlen(name);
    pow_result = pow(len, 3);
    volume = (4./3)*pi*pow_result;

    printf("The sphere's name is %s, the radius is %d, and the volume is %.2f\n", name, len, volume);


 return 0;
  }
