#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int *filAray(int,int);
void prntAry(int *,int,int);
void prtMode(int *);
void destroy(int *);
void markSrt(int *,int);
int *mode(int *,int);
float findMedian(int [],int);
float findMean(int [],int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    int size,modVal,perLine,*a1D,*modAray;
    
    //Input or initialize values Here
    size=11;
    modVal=5;
    a1D=filAray(size,modVal);
    
    //Display the unsorted array
    prntAry(a1D,size,modVal);
    
    
    //Process/Calculations Here
    markSrt(a1D,size);
    modAray=mode(a1D,size);
     
    //Output Located Here
    prntAry(a1D,size,modVal);
    prtMode(modAray);
    cout<<endl<<"mean is "<<findMean(a1D,size)<<endl;
    cout<<"median is "<<findMedian(a1D,size)<<endl;
    //Clean up
    destroy(a1D);
    destroy(modAray);

    //Exit
    return 0;
}

void prtMode(int *a){
    if(a[1]>1)
    {
        cout<<"Number of modes is :"<<a[0]<<endl;
        cout<<"Frequency is "<<a[1]<<endl;
    }
    else
    {
        cout<<"no mode"<<endl;
    }
         
            
}

int *mode(int *a,int n){
    //You write the function
    int *modAray=new int[2];         
    int freq =1;
    modAray[0]=0;//Number of modes go here
    modAray[1]=0;//Frequence goes here
    //mode[2 to mode[0]];
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            freq++;
        }
        else
        {
            if(modAray[1]<freq)
            {
                modAray[1]=freq;
                modAray[0]=1;
            }
            else if(modAray[1]==freq)
            {
                modAray[0]++;
            }
            freq=1;
            
        }
    }
    if(modAray[1]<freq)
    {
        modAray[1]=freq;
        modAray[0]=1;
    }
    else if(modAray[1]==freq)
    {
        modAray[0]++;
    }
    return modAray;
}

void markSrt(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void destroy(int *a){
    delete []a;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *filAray(int n,int m){
    n=n<2?2:
      n>1000?1000:n;
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=i%m;//2 digit numbers
    }
    return array;
}
float findMedian(int array[],int size)
{
    float median;
    if(size%2==0)
    {
        median=(float)(array[size/2 -1] + array[size/2] )/2;
    }
    else
    {
        median=array[(size-1)/2 ];
    }
    return median;
}
float findMean(int array[],int size)
{
     int sum=0;
    for(int i=0;i<size;i++)
    {
        
        sum=sum+array[i];       
    };
    float mean=(float)sum/size;
    return mean;
}