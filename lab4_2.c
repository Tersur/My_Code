//lab4_2.c by Basil Gaji

#include<stdio.h>

int find_area(float area);
int find_volume(float vol);
float length;


int main(void){

	int status;

	printf("Welcome to the cube calculator!\n");
	printf("Please enter the length(> 0): ");
	status = scanf("%f", &length);
	while((length < 1)||(status !=1)){
		while (getchar() != '\n'){}
		printf("Wrong input! Enter the length again (>0): ");
		status = scanf("%f", &length);
	}
		find_area(length);
		find_volume(length);

	return 0;
}

// definition of function for surface area
int find_area(float area){
	printf("The surface area is: %lu\n",(long unsigned int)(6*length*length));
	return 0;
}

// definition of function for volume
int find_volume(float vol){
	printf("The volume is: %lu\n", (long unsigned int)(length*length*length));
	return 0;
}
