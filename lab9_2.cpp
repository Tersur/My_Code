//lab9_2.cpp by Basil Gaji
#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<string>word_array;
int main(){

    int size;
    string word;
    do{
        cout<<"Please enter a string (q to exit):"<<endl;
        getline(cin,word);
        word_array.push_back(word);
    }while (word!="q");

    word_array.pop_back();
   
    size = int(word_array.size());
    for(int i = (size-1); i>=0;i--){
        cout<<word_array[i]<<" ";
    }

    return 1;
}
