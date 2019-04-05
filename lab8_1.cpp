#include<iostream>
using namespace std;

int main(){

    char name[80];
    int row, column;

    cout<<"Please enter the matrix name: ";
    cin>>name;
    cout<<"Please enter the number of rows: ";
    cin>>row;
    while(row<1){
        cout<<"Please enter a number greater than zero";
        cin>>row;
    }
    cout<<"Please enter the number of columns: ";
    cin>>column;
    while(column<1){
        cout<<"Please enter a number greater than zero";
        cin>>column;
    }
    cout<<endl;
    cout<<name<<endl;
    for (int i = 0; i<row; i++){
        for(int j = 0; j<column;j++){
            cout<<'*';
        }
        cout<<endl;
    }
    return 1;
}