/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: raytim
 *
 * Created on 2019氓鹿麓10忙艙藛10忙鈥斅�, 盲赂鈥姑ワ拷藛2:27
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

#include "RollingResult.h"
#include "Game.h"
#include "ThreeDiceGame.h"
#include "FourDiceGame.h"
//six faces for dice
enum DiceNum {ONE,TWO,THREE,FOUR,FIVE,SIX};

/*
 * 
 */
int rollingDice();
template <class T>
Game setGame(char ,T ,T,T ,T);
template <class T>
ThreeDiceGame setGame(char ,T ,T,T ,T,T);
template <class T>
FourDiceGame setGame(char ,T ,T,T ,T,T,T);
void printGame(Game *,int);
void printGame(ThreeDiceGame *,int);
void printGame(FourDiceGame *,int);
int streak(char*,char,int);
int* streak(fstream&,char*,int,RollingResult&);
int twoDiceSum(int,int);
int threeDiceSum(int,int,int);
int fourDiceSum(int,int,int,int);
void writeRecord(int);
void printStreak(int*);
void checkDice(int);
void checkInput(int);

int main(int argc, char** argv) {
    srand(unsigned(time(0)));
    int n;//number of games
    //points get from the first time of rolling
    int myPoint;
    char good[]={"good "};
    char bad[]={"bad "};
    char luck[]={"luck"};
    RollingResult r;
    r.resetResult();
    cout<<"Input the number of games you want to play"<<endl;
    cin>>n;
    //vector of char for store a list of all games result
    vector <string>resultList;
    try
    {
        //check if is valid input
        checkInput(n);
    }
    catch(string exception)
    {
        //output the exception if is invalid
        cout<<exception<<endl;
        return 0;
    }
    FourDiceGame *g=new FourDiceGame[n];
    //for store the result of each game
    char *status=new char[n];//w for win, l for lose
    for(int i=0;i<n;i++)
    {
        //set the dice rolling times
        int rollNum=0;
        //roll the dices
        int d1=rollingDice();
        int d2=rollingDice();
        int d3=rollingDice();
        int d4=rollingDice();
        rollNum++;
        int sum=fourDiceSum(d1,d2,d3,d4);
        //win if get 14 or 23
        if(sum==14 || sum==23)
        {
            //add 'win' to the result list
            resultList.push_back("win");
            status[i]='w';
            try
             {
                r.addWinTimes();
             }
             catch(string exception)
             {
                 cout<<exception<<endl;
                 return 0;
             }
        }
        //lose if get 4 or 24
        else if(sum==4||sum==24)
        {
            //add 'lose' to the result list
            resultList.push_back("lose");
            status[i]='l';
            try
             {
                r.addLoseTimes();
             }
             catch(string exception)
             {
                 cout<<exception<<endl;
                 return 0;
             }
        }
        else
        {
            //continue rolling otherwise
            myPoint=sum;
            status[i]='c';
        }
        while (status[i]=='c') 
        {
            try
            {
                r.addContTimes();
            }
            catch(string exception)
            {
                cout<<exception<<endl;
                return 0;
            }
            // not WON or LOST   
            // roll dice again
            d1=rollingDice();
            d2=rollingDice();
            d3=rollingDice();
            d4=rollingDice();
            rollNum++;
            sum=d1+d2+d3+d4;
           // determine game status
         if (sum == myPoint) 
         { 
             // win by making point
             //add 'win' to the result list
             resultList.push_back("win");
             status[i]='w';
             try
             {
                r.addWinTimes();
             }
             catch(string exception)
             {
                 cout<<exception<<endl;
                 return 0;
             }
         } 
         else 
         { 
            if (sum == 14) 
            { 
                // lose by rolling 14 before point
                status[i] = 'l';
                //add 'lose' to the result list
                resultList.push_back("lose");
              try
              {
                 r.addLoseTimes();
              }
              catch(string exception)
              {
                  cout<<exception<<endl;
                  return 0;
              }
            } 
         } 
      } 
        g[i]=setGame(status[i],rollNum,sum,d1,d2,d3,d4);       
    }
    fstream file;
    file.open("Result.dat",ios::in | ios::out | ios::binary);
    //output the results to the file
    file.write(reinterpret_cast<char *>(&r),sizeof(r));
    //print detail of each game
    try
    {
        printGame(g,n);
    }
    catch(string exception)
    {
        cout<<exception<<endl;
        return 0;
    }
    try
    {
        if(!file)//erro checking
        {
            throw "erro opening file";
        }
        else
        {
            //read and print the total win/lose times
            file.read(reinterpret_cast<char *>(&r),sizeof(r));
            r.printResult();
        }
    }
    catch(string exception)
    {
        cout<<exception<<endl;
    }
    int* consecutive=new int[2];
    //for store the consecutive win/lose
    //find the longest win/lose streak
    consecutive=streak(file,status,n,r);
    printStreak(consecutive);
    //write the win streak to file if its longer than history
    writeRecord(consecutive[0]);
    if(r.getWinTimes()>r.getLoseTimes())
    {
        //"good luck" for wins more than loses
        strcat(good,luck);
        cout<<good<<endl;
    }
    else
    { 
        //otherwise "bad luck"
        strcat(bad,luck);
        cout<<bad<<endl;
    }
    file.close();
    delete []status;
    delete []g;
    delete []consecutive;
    return 0;
}

