//hw3_2_Gaji_Basil.c by Basil Gaji
#include<stdio.h>
#include<stdbool.h>


//a program to play rock paper scissors with the computer
 int main(void){
	int your_ges;
	

	while(true){					//the program runs continuously unless interrupted	
	printf("Input your gesture (0-Rock 1-Paper 2-Scissors):\n");
	scanf("%d", &your_ges);
	

	switch(your_ges){

		case 0:
			printf("Your gesture: Rock; Computer gesture: Rock.\n");
			printf("Draw!\n");
			break;
		case 1:
			printf("Your gesture: Paper; Computer gesture: Scissors.\n");
			printf("You lose\n");
			break;
		case 2:
			printf("Your gesture: Scissors; Computer gesture: Scissors\n");
			printf("Draw!\n");
			break;

	}
	}
  return 0;
 }
