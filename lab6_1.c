/*! \file lab6_1.c
    \brief program to print the initials of a name

    \author Basil Gaji
    \date 03/01/2019

*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 300

void initial(char *, int);

/*! \fn int main(void)
    \brief This is the main function

    This function asks a user for their name and
    stores it in an array and then passes it to 
    the function that produces the initials

    \return integer(1 in tis case) when successfully completed

    \author Basil Gaji
    \date 03/01/2019

*/

int main(void){

    char name[MAX], *arr;

    printf("Enter your name: ");
    fgets(name, MAX, stdin);
    arr = name;
    int num = strlen(name);

    initial(arr, num);

    return 1;

}


/*! \fn void initial(char * arr, int num)
    \brief This function reverses the user input

    This function takes the address of the array of
    the user input, reverses and stores the new word in
    a new array

    \param[in] arr the address of the array which stores the user input
    \param[in] num the index of the last element in the user input array
    \return no value

    \author Basil Gaji
    \date 03/01/2019

*/

void initial(char * arr, int num){

    char initials[20];
    int i = 0;

    //produces initials if the first character of the user
    //input is an alphabet
    if (isalpha(*(arr ))){
            initials[i]=*(arr);
            i++;

        for (int x = 1; x<num; x++){
        
            if (isalpha(*(arr + x))&&(*(arr + x-1)==' ')){
                initials[i] = *(arr + x);
                i++;
            }
        }
    }

    //produces initials if the first character of the user
    //input is not an alphabet
    else{
        //reads until it reads an alphabet
        int j = 0;
        while(!isalpha(*(arr + j))){
            j++;
        }
        for (int x = j; x<num; x++){
        
            if (isalpha(*(arr + x))&&(*(arr + x-1)==' ')){
                initials[i] = *(arr + x);
                i++;
            }
        }
    }

    printf("Your initials are: ");
    for(int y = 0; y <(num-1); y++){
       putchar( *(arr + y));
    }
    printf(" ");

    for (int y = 0; y<i; y++){
        putchar(*(initials + y));
    }
    printf("\n");

}


