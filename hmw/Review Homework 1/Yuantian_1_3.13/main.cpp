#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    float totalAge;
    cout<<"input the totalAge"<<endl;
    cin >> totalAge;
    cout << setprecision(4)<<fixed<<setw(12)<<totalAge<< endl;
    return 0;
}