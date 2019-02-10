#include<stdio.h>

int main(void){

int speed, dist, hrs, min;
float mPm;

printf("Enter the average speed in mph:");
scanf("%d", &speed);
printf("Enter the total distance travelled in miles:");
scanf("%d", &dist);

if(speed!=0){
hrs =(dist/speed);
mPm = dist%speed;
min =(mPm*60)/speed;

printf("Total duration of your trip is %d hours %d minutes.\n", hrs, min);
}


else{
printf("Speed cannot be zero if there is motion\n");
	
	return 0;
}
}
