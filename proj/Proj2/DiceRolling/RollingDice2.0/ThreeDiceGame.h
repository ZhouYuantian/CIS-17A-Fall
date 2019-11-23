/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ThreeDiceGame.h
 * Author: raytim
 *
 * Created on 2019年11月22日, 下午11:31
 */
#ifndef THREEDICEGAME_H
#define THREEDICEGAME_H
#include "Game.h"

class ThreeDiceGame :public Game
{
protected:
	int dice3;//one dice more than two
public:
	ThreeDiceGame();
	template <class T>
	void setDice3(T);
	int getDice3();
	void printDice3();
	void printGame();
	void printSum();
	template <class T>
	ThreeDiceGame setGame(char, T, T, T, T, T);
	const ThreeDiceGame operator=(const ThreeDiceGame&);
	friend ostream &operator<<(ostream&strm, const ThreeDiceGame&);
	friend istream &operator>>(istream&strm, ThreeDiceGame&);
};

template <class T>
void ThreeDiceGame::setDice3(T dice3)
{
	this->dice3 = dice3;
}

template <class T>
ThreeDiceGame ThreeDiceGame::setGame(char result, T diceRollTimes, T sum, T dice1, T dice2, T dice3)
{
	ThreeDiceGame g;
	g.setResult(result);
	g.setDiceRollingTimes(diceRollTimes);
	g.setSum(sum);
	g.setDice1(dice1);
	g.setDice2(dice2);
	g.setDice3(dice3);
	return g;
}
#endif /* THREEDICEGAME_H */