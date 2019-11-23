/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Game.h"

int Game::gameCount = 0;
Game::Game()
{
	gameCount++;
	dice1 = 0;
	dice2 = 0;
	diceRolltimes = 0;
	sum = 0;
	r.resetResult();
}

void Game::setResult(char result)
{
	if (result == 'w')
	{
		gameResult = "win";
	}
	else
	{
		gameResult = "lose";
	}
}

void Game::printResult()
{
	cout << "The game result is: " << gameResult.c_str() << endl;
}
void Game::printSum()
{
	cout << "The sum of two dice is: " << sum << endl;
}
void Game::printDice1()
{
	cout << "The dice 1 is: " << dice1 << endl;
}
void Game::printDice2()
{
	cout << "The dice 2 is: " << dice2 << endl;
}
void Game::printDiceRollTimes()
{
	cout << "The dice rolling times are: " << diceRolltimes << endl;
}
void Game::printGame()
{
	printResult();
	printDice1();
	printDice2();
	printSum();
	printDiceRollTimes();
}

int Game::getGameCount()
{
	return gameCount;
}