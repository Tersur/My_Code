#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

/*! \file hw4_1_Gaji_Basil.c
        \brief Program to play toss the coin
        \author Basil Gaji
        \date 02/20/2019
*/

/*!	\fn bool toss(int)
	\brief Controls the tossing of the coin
	This function tosses the coin, calculates the side after tossing and checks if the side is the same as what a user inputed

	\returns a boolean when successfully completed.
	\author Basil Gaji
	\date 02/20/2019
*/

bool toss(int);

/*!	\fn int main(void)
	\brief The main function
	Controls the rounds to play, takes input, and determines if the user wins or losses by passing the inputs into the toss() function and checking for true or false

	\returns zero when successfully completed.
	\author Basil Gaji
	\date 02/20/2019
*/

int main(void){
    
    int status, user_input;                                               //status keeps track valid int input and user_input takes in the users choice
    bool toss_result, toss_result1, toss_result2;                         //all three keep track of whether a valid user_input is the same with the result of the tossed coin

    printf("Welcome to Heads or tails. Best 2 out of 3\n");
    printf("Heads = 1, and tails = 2\n");

    //Round1
    printf("Round 1:\n");
    printf("Heads or Tails? ");
    status = scanf("%d", &user_input);

    //makes sure a user input is valid
    while (status != 1 || user_input<1 || user_input>2){
        while(getchar() != '\n'){}
        printf("Wrong input! Enter again: ");
        status = scanf("%d", &user_input);
    }
    toss_result = toss(user_input);                                       //Prints the side after toss and returns true or false

    //Round2
    printf("Round 2:\n");
    printf("Heads or Tails? ");
    status = scanf("%d", &user_input);

    //makes sure a user input is valid
    while ((status != 1)||(user_input<1 || user_input>2)){
        while(getchar() != '\n'){}
        printf("Wrong input! Enter again: ");
        status = scanf("%d", &user_input);
    }
    toss_result1 = toss(user_input);                                      //Prints the side after toss and returns true or false

    if (toss_result&&toss_result1){                                       //checks if the player wins the first 2 times
        printf("Congratulations! You win!\n");
    }
    else if((!toss_result)&&(!toss_result1)){                             //checks if the player loses the first 2 times
        printf("You lose\n");
    }
    
    
    else{                                                                 //true if neither the player wins nor loses the first 2 times
        printf("Round 3:\n");
        printf("Heads or Tails? ");
        status = scanf("%d", &user_input);

        //makes sure a user input is valid
        while ((status != 1)||(user_input<1 || user_input>2)){
            while(getchar() != '\n'){}
            printf("Wrong input! Enter again: ");
            status = scanf("%d", &user_input);
        }  
        toss_result2 = toss(user_input);                                  //Prints the side after toss and returns true or false
        if((toss_result&&toss_result1)||(toss_result&&toss_result2)||(toss_result1&&toss_result2)){     //returns true if 2 out of the 3 tosses are wins or true
            printf("Congratulations! You win!\n");
        }
        else{                                                             //returns true if atleast 2 out of the 3 tosses are loses or false
            printf("You lose\n");
        }
    }


 return 0;   
}


bool toss(int num){

    int ranNum;
    srand(time(NULL));
    ranNum = (rand()%2) + 1;                                              //generates random numbers from 1 to 2

    switch(ranNum){

        case 1:
        printf("Tossing the coin...It's Heads!\n");
        break;

        case 2:
        printf("Tossing the coin...It's Tails!\n");
        break;

    }

    if (num == ranNum){                                                   //checking for equality with user_input and result of tossed coin
        return true;
    }
    else{
        return false;
    }


}
