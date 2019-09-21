/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Raytim
 *
 * Created on 2019年9月18日, 下午9:57
 */

#include <cstdlib>

using namespace std;
int *arrayAllocator(int);

/*
 * 
 */
int main(int argc, char** argv) {
    int *array=NULL;
    array=arrayAllocator(5);
    delete [] array;
    return 0;
}

int *arrayAllocator(int size)
{
    int *array=new int[size];
    return array;
}