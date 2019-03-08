/*! \file lab6_2.c
    \brief program to reverse a word

    \author Basil Gaji
    \date 03/01/2019

*/

#include<stdio.h>
#include<string.h>

#define MAX 100

char * strev(char *, int);

/*! \fn int main(void)
    \brief This is the main function

    This function asks a user for a word and calls
    another function which reverses the word,
    stores it in an array and returns the address
    of the array

    \return integer(1 in tis case) when successfully completed

    \author Basil Gaji
    \date 03/01/2019

*/
int main(void){

    char name[MAX];

    printf("Please enter a word: ");
    fgets(name, MAX, stdin);

    char *arr = name;
    int num = strlen(name)-1;

    printf("Your word backwards is: ");

    for (int i = 0; i<num; i++){
        putchar(*(strev(arr, num) + i));
    }
    printf("\n");

    return 1;

}


/*! \fn char * strev(char *arr, int num)
    \brief This function reverses the user input

    This function takes the address of the array of
    the user input, reverses and stores the new word in
    a new array

    \param[in] arr the address of the array which stores the user input
    \param[in] num the index of the last element in the user input array
    \return pointer to the array of the reversed word when successfully completed

    \author Basil Gaji
    \date 03/01/2019

*/
char * strev(char * arr, int num){

    char name_rev[100];
    int index = num;
    for (int i = 0; i < num; i++){
        name_rev[i] = *(arr + index -1);
        index--;
    }

    char *arr1 = name_rev;
    return arr1;
}