#include<iostream>
using namespace std;

int main()
{
    int year;
    int month;
    int day;
    do{
    cout << "input the month" << endl;
    cin >> month;
    if(month<1||month>12)
    cout << "month is not in the range" << endl;
    }while(month<1||month>12);
    cout <<"Input the year"<<endl;
    cin>>year;
    if(year % 100 ==0 && year % 400==0 && month==2)
    day=29;
    else if(!year % 100 ==0 && year % 4==0 && month==2)
    day=29;
    else
    {
    switch(month)
    {
        case 1: day=31;
        break;
        case 2: day=28;
        break;
        case 3: day=31;
        break;
        case 4: day=30;
        break;
        case 5: day=31;
        break;
        case 6: day=30;
        break;
        case 7: day=31;
        break;
        case 8: day=31;
        break;
        case 9: day=30;
        break;
        case 10: day=31;       
        break;
        case 11: day=30;
        break;
        case 12: day=31;
        break; 
       
    }
    }
    cout<<day<<"days"<<endl;
    return 0;
}