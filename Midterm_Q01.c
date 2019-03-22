/*
 ============================================================================
 Name		 : 
 Title       : Midterm_Q01.c
 ECE 114	 : Spring 2019
 Description : Midterm Question 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/*! \fn int main(void)
	\brief main function

	This function calculates a series
	of numbers n times, where n is the
	an input from a user specifying the
	length of the series

	\return 0 when successfully completed

	\author Basil Gaji
	\date 03/22/2019
*/

int main(void) {
	long int sum, num;
	int count, status;
	
	printf("Number of terms in the series (Enter a positive integer): ");
	status = scanf("%d", &count);
	//input validation
	while(status!=1 || count<1){
		while(getchar()!='\n'){}							//clearing buffer
		printf("Wrong input! Enter again: ");
		status = scanf("%d", &count);
	}
	sum = 1;												//initializing sum
	num = 1;												//initializing num
	printf("%ld",num);
	//printing result
	for(int i=1; i<count; i++){
		num=(num + pow(10, i));
		sum += num;
		printf("+ %ld",num);
	}
	printf("\n");
	printf("The sum is: %ld", sum);
	return 0;
}
