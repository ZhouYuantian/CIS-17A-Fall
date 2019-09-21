#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int binarySearch(string array[],int numElems, string value)
{
    int first=0,last=numElems-1,middle,position=-1;
    bool found=false;
    while(!found && first<=last)
    {
        middle=(first+last)/2;
        if(array[middle]==value)
        {
            found =true;
            position = middle;
        }
        else if(array[middle]<value)
        {
            first=middle+1;
        }
        else
        {
            last=middle-1;
        }
    }
    return position;
}
int main(int argc, char** argv) {
    string array[3]={"abc","bca","cba"};//must be sorted
    int num=3;
    string value="abc";
    cout<< binarySearch(array,num,value);
    return 0;
}

