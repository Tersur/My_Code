#include<stdio.h>
#include<string.h>

	int main(void){
	
	int num;

   printf("************\n");
   printf("Selection\n");
   printf("1.Chocolate\n");
   printf("2.cookie\n");
   printf("3.chip\n");
   printf("4.coke\n");
   printf("5.tea\n");
   printf("************\n");
  
   
   printf("Input #1~5 to check item price: ");
  
  scanf("%d",&num);
   
  switch(num){ 
	  
	case 1:
		  printf("You select chocolate\n");
		  printf("Unit Price: $4.5\n");
		  break;
	case 2:
		  printf("You select cookie\n");
		  printf("Unit Price: $2.5\n");
		  break;
	case 3:
		  printf("You select chip\n");
		  printf("Unit Price: $2\n");
		  break;
	case 4:
		  printf("You select coke\n");
		  printf("Unit Price: $1.5\n");
		  break;
	case 5:
		  printf("You select tea\n");
		  printf("Unit Price: $1.5\n");
		  break;
        default:
		  printf("\n");
		  printf("Invalid Input\n");
		 
		}
  return 0;
	}