int rollingDice()
{    
    return (rand()%(SIX+1))+1;
}

template <class T>
Game setGame(char result,T diceRolltimes,T sum,T dice1,T dice2)
{  
    Game g;
    g.setResult(result);
    g.setDiceRollingTimes(diceRolltimes);
    g.setSum(sum);
    g.setDice1(dice1);
    g.setDice2(dice2);
    return g;
}
template <class T>
ThreeDiceGame setGame(char result,T diceRolltimes,T sum,T dice1,T dice2,T dice3)
{  
    ThreeDiceGame g;
    g.setResult(result);
    g.setDiceRollingTimes(diceRolltimes);
    g.setSum(sum);
    g.setDice1(dice1);
    g.setDice2(dice2);
    g.setDice3(dice3);
    return g;
}
template <class T>
FourDiceGame setGame(char result,T diceRolltimes,T sum,T dice1,T dice2,T dice3,T dice4)
{  
    FourDiceGame g;
    g.setResult(result);
    g.setDiceRollingTimes(diceRolltimes);
    g.setSum(sum);
    g.setDice1(dice1);
    g.setDice2(dice2);
    g.setDice3(dice3);
    g.setDice4(dice4);
    return g;
}

int* streak(fstream& file,char* array,int size,RollingResult&r)
{
    file.seekg(0,ios::beg);
    file.read(reinterpret_cast<char*>(&r),sizeof(r));
    int nsize=r.getWinTimes()+r.getLoseTimes();   
    char*narray=new char[nsize];
    int j=0;
    //copy to a new array that only contains win and lose
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        if(array[i]=='w'||array[i]=='l')
        {
            narray[j]=array[i];
            j++;
        }
   }
    int *consecu=new int[2];//to store the number of consecutive win/lose
    consecu[0]=streak(narray,'w',nsize);//consecutive wins
    consecu[1]=streak(narray,'l',nsize);//consecutive loses
    delete []narray;
    return consecu;
}
int streak(char *array,char a,int size)
{
    int cons=0;//current consecutive win/lose
    int max=0;//max consecutive win/lose
    for(int i=0;i<size;i++)
    {//count for consecutive win
        if(array[i]==a)
        {
            while(array[i]==array[i+1])
            {
                cons++;
                i++;
            }
            if(cons>max)
            {
                max=cons;
            }
            cons=0;
        }       
    }
    return max;
}

void printGame(Game *g,int n)
{
    if(n<0)
    {
        throw "erro: invalid number of games";
    }
    for(int i=0;i<n;i++)
    {
        cout<<"The round "<<i+1<<": "<<endl;
        g[i].printGame();
        cout<<endl;
    }
}
void printGame(ThreeDiceGame *g,int n)
{
    if(n<0)
    {
        throw "erro: invalid number of games";
    }
    for(int i=0;i<n;i++)
    {
        cout<<"The round "<<i+1<<": "<<endl;
        g[i].printGame();
        cout<<endl;
    }
}
void printGame(FourDiceGame *g,int n)
{
    if(n<0)
    {
        throw "erro: invalid number of games";
    }
    for(int i=0;i<n;i++)
    {
        cout<<"The round "<<i+1<<": "<<endl;
        cout<<g[i];
        cout<<endl;
    }
}

