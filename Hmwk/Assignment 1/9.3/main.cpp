/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 18, 2019, 12:51 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
void Sort(int[],int);

float Average(int[],int);


int main(int argc, char** argv) {
    int size;
    cout<<"input the size"<<endl;
    cin>>size;
    int *array=new int[size];
    cout<<"input the score"<<endl;
    int score;
    for(int i=0;i<size;i++)
    {
        do
        {
            cin>>score;
            if(score<0)
            {
                cout<<"please input a positive value"<<endl;
            }
        }while(score<0);
        array[i]=score;
    }
    Sort(array,size);
     cout<<"In ascending order: ";
    for(int i=1;i<size;i++)
    {
       
        cout<<array[i]<<" ";
    }
     cout<<endl<<"average score is "<<Average(array,size)<<endl;
     delete[] array;
    return 0;
}

void Sort(int array[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
        if(array[i]>array[j])
        {
            int temp;
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
        }
    }
}
float Average(int array[],int size)
{
    int sum=0;
    float average;
    for(int i=1;i<size;i++)
    {
        sum=sum+array[i];
        average=(float)sum/(size-1);
    }
    return average;
}
