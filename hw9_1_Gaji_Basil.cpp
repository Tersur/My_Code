/*! \file hw9_1_Gaji_Basil.cpp
    \brief A program to carry out a bank transaction

    \author Basil Gaji
    \date 04/09/2019
*/
#include<iostream>
#include<string>
#include<vector>
#include <iomanip>

using namespace std;
/*! \struct ACCOUNT
    \brief structure template to store record of banker

    \author Basil Gaji
    \date 04/09/2019
*/
struct ACCOUNT{
    std::string banker_Name;
    double banker_Balance;
};

vector<ACCOUNT>customer;                                            //initialization of vector of ACCOUNT   
char choice = 0;                                                    //keeps track of the user's choice
double deposit_total = 0, withdraw_total = 0;                       //keeps track of total deposit and withdrawal made

void recordTransaction(vector<ACCOUNT> &);
void listTransctions(vector<ACCOUNT> &);
/*! \fn int main()
    \brief The main function
    
    \param[in] void
    \return 0 when successfully completed

    \author Basil Gaji
    \date 04/09/2019
*/
int main(){
    double amount;
    std::string name;

    cout<<"Enter the name of the account holder: ";
    getline(cin, name);
    cout<<"Enter the starting balance: ";
    cin>>amount;
    cin.get();

    customer.push_back({name, amount});
    //loop continues until the user choice is q
    do{
        cout<<"\nWelcome. What would you like to do?\n"<<"1. Deposit money into account.\n"<<"2. Withdraw money from account.\n"<<"q. Quit"<<endl;
        cout<<"Choice: ";
        //input validation
        if(!(cin>>choice)||(choice!='q' && choice!='1' && choice!='2')){
            //checking for and clearing fail bit
            if(cin.fail()){
                cin.clear();
            }
            while(cin.get()!='\n'){}
        }
        
        //if the choice is q
        if(choice=='q'){
            std::cout << std::setprecision(2) << std::fixed;
            listTransctions(customer);
        }
        //if the choice is 1 or 2
        else{
            //if the choice is 1
            recordTransaction(customer);
            //if the choice is 2
            listTransctions(customer);
        }
        
    }while(choice!='q');

    return 0;
    
}

/*! \void recordTransaction(vector<ACCOUNT> &a)
    \brief The function records transactions such as
    deposit and withdrawl
    
    \param[in] a a vector of ACCOUNT
    
    \author Basil Gaji
    \date 04/09/2019
*/
void recordTransaction(vector<ACCOUNT> &a){
    double amount = 0;                                                      //each time the function is called, amount is declared to take in the value of deposit or withdrawal in a certain function call
    switch(choice){
        //
        case '1':
            cout<<"Enter deposit amount (>0): ";

            //input validation
            while(!(cin>>amount)||(amount<=0)){
            //checking for and clearing fail bit
            if(cin.fail()){
                cin.clear();
            }
            while(cin.get()!='\n'){}
            cout<<"Enter amount (>0): ";
            }

            a.at(0).banker_Balance +=amount;
            deposit_total += amount;
            break;

        case '2':
            cout<<"Enter withdrawal amount: ";
            cin>>amount;
            a.at(0).banker_Balance -=amount;
            withdraw_total += amount;
            break;
    }
    
}

/*! \void listTransctions(vector<ACCOUNT> &a)
    \brief The function prints out the balance in an account
    
    \param[in] a a vector of ACCOUNT
    
    \author Basil Gaji
    \date 04/09/2019
*/
void listTransctions(vector<ACCOUNT> &a){
    switch(choice){
        //prints out user name and balance if input choice is 1 or 2
        case '1': case '2':
            cout<<"Account: "<<a.at(0).banker_Name<<"; "<<"Balance: "<<a.at(0).banker_Balance<<endl;
            break;
        //prints out the total transaction carried out if input choice is q
        case 'q':
            cout<<"Deposit "<<deposit_total<<"\nWithdrawal "<<withdraw_total<<"\nThank you!!!"<<endl;
            break;
    }
}
