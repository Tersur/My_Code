//hw3_1_Gaji_Basil.c by Basil Gaji


#include<stdio.h>
#define RATE_m .15
#define RATE_l .20


//a program to make an order at McDonald's
int main(void){

	float b_mac = 6.99, g_a_chick = 7.49, mcnug = 6.99, chic_crisp = 7.79, b_s_art = 7.89, m_swiss = 8.69, size1, item_price, price, total;
	int selected_item, amount, status;
	char size, repeat;

	//printing all selections	
	printf("******* Selections *******\n");
	printf("1.Big Mac\n");
	printf("2.Grilled Asian Chicken\n");
	printf("3.McNuggets\n");
	printf("4.Chicken-Crispy\n");
	printf("5.Bacon Smokehouse Artisan\n");
	printf("6.Mushroom Swiss\n");
	printf("***************************\n");

	total = 0;    																					//initializing the variable for storing the total price of selections after each round of selection
	
	printf("Select your order from #1~6: ");
	selected_item = getchar();	  
											
	do{

		while (((selected_item >54)||(selected_item<49))){				//making sure the slected item ranges from 1 to 6 by comparing ASCII codes
			while (getchar()!='\n'){}																//clearing the buffer
			printf("Please input a valid order number: ");
	 		selected_item = getchar();
		
	  	}  
	

	//The different slections and their prices
		switch(selected_item){
			case 1:case 49:																					//the second case makes use of the ASCII codes
				printf("You select: Big Mac, unit price: $6.99\n");
				item_price = b_mac;																		//the price to be used for calculating the selection
				break;
			case 2:case 50:
				printf("You select: Grilled Asian Chicken, unit price: $7.49\n");
				item_price = g_a_chick;
				break;
			case 3:case 51:
				printf("You select: McNuggets, unit price: $6.99\n");
				item_price = mcnug;
				break;
			case 4:case 52:
				printf("You select: Chicken-Crispy, unit price: $7.79\n");
				item_price = chic_crisp;
				break;
			case 5:case 53:
				printf("You select: Bacon Smokehouse Artisan, unit price: $7.89\n");
				item_price = b_s_art;
				break;
			case 6: case 54:
				printf("You select: Mushroom Swiss, unit price: $8.69\n");
				item_price = m_swiss;
				break;
			}

		//entering the amount of selected items wanted
		printf("Input the amount: ");

	  status = scanf("%d", &amount);					
	  while (status != 1){																		//makes sure the an integer is read
	    while(getchar() != '\n'){}
		  printf("Please input a valid order amount: ");
		  status = scanf("%d", &amount);
		
			}
	    
		//entering the size of the selected items
		printf("Input lower case s/m/l to select size: ");
		getchar();
	  size = getchar();  
	  while(!((size == 's') || (size =='m') || (size =='l'))){
			while(getchar()!='\n'){}
			printf("Please input a valid size(s,m,l): ");
			size = getchar();
			}

		//the different sizes of selected items
	  switch(size){
	    case 's':
				printf("You select small.\n");
				size1 = 1;																					//rate applied to the size selected
				break;
	    case 'm':
				printf("You select medium.\n");
				size1 = 1 + RATE_m;
				break;
	    case 'l':
				printf("You select large.\n");
				size1 = 1 + RATE_l;
				break;
				}
				
	  price = amount*item_price*size1;											//calculation of price selected items
	  total += price;																				//increments the price after every order

	  printf("Press c to continue or any other key to checkout. ");
	 	getchar();	
	  scanf("%c", &repeat);
	  while(getchar()!= '\n'){}
	  if (repeat == 'c'){
			printf("Please select another item. ");
			selected_item = getchar();
			
	  }

  }while (repeat == 'c');

	printf("Your total is $%.2f. Enjoy your meal!\n", total);



	return 0;
 }
