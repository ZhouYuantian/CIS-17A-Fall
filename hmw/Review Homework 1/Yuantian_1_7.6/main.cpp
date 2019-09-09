/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on 2019年9月9日, 上午4:49
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char weather[3][30];
    int r,c,s,r1,r2,r3,s1,s2,s3,c1,c2,c3;
    r=c=s=r1=r2=r3=s1=s2=s3=c1=c2=c3=0;
ifstream infile("RainOrShine.txt");
   
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<30;j++)
        {
            infile>>weather[i][j];
                     
        }
    }
      for(int i=0;i<3;i++)
    {
        for(int j=0;j<30;j++)
        {
            cout<<weather[i][j]<<" ";
                     
        }
    }
cout<<endl<<"June:"<<endl;
    for(int i=0;i<30;i++)
    {
        switch(weather[0][i])
        {
            case 'S':
                s1++;
                cout<<"sunny ";
                break;
            case 'R':
                r1++;
                cout<<"rain ";
                break;
            case 'C':
                c1++;
                cout<<"cloud ";
                break;
            default:
                cout<<"n/a ";
                break;
        }
    }
    cout<<endl<<"July:"<<endl;
    for(int i=0;i<30;i++)
    {
     switch(weather[1][i])
        {
            case 'S':
                s2++;
                cout<<"sunny ";
                break;
            case 'R':
                r2++;
                cout<<"rain ";
                break;
            case 'C':
                c2++;
                cout<<"cloud ";
                break;
            default:
                cout<<"n/a ";
                break;
        }
    }
    cout<<endl<<"August:"<<endl;
    for(int i=0;i<30;i++)
    {
       switch(weather[2][i])
        {
            case 'S':
                s3++;
                cout<<"sunny ";
                break;
            case 'R':
                r3++;
                cout<<"rain ";
                break;
            case 'C':
                c3++;
                cout<<"cloud ";
                break;
            default:
                cout<<"n/a ";
                break;
        }
    }
    cout<<endl<<"Total Sunny day:"<<s1+s2+s3<<endl;
    cout<<"total rain day:"<<r1+r2+r3<<endl;
    cout<<"total cloudy day"<<c1+c2+c3<<endl;
    cout<<"rain in June:"<<r1<<endl;
    cout<<"sun in June:"<<s1<<endl;
    cout<<"cloud in June"<<c1<<endl;
    cout<<"rain in July:"<<r2<<endl;
    cout<<"sun in July"<<s3<<endl;
    cout<<"cloud in July"<<c2<<endl;
    cout<<"rain in August"<<r3<<endl;
    cout<<"sun in August"<<s3<<endl;
    cout<<"cloud in August"<<c3<<endl;
    
    
    if(r1>=r2 && r1>=r3)
        cout<<"most rain month is June"<<endl;
    else if(r2>=r1 && r2>=r3)
        cout<<"most rain month is July"<<endl;
    else
       cout<<"most rain month is August"<<endl;
      infile.close();
    return 0;
}

