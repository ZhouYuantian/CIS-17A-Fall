#include<iostream>
#include<iomanip>
using namespace std;
float FtoC(float F)
{
    
    float C=5*(F-32)/9;
    return C;
}
int main()
{

    float F;
    for(int i=0;i<=20;i++)
    {
        F=i;
        cout <<setprecision(3)<<fixed<< i <<"F is " <<FtoC(F)<<"C"<< endl;
    }
    return 0;
}

