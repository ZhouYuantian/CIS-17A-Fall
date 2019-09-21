#include<iostream>
using namespace std;

int main()
{
    int startNum;
    float dailyInc;
    int days;
    do
    {
    cout<<"input the starting number"<<endl;
    cin>>startNum;
    if(startNum<2)
    cout << "startNum can not less than 2" << endl;
    }while(startNum<2);
    do{
       cout << "input the daily increase(as pesemtage)" << endl; 
       cin >> dailyInc;;
       if(dailyInc<0)
       cout << "daily increase cannot less than0" << endl;
    }while(dailyInc<0);
    do{
        cout << "input the multiply number of dsys" << endl;
        cin >> days;
        if(days<1)
        cout << "days number cannot less than 1" << endl;
        
    }while(days<1);
    for(int i=0;i<days;i++)
    {
        startNum=startNum*(1+dailyInc);
        cout<<"day"<<i+1<<":  "<<startNum<<endl;
    }
    return 0;
}