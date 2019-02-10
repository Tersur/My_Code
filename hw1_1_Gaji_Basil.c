//hw1_1_Gaji_Basil.c by Basil Gaji

#include<stdio.h>


int main(void){

  int Vin, Rt;	
  float Vout, R1, R2;
   
 	printf("Welcome to the voltage divider calculator.\n");
 	printf("Please enter:\n");
 	printf("Input voltage(Vin): ");
 	scanf("%d", &Vin);
 	printf("Output Voltage(Vout): ");
 	scanf("%f", &Vout);
 	printf("Total Resistance in ohm (Rt): ");
 	scanf("%d", &Rt);

  R2 = Rt*(Vout/Vin);
  R1 = Rt - R2;

 	printf("When Vin=%d, Vout=%1.2f, and Rt=%d\n", Vin, Vout, Rt);
 	printf("R1 = %1.2f\n", R1);
 	printf("R2 = %1.2f\n", R2);

 return 0;


}
