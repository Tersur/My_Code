/*! \file hw5_2_Gaji_Basil.c
        \brief calculating scalar and cross product

        This program calculates the scalar and cross product
        of two 3 dimentional vectors.
        
        \author Basil Gaji
        \date 02/28/2019

*/

#include<stdio.h>


void cross_product(int *, int *);
void scalar_product(int *, int *);

/*! \fn int main(void)
        \brief This is the main function

        This function prompts the user two times for 3 values
        and puts each 3 values into separate arrays. It then calls the
        functions that calculate the scalar or cross product, depending
        on whether the user wants a scalar or cross product
        
        \return an integer(0 in this case) when successfully completed

        \author Basil Gaji
        \date 02/28/2019


*/
int main(void){

    int type_prod, val1, val2, val3, status;
    int *firstPtr, *secondPtr;
   // int first_arr[5];
   // int second_arr[5];

    printf("Welcome! Please enter 1 for scalar ");
    puts("product and 2 for vector product:");
    scanf("%d", &type_prod);

    //the user has to input either 1 or 2
    while(type_prod!=1 && type_prod!=2){
        while(getchar()!='\n'){}                                                        //clearing the buffer                           
        printf("That doesn't seem right! Please enter 1 for ");
        printf("scalar product and 2 for vector product: ");
        scanf("%d", &type_prod);
    }

    printf("\n");

    printf("Enter the first vector with components in the order <i, j, k>: ");
    status = scanf("%d%d%d", &val1, &val2, &val3);
    
    //the user has to input 3 integers
    while (status != 3){
        while(getchar()!= '\n'){}                                                       //clearing the buffer
        printf("Sorry, you have to enter 3 numbers in a row in the order <i, j, k>: ");
        status = scanf("%d%d%d", &val1, &val2, &val3);
    }
    int first_arr[5] = {val1, val2, val3};                                              //storing the first 3 integers into an array
    firstPtr = first_arr;                                                               //creating a pointer to the array

    printf("Enter the second vector with components in the order <i, j, k>: ");
    status = scanf("%d%d%d", &val1, &val2, &val3);

    //the user has to input 3 integers
    while (status != 3){
        while(getchar()!= '\n'){}                                                       //clearing the buffer
        printf("Sorry, you have to enter 3 numbers in a row in the order <i, j, k>: ");
        status = scanf("%d%d%d", &val1, &val2, &val3);
    }
    int second_arr[5] = {val1, val2, val3};                                             //storing the second 3 integers into an array
    secondPtr = second_arr;                                                             //creating a pointer to the array
    
    //calculates the scalar product if the user entered 1
    if(type_prod == 1){
        printf("\n");
        scalar_product(firstPtr, secondPtr);
    }

    //calculates the cross product if the user entered 2
    else{
        printf("\n");
        cross_product(firstPtr, secondPtr);
    }

    return 0;
}

/*! \fn void scalar_product(int *arr1, int *arr2)
        \brief Calculates the scalar product

        This function calculates the scalar product by using
        the values from the two arrays

        \param[in] *arr1 the pointer to the first array
        \param[in] *arr2 the pointer to the second array
        \return no value

        \author Basil Gaji
        \date 02/28/2019
*/
void scalar_product(int *arr1, int *arr2){
    int result = *(arr1) * *(arr2) + *(arr1 + 1) * *(arr2 + 1) + *(arr1 + 2) * *(arr2 + 2);
    printf("a . b = %d\n", result);
}


/*! \fn void cross_product(int *arr1, int *arr2)
        \brief Calculates the cross product

        This function calculates the cross product by using
        the values from the two arrays

        \param[in] *arr1 the pointer to the first array
        \param[in] *arr2 the pointer to the second array
        \return no value

        \author Basil Gaji
        \date 02/28/2019
*/
void cross_product(int *arr1, int *arr2){
    int result1 = (*(arr1 + 1) * *(arr2 + 2) -  *(arr1 + 2) * *(arr2 + 1));
    int result2 = -((*(arr1) * *(arr2 + 2) -  *(arr1 + 2) * *(arr2)));
    int result3 = (*(arr1) * *(arr2 + 1) -  *(arr1 + 1) * *(arr2));
    printf("a x b = %di + %dj + %dk\n", result1, result2, result3);

}