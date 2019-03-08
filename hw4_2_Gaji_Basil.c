#include<stdio.h>
#include<stdbool.h>

/*! \file hw4_2_Gaji_Basil.c
        \brief Program to order food at McDonald
        \author Basil Gaji
        \date 02/20/2019
*/


/*!	\fn int order_total(int )
	\brief Calculates the order total
    Calculates and returns the total of order after each order
	
	\return An integer when successfully completed.
	\author Basil Gaji
	\date 02/20/2019
*/

int order_total(int );

/*!	\fn float order_cost(int, int, int )
	\brief Calculates the cost of the order
    Calculates the cost of the order

	\return a float when successfully completed.
	\author Basil Gaji
	\date 02/20/2019
*/

float order_cost(int, int, int );


/*! \def McRib 5.49
        \brief Price of one selection of McRib
*/
#define McRib 5.49

/*! \def McChicken 1.99
        \brief Price of one selection McChicken
*/
#define McChicken 1.99

/*! \def McDouble 2.49
        \brief Price of one selection of McDouble
*/
#define McDouble 2.49

/*!	\fn int main(void)
	\brief The main function
	The function asks for inputs and passes the inputs into the functions for calculating the total order and cost of order

	\returns zero when successfully completed.
	\author Basil Gaji
	\date 02/20/2019
*/

int main(){

    int user_input, status, order1, order2, order3;
    char user_input2;

    printf("Welcome to McDonalds we have the McRib ($5.49) and the McChicken($1.99). You already know we have the McDouble($2.49) too.\n");

    //Order for McRibs 
    printf("How many McRibs would you like?: ");
    status = scanf("%d", &user_input);
    while(status != 1){
        while(getchar()!= '\n'){}
        printf("Wrong input! Enter again: ");
        status = scanf("%d", &user_input);
    }
    
    order1 = order_total(user_input);                                       //initial order for McRibs
    do{
    printf("Is this order complete (y/n)? ");
    getchar();
    user_input2 = getchar();
    while(user_input2 != 'y' && user_input2 != 'n'){
        while(getchar()!='\n'){}
        printf("Invalid input. Enter y or n: ");
        user_input2 = getchar();
        
    }
    //enables additional order if the user wants to add to the previous order of the same food
    if(user_input2 == 'y'){break;}
    else {
        while(getchar()!='\n'){}
        printf("How many additional would you like to order? ");
        status = scanf("%d", &user_input);
        while(status != 1){
            while(getchar()!= '\n'){}
            printf("Wrong input! Enter again: ");
            status = scanf("%d", &user_input);
    }
        
        order1 += order_total(user_input);                                  //increments the order by additional amount if the user intends to make another order of the same food
        
    }
    }while(true);

    printf("You ordered a total of %d\n", order1);
    
    printf("\n");
    //Order for McChickens
    printf("How many McChickens would you like?: ");
    status = scanf("%d", &user_input);
    while(status != 1){
        while(getchar()!= '\n'){}
        printf("Wrong input! Enter again: ");
        status = scanf("%d", &user_input);
    }
   
    order2 = order_total(user_input);                                       //initial order for McChicken

    do{
    printf("Is this order complete (y/n)? ");
    getchar();
    user_input2 = getchar();
    while(user_input2 != 'y' && user_input2 != 'n'){
        while(getchar()!='\n'){}
        printf("Invalid input. Enter y or n: ");
        user_input2 = getchar();
    }
    //enables additional order if the user wants to add to the previous order of the same food
    if(user_input2 == 'y'){break;}
    else {
        while(getchar()!='\n'){}
        printf("How many additional would you like to order? ");
        status = scanf("%d", &user_input);
        while(status != 1){
            while(getchar()!= '\n'){}
            printf("Wrong input! Enter again: ");
            status = scanf("%d", &user_input);
    }
        
        order2 += order_total(user_input);                                  //increments the order by additional amount if the user intends to make another order of the same food
    }
    }while(true);
    printf("You ordered a total of %d\n", order2);

    printf("\n");

    //Order for McDoubles
    printf("How many McDoubles would you like?: ");
    status = scanf("%d", &user_input);
    while(status != 1){
        while(getchar()!= '\n'){}
        printf("Wrong input! Enter again: ");
        status = scanf("%d", &user_input);
    }
   
    order3 = order_total(user_input);                                       //initial order for McDoubles

    do{
    printf("Is this order complete (y/n)? ");
    getchar();
    user_input2 = getchar();
    while(user_input2 != 'y' && user_input2 != 'n'){
        while(getchar()!='\n'){}
        printf("Invalid input. Enter y or n: ");
        user_input2 = getchar();
    }
    //enables additional order if the user wants to add to the previous order of the same food
    if(user_input2 == 'y'){break;}
    else {
        while(getchar()!='\n'){}
        printf("How many additional would you like to order? ");
        status = scanf("%d", &user_input);
        while(status != 1){
            while(getchar()!= '\n'){}
            printf("Wrong input! Enter again: ");
            status = scanf("%d", &user_input);
    }
        
        order3 += order_total(user_input);                                  //increments the order by additional amount if the user intends to make another order of the same food
    }
    }while(true);
    printf("You ordered a total of %d\n", order3);

    printf("\n");
    printf("Your total is $%.2f\n", order_cost(order1, order2, order3));

    return 0;
}

int order_total(int order){

    return order;
    
}


float order_cost(int val1, int val2, int val3){
    
    float total_cost;

    return total_cost = (val1*McRib) + (val2*McChicken) + (val3*McDouble);
}