//Recored the winnig streak to the file if it's longer than the history
void writeRecord(int winStreak)
{
    fstream file("LongestWinStreak.txt",ios::in);
    int oldRecord;
    int oldMax=0;
    while(file>>oldRecord)
    {//find the higest record of history
        if(oldRecord>oldMax)
        {
            oldMax=oldRecord;
        }
    }
    file.close();
    file.open("LongestWinStreak.txt",ios::out | ios_base::app);
    winStreak++;
    if(winStreak>oldMax)
    {
        //write the new record at the end of the file
        file.seekp(0,ios::end);
        file<<"\r\n"<<winStreak;
        cout<<"Great! You break the record of longest win streak"<<endl;
    }
    file.close();
}
void printStreak(int *consecutive)
{
    if(consecutive[0]>0)
    {
        cout<<"The longest winnig streak is: "<<consecutive[0]+1<<endl;
    }
    if(consecutive[1]>0)
    {
        cout<<"The longest loseing streak is: "<<consecutive[1]+1<<endl;
    }
    if(consecutive[0]==0)
    {
        cout<<"No winnig streak "<<endl;
    }
    if(consecutive[1]==0)
    {
        cout<<"No loseing streak "<<endl;
    }
}

  ostream &operator<<(ostream&strm,const RollingResult&right)
  {
      strm<<"Number of win times are: "<<right.win<<endl;
      strm<<"Number of lose times are: "<<right.lose<<endl;
      strm<<"Number of cont times are: "<<right.cont<<endl;
      return strm;
  }
  istream &operator>>(istream&strm,RollingResult&right)
   {
       cout<<"input the win times:"<<endl;
       strm>>right.win;
       cout<<"input the lose times:"<<endl;
       strm>>right.lose;
       cout<<"input the continue times:"<<endl;
       strm>>right.cont;
       return strm;
   }
  ostream &operator<<(ostream&strm,const Game&right)
  {
      strm<<"The game result is: "<<right.gameResult<<endl;
      strm<<"The dice1 is: "<<right.dice1<<endl;
      strm<<"The dice2 is: "<<right.dice2<<endl;
      strm<<"The sum of two dice is: "<<right.sum<<endl;
      strm<<"The dice rolling times are: "<<right.diceRolltimes<<endl;
      return strm;
  }
  istream &operator>>(istream&strm,Game&right)
  {
      cout<<"input the dice 1: "<<endl;
      strm>>right.dice1;
      cout<<"input the dice 2: "<<endl;
      strm>>right.dice2;
      return strm;
  }
   ostream &operator<<(ostream&strm,const ThreeDiceGame&right)
   {
      strm<<"The game result is: "<<right.gameResult<<endl;
      strm<<"The dice 1 is: "<<right.dice1<<endl;
      strm<<"The dice 2 is: "<<right.dice2<<endl;
      strm<<"The dice 3 is: "<<right.dice3<<endl;
      strm<<"The sum of three dice is: "<<right.sum<<endl;
      strm<<"The dice rolling times are: "<<right.diceRolltimes<<endl;
      return strm;
   }
   istream &operator>>(istream&strm,ThreeDiceGame&right)
   {
       int dice1,dice2,dice3;
        cout<<"input the dice 1: "<<endl;
        strm>>dice1;
        cout<<"input the dice 2: "<<endl;
        strm>>dice2;
        cout<<"input the dice 3: "<<endl;
        strm>>dice3;
        right.setDice1(dice1);
        right.setDice2(dice2);
        right.setDice3(dice3);
        return strm;
   }
   ostream &operator<<(ostream&strm,const FourDiceGame&right)
   {
      strm<<"The game result is: "<<right.gameResult<<endl;
      strm<<"The dice 1 is: "<<right.dice1<<endl;
      strm<<"The dice 2 is: "<<right.dice2<<endl;
      strm<<"The dice 3 is: "<<right.dice3<<endl;
      strm<<"The dice 4 is: "<<right.dice4<<endl;
      strm<<"The sum of four dice is: "<<right.sum<<endl;
      strm<<"The dice rolling times are: "<<right.diceRolltimes<<endl;
      return strm;
   }
   istream &operator>>(istream&strm,FourDiceGame&right)
   {
       int dice1,dice2;
        cout<<"input the dice 1: "<<endl;
        strm>>dice1;
        cout<<"input the dice 2: "<<endl;
        strm>>dice2;
        cout<<"input the dice 3: "<<endl;
        strm>>right.dice3;
        cout<<"input the dice 4: "<<endl;
        strm>>right.dice4;
        right.setDice1(dice1);
        right.setDice2(dice2);
        return strm;
   }
 
  void checkInput(int input)
  {
      if(input<=0)
      {
          throw "invalid input";
      }
  }
  void checkDice(int dice)
  {
      if(dice<=0)
      {
          throw "invalid dice";
      }
  }
  int twoDiceSum(int dice1,int dice2)
  {
      try
      {
          checkDice(dice1);
          checkDice(dice2);
      }
      catch(string exception)
      {
          cout<<exception<<endl;
      }
      return dice1+dice2;
  }
  int threeDiceSum(int dice1,int dice2,int dice3)
  {
      try
      {
          checkDice(dice1);
          checkDice(dice2);
          checkDice(dice3);
      }
      catch(string exception)
      {
          cout<<exception<<endl;
      }
      return dice1+dice2+dice3;
  }
  int fourDiceSum(int dice1,int dice2,int dice3,int dice4)
  {
      try
      {
          checkDice(dice1);
          checkDice(dice2);
          checkDice(dice3);
          checkDice(dice4);
      }
      catch(string exception)
      {
          cout<<exception<<endl;
      }
      return dice1+dice2+dice3+dice4;
  }
