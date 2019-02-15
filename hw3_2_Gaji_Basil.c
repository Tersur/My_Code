//hw3_2_Gaji_Basil.c by Basil Gaji


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


//a program to play rock paper scissors with the computer
 int main(void){
	int your_ges, comp_ges;
	

	while(true){					//the program runs continuously unless interrupted	
	printf("Input your gesture (0-Rock 1-Paper 2-Scissors):\n");

	scanf("%d", &your_ges);

	//printing your gesture
	switch(your_ges){

		case 0:
			printf("Your gesture: Rock; ");
			break;
		case 1:
			printf("Your gesture: Paper; ");
			break;
		case 2:
			printf("Your gesture: Scissors; ");
			break;

	}

	comp_ges = rand()%3;					//generating random numbers from 0 to 2
	
	//printing the computers gesture
	switch(comp_ges){

		case 0:
			printf("Computer gesture: Rock.\n");
			break;
		case 1:
			printf("Computer gesture: Paper.\n");
			break;
		case 2:
			printf("Computer gesture: Scissors.\n");
			break;
	}

	//printing whether you win or lose
	if (your_ges == comp_ges){
		printf("Draw!\n");
		}
	else{
		printf("You lose!\n");
	}
	}
  return 0;
 }
