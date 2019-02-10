//hw1_2_Gaji_Basil.c by Basil Gaji

#include<stdio.h>

#define SALES_TAX  0.08 

int main(void){

 int cof, esp, lat, cap, moc;
 float untaxed_cost, taxed_cost;

  printf("|| ITEM \t || PRICE ||\n");
  printf("|| Coffee\t || %c1.99 ||\n",'$');
  printf("|| Espresso\t || %c1.49 ||\n", '$');
  printf("|| Latte \t || %c2.49 ||\n", '$');
  printf("|| Cappuccino \t || %c2.49 ||\n", '$');
  printf("|| Mocha\t || %c2.89 ||\n", '$');
  
  printf("Number of coffees: ");
  scanf("%d", &cof);
  printf("Number of Espresso: ");
  scanf("%d", &esp);
  printf("Number of lattes: ");
  scanf("%d", &lat);
  printf("Number of Cappuccinos: ");
  scanf("%d", &cap);
  printf("Number of mochas: ");
  scanf("%d",&moc);

	untaxed_cost = cof*1.99 + esp*1.49 + lat*2.49 + cap*2.49 + moc*2.89;
	taxed_cost = untaxed_cost*(1+SALES_TAX);
	
  printf("The total cost for the order is %c%1.2f\n", '$', taxed_cost);


 return 0;

}

