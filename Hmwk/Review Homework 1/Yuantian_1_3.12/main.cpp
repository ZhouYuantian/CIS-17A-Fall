#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    float divSales;
    cout << "enter the divSalee" << endl;
    cin >> divSales;
    cout<<setprecision(2)<<fixed<<showpoint<<setw(8)<<divSales;
        return 0;
}