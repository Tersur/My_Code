/*
 ============================================================================
 Name		 : 
 Title       : Midterm_Q04.c
 ECE 114	 : Spring 2019
 Description : Midterm Question 4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

/*! \fn int main(void)
	\brief main function

	This function flips a coin twice
	for 100 tries and calculates if
	a head shows up twice in each try
	or a tail shows up twice or both
	head and tail show up and then prints
	the number of times each phenomenom
	happens

	\return 0 when successfully completed

	\author Basil Gaji
	\date 03/22/2019
*/


int main(void) {

	int head_tail, head_tail1, sum, countH, countT, countB;

	printf("Flipping the two coins 100 times...\n");

	countH = 0;
	countB = 0;
	countT = 0;
	for(int i =0; i<100;i++){
		srand((unsigned)time(NULL));
		head_tail = rand()%2;
		srand((unsigned)time(NULL));
		head_tail1 = rand()%2;
		sum = head_tail + head_tail1;
		printf("%d", sum);
		//counts for head
		if(sum == 0){
			countH += 1;
		}
		//counts for both
		else if(sum == 1){
			countB += 1;
		}
		//counts for tail
		else if(sum == 2){
			countT += 1;
		}

	}
	printf("Sum: # of times\n");
	printf("Outcome:        # of times\n");
	printf("Both Heads:%*d\n", 6, countH);
	printf("Heads/Tails:%*d\n", 5, countB);
	printf("Both Tails:%*d\n", 6, countT);

	return 0;
}
