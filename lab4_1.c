//lab4_1.c by Basil Gaji

#include<stdio.h>
#include <string.h>


int main(void){
	char PIN[7] = "ECE114";
	char pinName_entered[15];
	printf("Please enter your pin #: ");
	scanf("%s", pinName_entered);
	while (strcmp(PIN, pinName_entered) != 0){
		while (getchar()!= '\n'){}
		printf("Incorrect pin. Please enter again: ");
		scanf("%s", pinName_entered);
	}
	printf("Congrats!\n");
	return 0;
}
