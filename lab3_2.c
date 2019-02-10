#include<stdio.h>
#include<string.h>
#include<stdlib.h>

     int main(void){

        char ch, ch1;
        int num,diff1, space, diff;

   printf("Enter an uppercase letter: ");


   ch = getchar();
   ch1 = 'A';
   diff = ch-ch1;
   diff1= diff;

	   for (num = 'A'; num<= ch; num++){	

	
	
	for(space ='A'; space<('A'+diff); space++){
		putchar(' ');
	}
	for(ch1='A'; ch1<= ch-diff; ch1++){
		putchar(ch1);
	}
	for(ch1 = ch-diff-1; ch1>='A'; ch1--){
		putchar(ch1);
	}
	printf("\n");
	diff--;


	}
   
	

	  for (num = 'B'; num<= ch; num++){



	for(space ='B'; space<=num; space++){
		putchar(' ');
	}
	for(ch1='A'; ch1<= 'A'+diff1-1; ch1++){
		putchar(ch1);
	}
	for(ch1 = 'A'+diff1-2; ch1>='A'; ch1--){
		putchar(ch1);
	}
	printf("\n");
	diff1--;



	}
  return 0;

     }


