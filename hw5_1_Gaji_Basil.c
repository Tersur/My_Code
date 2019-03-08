/*! \file hw5_1_Gaji_Basil.c
        \brief Program to carry out an encryption

        This program encrypts plain text using a key

        \author Basil Gaji
        \date 02/28/2019
*/

#include<stdio.h>

void encrypt(char *, int);

/*! \fn int main(void)
    \brief This is the main function

    This function prompts the user for a key that
    will be used to encrypt a plain text

    \return an integer(0 in this case) if successfully completed

    \author Basil Gaji
    \date 02/28/2019

*/
int main(void){

    int index, count;
    char key, *kPtr, key_arr[300];

    puts("*** The Vigenere Cipher ***\n");
    printf("Please enter the key: ");

    index = 0;
    count = 0;                                                                          //keeps track of the number of characters in a key
    key = getchar();                                                                    //reads the first character

    //reads the input until it reaches a new line
    while(key != '\n'){
        //The user is expected to input only alphabets, lower or uppercase
        if (((key>=65) && (key<=90))|| ((key>=97)&&(key<=122))){
            key_arr[index++] = key;
            count++;
            key = getchar();
        }
        //breaks the loop if it reads a non alphabet even if a newline is not read
        else{
            printf("Only alphabets allowed! Error!\n");
            break;
        }
    }

    //produces the encryption if a key was successfully read
    if(key == '\n'){
        printf("\n");
        kPtr = key_arr;
        encrypt(kPtr, count);
    }

    return 0;
}


/*! \fn void encrypt(char *arr, int count)
    \brief This function carries out an encrption

    This function prompts the user for a plain text with any
    combination of characters which are stored in an initial array.
    The characters are encrypted one at a time using the key and then stored
    in another array. While encrypting, alphabets are encrypted and non alphabets
    are not but they are still stored in the new array and can be printed out.

    \param[in] arr the pointer to the array of keys
    \param[in] count the number of characters contained in the key
    \return no value

    \author Basil Gaji
    \date 02/28/2019

*/

void encrypt(char *arr, int count){

    char alpha, ptext[300], ctext[300];
    int count1, index1, index2;
    
    printf("Plain Text: ");
    index1 = 0;                                                                         //keeps tarck of the plain text array index
    count1 = 0;                                                                         //keeps track of the number of characters in the plain text

    alpha = getchar();                                                                  //reads the first character
    //reads all characters until the end of the line and stores in an array
    while(alpha != '\n'){
        ptext[index1++] = alpha;
        count1++;
        alpha = getchar();
    }

    int j = 0;                                                                          //keeps track of the index of the key
    for (int i = 0; i<count1; i++){

        /*
        reinitializes j if all the plain text have
        not been encrypted yet, so that it starts from
        the first character of the key again
        */
        if (j == count){
                j = 0;
        }
        //encrypts upper case alphabets
        if ((ptext[i]>='A') && (ptext[i]<='Z')){
            
            //encypts text if key is upper case
            if((*(arr + j)>='A') && (*(arr + j)<='Z')){
            index2 = ((ptext[i]-'A') + (*(arr + j)-'A'))%26;
            ctext[i] = index2 + 'A';
            j++;
            }

            //encypts text if key is lower case
            else{
                index2 = ((ptext[i]-'A') + (*(arr + j)-'a'))%26;
                ctext[i] = index2 + 'A';
                j++;
            }
           
        }
        //encrypts lower case alphabets
        else if ((ptext[i]>='a')&&(ptext[i]<='z')){

            //encypts text if key is upper case
            if((*(arr + j)>='A') && (*(arr + j)<='Z')){
            index2 = ((ptext[i]-'a') + (*(arr + j)-'A'))%26;
            ctext[i] = index2 + 'a';
            j++;
            }

            //encypts text if key is lower case
            else{
                index2 = ((ptext[i]-'a') + (*(arr + j)-'a'))%26;
                ctext[i] = index2 + 'a';
                j++;
            }
           
        }

        //stores character without encrpting if it is
        //a non-alphabet
        else {
            ctext[i] = ptext[i]; 
        }

    }

    printf("Cipher Text: ");

    //prints encrypted text
    for(int i = 0; i < count1; i++){
        printf("%c", ctext[i]);
    }

    printf("\n");

}