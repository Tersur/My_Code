#include<stdio.h>
#include<string.h>
void prog(void);


 int main(void){

	char name1[100];
        char name2[100];
 	int result, rem, result1,len1, len2, rem1;

	printf("Please enter the first name: ");
	scanf("%s", name1);
	printf("Please enter the second name: ");
	scanf("%s", name2);

	len1 = strlen(name1);
	len2 = strlen(name2);
	result = len1/len2;
	rem = len1%len2;
	result1 = len2/len1;
	rem1 = len2%len1;


	printf("The length of name1 is %d, and the length of name2 is %d\n", len1, len2);
	printf("The result of len(name1)/len(name2) equals to %d, and remainder is %d\n", result, rem);
	printf("The result of len(name2)/len(name1) equals to %d, and remainder is %d\n", result1, rem1);
	/*prog(); prog();
	prog();*/
	//printf("What?\nNo/nfish?\n");

	//printf("The length of the array is %ld\n", sizeof(name1));
return 0;
 }
/*
	void prog(void){
	printf("Smile!\n");
	
	}
*/ 
