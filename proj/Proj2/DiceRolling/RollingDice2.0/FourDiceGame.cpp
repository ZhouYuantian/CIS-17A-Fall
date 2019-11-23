/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FourDiceGame.h"

FourDiceGame::FourDiceGame() : ThreeDiceGame()
{
	dice4 = 0;
}
const FourDiceGame FourDiceGame::operator =(const FourDiceGame&right)
{
	if (this != &right)
	{
		diceRolltimes = right.diceRolltimes;
		sum = right.sum;
		dice1 = right.dice1;
		dice2 = right.dice2;
		dice3 = right.dice3;
		dice4 = right.dice4;
		gameResult = right.gameResult;
		r = right.r;
	}
	return *this;
}
int FourDiceGame::getDice4()
{
	return dice4;
}
void FourDiceGame::printDice4()
{
	cout << "The dice 4 is: " << dice4 << endl;
}
void FourDiceGame::printGame()
{
	printResult();
	printDice1();
	printDice2();
	printDice3();
	printDice4();
	printSum();
	printDiceRollTimes();
}
void FourDiceGame::printSum()
{
	cout << "The sum of four dice is: " << sum << endl;
}

