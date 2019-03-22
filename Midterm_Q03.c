/*
 ============================================================================
 Name		 : 
 Title       : Midterm_Q03.c
 ECE 114	 : Spring 2019
 Description : Midterm Question 3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*! \fn int main(void)
	\brief main function

	This function carries out a survey.
	It asks a student how many hours they
	sleep each day of the week, calculates
	the total and the average and prints
	out daily hours of sleep, weekly total
	and weekly average

	\return 0 when successfully completed

	\author Basil Gaji
	\date 03/22/2019
*/


int main(void) {
	char *dayPtr[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	int num[7];
	int hrs, status, total;
	float avg;

	printf("How many hours of sleep did you get on...\n");
	//asks for the daily hrs of sleep and stores in array of ints
	for (int i = 0; i<7; i++){
		printf("%s night? ", *(dayPtr + i));
		status = scanf("%d", &hrs);
		//input validation
		while(status!= 1 || hrs <1){
			while(getchar()!='\n'){}				//clearing buffer
			printf("Wrong input! Enter a whole number: ");
			status = scanf("%d", &hrs);
		}
		num[i] = hrs;
	}
	total = 0;
	//calculates total hrs in a week
	for (int i = 0; i<7; i++){
		total += num[i];
		printf("%d\n",total );
	}
	avg = total/7.;							        //average hrs of sleep

	printf("\n");
	//prints out the result
	printf("Summary of sleep this week:\n");
	for (int i = 0; i<7; i++){
		printf("%s:    %d hours\n", (dayPtr[i]), num[i]);
	}
	
	printf("------------\n");
	printf("Weekly Total: %d hours\nAverage:      %.2f hours\n", total, avg);

	return 0;
}
