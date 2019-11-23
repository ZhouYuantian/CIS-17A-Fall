/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ThreeDiceGame.h"
ThreeDiceGame::ThreeDiceGame():Game()
  {
      dice3=0; 
  }
const ThreeDiceGame ThreeDiceGame::operator =(const ThreeDiceGame&right)
{
	if (this != &right)
	{
		diceRolltimes = right.diceRolltimes;
		sum = right.sum;
		dice1 = right.dice1;
		dice2 = right.dice2;
		dice3 = right.dice3;
		gameResult = right.gameResult;
		r = right.r;
	}
	return *this;
}
int ThreeDiceGame::getDice3()
{
	return dice3;
}
void ThreeDiceGame::printDice3()
{
	cout << "The dice 3 is: " << dice3 << endl;
}
void ThreeDiceGame::printSum()
{
	cout << "The sum of three dice is: " << sum << endl;
}
void ThreeDiceGame::printGame()
{
	printResult();
	printDice1();
	printDice2();
	printDice3();
	printSum();
	printDiceRollTimes();
}