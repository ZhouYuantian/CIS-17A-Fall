/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FourDiceGame.h
 * Author: raytim
 *
 * Created on 2019年11月22日, 下午11:31
 */
#ifndef FOURDICEGAME_H
#define FOURDICEGAME_H
#include "ThreeDiceGame.h"
class FourDiceGame :public ThreeDiceGame
{
private:
	int dice4;//one dice more than three
public:
	FourDiceGame();
	template <class T>
	void setDice4(T);
	int getDice4();
	void printDice4();
	void printGame();
	void printSum();
	template <class T>
	FourDiceGame setGame(char, T, T, T, T, T, T);
	const FourDiceGame operator=(const FourDiceGame&);
	friend ostream &operator<<(ostream&strm, const FourDiceGame&);
	friend istream &operator>>(istream&strm, FourDiceGame&);

};

template <class T>
void FourDiceGame::setDice4(T dice4)
{
	this->dice4 = dice4;
}

template <class T>
FourDiceGame FourDiceGame::setGame(char result, T diceRollTimes, T sum, T dice1, T dice2, T dice3, T dice4)
{
	FourDiceGame g;
	g.setResult(result);
	g.setDiceRollingTimes(diceRollTimes);
	g.setSum(sum);
	g.setDice1(dice1);
	g.setDice2(dice2);
	g.setDice3(dice3);
	g.setDice4(dice4);
	return g;
}
#endif /* FOURDICEGAME_H */

