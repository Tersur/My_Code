#include<stdio.h>
#include<string.h>
//#include<stdlib.h>

	
	int main(void){

	char fir_string[100], sec_string[100];
	int len_thir;
	
	printf("Enter the first string: ");
	scanf("%s", fir_string);
	
	printf("Enter the second string: ");
	scanf("%s", sec_string);

	len_thir = strlen(fir_string) + strlen(sec_string);

	char thir_string[len_thir];
	
	strcpy(thir_string, strcat(fir_string, sec_string));
	
	printf("Concatenated string: %s\n", thir_string);
	printf("The length of the concatenated string: %d\n", len_thir);

	return 0;

 }
