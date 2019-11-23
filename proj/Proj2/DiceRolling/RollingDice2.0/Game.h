/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: raytim
 *
 * Created on 2019年11月22日, 下午11:31
 */

#ifndef GAME_H
#define GAME_H
#include "RollingResult.h"
#include <iostream>
using namespace std;
class Game
{
protected:
	static int gameCount; //count the number of game
	string gameResult; //win or lose
	int diceRolltimes; //number of times of rolling dice
	int sum;//sum of two dices
	int dice1;
	int dice2;
	RollingResult r;
public:
	Game();
	template <class T>
	Game(string, T, T, T, T, RollingResult);
	void setResult(char);
	template <class T>
	void setDiceRollingTimes(T diceRolltimes)
        { 
            this->diceRolltimes = diceRolltimes;
        }
	template <class T>
	void setSum(T sum)
        {
            this->sum = sum;
        }
	template <class T>
	void setDice1(T dice1)
        {
            this->dice1 = dice1;
        }
	template <class T>
	void setDice2(T dice2)
        {
            this->dice2 = dice2;
        }
	template <class T>
	void setGame(char, T, T, T, T);
	char getResult();
	RollingResult getRollingResult();
	int getDiceRollTimes();
	int getSum();
	int getDice1();
	int getDice2();
	void printResult();
	void printSum();
	void printDice1();
	void printDice2();
	void printGame();
	void printDiceRollTimes();
	int getGameCount();
	Game(const Game&right)
        {
                diceRolltimes = right.diceRolltimes;
                sum = right.sum;
                dice1 = right.dice1;
                dice2 = right.dice2;
                gameResult = right.gameResult;
                r = right.r;
        }
	friend ostream &operator<<(ostream&strm, const Game&);
	friend istream &operator>>(istream&strm, Game&);
};

template <class T>
Game::Game(string result, T diceRolltimes, T sum, T dice1, T dice2, RollingResult r)
{
	this->diceRolltimes = diceRolltimes;
	this->sum = sum;
	this->dice1 = dice1;
	this->dice2 = dice2;
	this->r = r;
}
#endif /* GAME_H */