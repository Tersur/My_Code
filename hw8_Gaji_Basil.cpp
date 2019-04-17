/*! \file hw8_Gaji_Basil.cpp
    \brief program to create or retrieve student record

    \author Basil Gaji
    \date 03/31/2019
*/

#include<iostream>
#include<string.h>
using namespace std;

/*! \typedef struct STUDENT
    \brief template for storing student record

    \author Basil Gaji
    \date 03/31/2019
*/
typedef struct{
    int student_code;
    char name[50];
    int grade;
}STUDENT;

STUDENT student[50];                                            //creates an array of 50 structs of the type STUDENT
int count = 0;                                                  //keeps track of the number of students whose records are stored


int create_records(STUDENT *student);
int search_records(STUDENT *student);

/*! \fn int main()
    \brief This is the main function

    It displays the options available and
    calls a certain function or exits the
    program based on the choice of the user

    \return 1 when successfully completed

    \author Basil Gaji
    \date 03/31/2019
*/
int main(){
    int choice;                                                 //stores the user's choice of creating or searching record or exiting
    
    //this loop ensures that the program continues to run until the user enters 3 to exit
    do{
        cout<<"1. Create records\n2. Search records\n3. exit\n"<<endl;
        cout<<"Select an option: ";
        //input validation
        while(!(cin>>choice) || (choice<1 || choice>3)){
            //checking for fail bit and clears if there is a fail bit
            if(cin.fail()){
                cin.clear();
                while(cin.get()!='\n'){}
            }
            cout<<"Enter 1, 2, or 3: ";
            }
        //create record if choice is to create record
        if(choice==1){
            create_records(student);
        }
        //search record if choice is to search record
        else if (choice==2){
            int search_status;                                  //checks if student record was searched without creating record
            char ch_y_or_n;                                            //for taking in the choice of 'y' or 'n'
            search_status = search_records(student);
            //if record is not found, ask user if they want to create record
            if(search_status==0){
                cout<<"Do you want to add student data?(y/n): ";
                //input validation
                while(!(cin>>ch_y_or_n) || (ch_y_or_n!='y' && ch_y_or_n!='n')){
                    if(cin.fail()){
                    cin.clear();
                    }
                    while(cin.get()!='\n'){}
                    cout<<"Enter y or n: ";
                }
                //creates record if user chooses 'y'. If not the initial options are displayed
                if(ch_y_or_n=='y'){create_records(student);}
            }

        }
        //exit the program if user chooses exit
        else if(choice==3){
            return 1;
        }

    }while(1);                                                  //continues to loop until user exits

    return 1;
}


/*! \fn int create_records(STUDENT *student)
    \brief This function creates student record

    It asks for student info and stores the info of
    each student in an array of structs

    \param[in] student array of struct of the type STUDENT
    \return 1 when successfully completed
    
    \author Basil Gaji
    \date 03/31/2019
*/
int create_records(STUDENT *student){
    int num = 0, code, code_n, Grade;
    char Name[50];
    //asks for the number of students whose records will be stored
    cout<<"Number of Students to enter: ";
    cin>>num;
    cout<<"Enter "<<num<<" records"<<endl;

    int i = count;                                              //this initialization makes sure that the next student data is stored in area after the last was stored. This is to avoid overwriting
    int sum = num + count;                                      //the sum of the number of students to add and the number of students stored already. This ensures that there is no overwriting and that the loop runs to store data
    //this loop asks for and stores records in an array of structs
    while (i<sum){
        char ch_replace = 0;
        cout<<"Student code: ";
        cin>>code;
        
        //this loop checks to see if a student code is repeated
        for(int j =0;j<50;j++){
            //checks if user entered code already exists
            if(student[j].student_code == code){
                cout<<"Student code #"<<student[j].student_code<<" already exist, would you like to overwrite?(y/n): ";
                cin>>ch_replace;
                //if user entered code already exists, asks the user if they wants to overwrite
                if(ch_replace == 'y'){
                    student[j].student_code = code;
                    cout<<"Name: ";
                    cin>>Name;
                    strcpy(student[j].name, Name);

                    cout<<"Grade: ";
                    cin>>Grade;
                    student[j].grade = Grade;
                    
                }
                //if the user does not want to overwrite
                else{
                    
                    cout<<"Student code: ";
                    cin>>code_n;
                }
            }
            //breaks the loop if an existing student code is found
            if(student[j].student_code == code){break;}
        }
        //continues to the next student data or breaks out of loop. This is to ensure that data is not overwritten unintentionally
        if(ch_replace == 'y'){
            i++;
            count = i;
            continue;
        }
        //stores data of student if an existing student code was found but the user decided to not overwrite it
        if(ch_replace == 'n'){
            student[i].student_code = code_n;
        }
        else{
            student[i].student_code = code;
        }
        
        //stores student data if no existing student was found
        cout<<"Name: ";
        cin>>Name;
        strcpy(student[i].name, Name);

        cout<<"Grade: ";
        cin>>Grade;
        student[i].grade = Grade;
        
        cout<<endl;
        i++;

        count = i;                                              //updates the variable that keeps track of the number of students
    }
    
    return 1;
}


/*! \fn int search_records(STUDENT *student)
    \brief This function retrieves student data

    It searches a student data using the student's
    code and prints the student's info

    \param[in] student array of struct of the type STUDENT
    \return 1 when successfully completed
    \return 0 when unsuccessfully completed
    
    \author Basil Gaji
    \date 03/31/2019
*/
int search_records(STUDENT *student){
    cout<<endl;
    //checks if user searches an empty record
    if(student[0].name[0]==0){
        cout<<"There is no student data"<<endl;
        return 0;
    }

    int code;                                                   //stores student code to be searched

    cout<<"Enter the student code to be searched: ";
    cin>>code;
    cout<<endl;
    int i;
    //searches for code
    for (i = 0; i<50; i++){
        if(student[i].student_code == code){
            break;
        }
    }

    int j = i;
    //if record does not exist, asks user if they want to create record
    if(student[j--].name[0] == 0){
        cout<<"This student record does not exist"<<endl;
        return 0;
    }

    //prints student record
    cout<<"Student code: "<<student[i].student_code<<endl;
    cout<<"Name: "<<student[i].name<<endl;
    cout<<"Grade: "<<student[i].grade<<endl;
    cout<<endl;

    return 1;

}