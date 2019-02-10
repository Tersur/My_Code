//hw2_2_Gaji_Basil.c by Basil Gaji
#include<stdio.h>
#include<math.h>
#include<string.h>
#define DISCOUNT 0.1


  int main(void){

	int start_hr, start_min, end_hr, end_min, diff_time;
	float ratePmin, undis_price, dis_price;


      printf("Welcome to ECE114 parking lot!\n");
      printf("Please Enter the start time: ");
      scanf("%d%d", &start_hr, &start_min);
      printf("Please Enter the end time: ");
      scanf("%d%d",&end_hr, &end_min);
      printf("Please Enter the rate per minute(%c): ", '$');
      scanf("%f",&ratePmin);

	diff_time = (60*end_hr + end_min) - (60*start_hr + start_min); //difference of end and start times in minutes

	undis_price = diff_time * ratePmin;         //applying the rate per minute to obtain total price
	
	dis_price = undis_price * (1 - DISCOUNT);  // applying 10% off to calculate the final price


      printf("Start time: %d:%d, End time: %d:%d\n", start_hr, start_min, end_hr, end_min);
      printf("Total time spent parking: %d minutes\n", diff_time);
      printf("The total price: %c%.2f\n", '$', undis_price);
      printf("The final price after discount: %c%.2f\n", '$', dis_price);




 return 0;
  }
