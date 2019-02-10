#include<stdio.h>

int main(void){

float red, green, blue, total, probr, probg, probb;
printf("Please enter number of red balls:\n");
scanf("%f", &red);
printf("Please enter the number of green balls:\n");
scanf("%f",&green);
printf("Please enter the number of blue balls:\n");
scanf("%f", &blue);
 total = red+green+blue;
if(total!=0){

probr = (red/total)*100;
probg = (green/total)*100;
probb = (blue/total)*100;

}
printf("Probability of drawing a red ball at the first attempt:%f\n", probr);
printf("Probability of drawing a green ball at the first attempt:%f\n", probg);
printf("Probability of drawing a blue ball at the first attempt: %f\n", probb);
 return 0;
}
