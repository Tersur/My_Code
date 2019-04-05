#include<iostream>
using namespace std;

int main(){
    float val, total=0;
    int type, num, tot1=0, tot2=0, tot3=0, tot4=0;

    cout<<"*** Welcome to ECE114 Cafe ***\n"<<endl;
    cout<<"1. Chicken Burger $3.49\n2. Beef Burger $3.49\n3. Pork Burger $4.99\n4. Fish Burger $4.49\n";
    cout<<"Which burger do you want to order (1, 2 ,3 ,4 or other exit)? ";
    
    while((cin>>type)&&(type>0&&type<5)){
        cout<<"How many? ";
        cin>>num;
        switch(type){
            case 1:
                tot1 +=num;
                val = num * 3.49;
                total += val;
                break;
            case 2:
                tot2 +=num;
                val = num * 3.49;
                total += val;
                break;
            case 3:
                tot3 +=num;
                val = num * 4.99;
                total += val;
                break;
            case 4:
                tot4 +=num;
                val = num * 4.49;
                total += val;
                break;
        }
        cout<<"Which burger do you want to order (1, 2 ,3 ,4 or other exit)? ";
    }
    cout<<endl<<"Your order"<<endl;
    if(tot1>0){
        cout<<tot1<<"*Chicken Burger"<<endl;
    }
    if(tot2>0){
        cout<<tot2<<"*Beef Burger"<<endl;
    }
    if(tot3>0){
        cout<<tot3<<"*Pork Burger"<<endl;
    }
    if(tot4>0){
        cout<<tot4<<"*Fish Burger"<<endl;
    }
    cout<<"Your total is $"<<total<<endl;
    return 0;
}