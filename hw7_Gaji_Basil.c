/*! \file hw7_Gaji_Basil.c
    \brief A program to collect student information

    This program asks for students information including
    firstname, lastname, GPA and class year. It then stores
    the information of each student in a text file. If data is
    already stored in the text file, it is printed out first
    and the new data is stored at the end of the text file.
    This program makes use of array of structures to store
    different information about different students.

    \author Basil Gaji
    \date 03/14/2019
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 40

/*! \typedef struct STUDENT
    \brief stores information belonging to one student

    The structure is a template that stores information
    about only one student. But an array of structures
    can be created to store information about multiple
    students.

    \author Basil Gaji
    \date 03/14/2019
*/

typedef struct{
        char first_name[MAX];
        char last_name[MAX];
        float gpa;
        int grad_year;
    }STUDENT;

char buffer[5];                                                 //used to convert GPA and class year to strings
int store_data(FILE *fp, STUDENT *sPtr, int count);

/*! \fn int main(int argc, const char * argv[])
    \brief This is the main function

    This function creates an array of structures containing
    information about students. If the text file has data, it
    is printed to the screen. It then asks for the data of
    each student and stores it in the respective structure.
    It then calls the function that stores the data into a text file
    if it is able to open an existing file or able to create a new file.
    The new data is stored at the end of the initial data if there
    was prior data, else, the new data is stored at the beginning
    of the file.

    \param[in] argc number of arguments to commandline
    \param[in] argv pointer to an array of the arguments entered
    \return 1 when successfully completed
    \return 0 if unsuccessful

    \author Basil Gaji
    \date 03/14/2019
*/
int main(int argc, const char * argv[]){
    int number, count, status;
    FILE *fp;                                                   //pointer to textfile
    char ch;
    
    number = argc;
    //checks if the arguments to the commandline are complete
    if(number<3){
        printf("Usage: filename num_Students outputTextFile\n");
        return 0;
    }

    count = atoi(argv[1]);
    //checks if number of students is a whole number or integer
    if (count ==0){
        printf("Usage: filename num_Students outputTextFile\n");
        return 0;
    }
    fp = fopen(argv[2], "a+");
    //checks to make sure the text file can be opened or written to
    if (fp == NULL){
        printf("can't open or write to file\n");
        return 0;
    }

    ch = fgetc(fp);
    //checks to see if the text file exists already
    if (ch>=0 && ch<=255){
        printf("The file %s has the following information already: \n", argv[2]);
        putchar(ch);
    }
    //prints the content of the text file
    while((ch = fgetc(fp))!=EOF){
        putc(ch, stdout);
    }

    STUDENT student[count], *sPtr;                            //creating an array of the struct STUDENT and pointer to the array
    sPtr = student;
    //a loop to ask for student info and store in array of structs
    for(int i = 1; i<=count;i++){
        printf("Enter first name for student %d: ", i);
        fgets((sPtr+i-1)->first_name, MAX, stdin);
        //scanf("%s", (sPtr+i-1)->first_name);
        printf("Enter last name for student %d: ", i);
        fgets((sPtr+i-1)->last_name, MAX, stdin);
        printf("Enter GPA for student %d: ", i);
        status = scanf("%f", &((sPtr+i-1)->gpa));
        //checking for wrong input for GPA
        while(status!=1){
            while(getchar()!='\n'){}                         //clearing buffer
            printf("Wrong input! Enter GPA: ");
            status = scanf("%f",  &((sPtr+i-1)->gpa));
        }
        printf("Enter expected graduation Year for student %d: ", i);
        status = scanf("%d",  &((sPtr+i-1)->grad_year));
        //checking for wrong input for graduation year
        while(status!=1){
            while(getchar()!='\n'){}                        //clearing buffer
            printf("Wrong input! Enter expected graduation year: ");
            status = scanf("%d", &((sPtr+i-1)->grad_year));
        }
        printf("\n");
        while(getchar()!='\n');
    }
    printf("\n");                                        //this is just for neatness in output

    
    store_data(fp, sPtr, count);                          //calling the function store_data

    return 1;
}

/*! \fn int store_data(FILE *fp, STUDENT *sPtr, int count)
    \brief Stores data of students

    This is the function that stores the data into a text file
    if an existing file is opened or a new file is created.
    This function also closes the opened file.

    \param[in] fp pointer to text file
    \param[in] sPtr pointer to array of structures storing students' data
    \param[in] count the number of students whose data is stored
    \return 1 when successfully completed
    \return 0 if unsuccessful

    \author Basil Gaji
    \date 03/14/2019

*/
int store_data(FILE *fp, STUDENT *sPtr, int count){

    //a loop to store student info to text file
    for(int i =1; i<=count; i++){
        fputs("First name: ", fp);
        fputs((sPtr+i-1)->first_name, fp);
        
        fputs("Last name: ", fp);
        fputs((sPtr+i-1)->last_name, fp);
        
        fputs("GPA: ", fp);
        sprintf(buffer, "%.2f", (sPtr+i-1)->gpa);
        fputs(buffer, fp);

        fputc('\n', fp);
       
        fputs("Expected Graduation Year: ", fp);
        sprintf(buffer, "%d", (sPtr+i-1)->grad_year);
        fputs(buffer, fp);

        fputc('\n', fp);
        fputc('\n', fp);       
    }
    
    fclose(fp);

    return 1;
}