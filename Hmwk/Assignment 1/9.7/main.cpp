/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 18, 2019, 2:50 PM
 */



#include <cstdlib>
#include <iostream>
using namespace std;
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);
/*
 * 
 */
int main(int argc, char** argv) {
    int size;
    cout<<"input the size"<<endl;
    cin>>size;
    int val;
    int *donation=new int[size];
    for(int i=0;i<size;i++)
    {
        cout<<"input the value"<<endl;
        cin>>val;
        donation[i]=val;
    }
    int **arrPtr = new int*[size];
  
    for(int count=0;count<size;count++)
    {
        arrPtr[count]=&donation[count];
    }
    arrSelectSort(arrPtr,size);
    cout<<"The donation, sorted in descending order, are: \n";
    showArrPtr(arrPtr,size);
    cout<<"The donations, in their original oder, are: \n";
    showArray(donation,size);
    delete[] donation;
    for(int i=0;i<size;i++)
    {
        delete[] (arrPtr+i);
    }
    
    return 0;
}
void arrSelectSort(int *arr[], int size)
{
    int startScan, minIndex;
    int *minElem;
    for (startScan=0;startScan<(size-1);startScan++)
    {
        minIndex=startScan;
        minElem=arr[startScan];
        for(int index=startScan+1;index<size;index++)
        {
            if(*(arr[index])>*minElem)
            {
                minElem=arr[index];
                minIndex=index;
            }
        }
        arr[minIndex]=arr[startScan];
        arr[startScan]=minElem;
    }
}

void showArray(const int arr[], int size)
{
    for(int count=0;count<size;count++)
        cout<<arr[count]<<" ";
    cout<<endl;
}
void showArrPtr(int *arr[], int size)
{
    for(int count=0;count<size;count++)
        cout<<*(arr[count])<<" ";
    cout<<endl;
}
