/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "RollingResult.h"


RollingResult::RollingResult()
{
	win = 0;
	lose = 0;
	cont = 0;
}
RollingResult::~RollingResult()
{
}
const RollingResult RollingResult::operator=(const RollingResult&right)
{
	if (this != &right)
	{
		win = right.win;
		lose = right.lose;
		cont = right.cont;
	}
	return *this;
}

void RollingResult::addWinTimes()
{
	if (win < 0)
	{
		throw "error: win less than 0";
	}
	else
	{
		win++;
	}
}
void RollingResult::addLoseTimes()
{
	if (lose < 0)
	{
		throw "error: lose less than 0";
	}
	else
	{
		lose++;
	}
}
void RollingResult::addContTimes()
{
	if (cont < 0)
	{
		throw "error: cont less than 0";
	}
	else
	{
		cont++;
	}
}
int RollingResult::getWinTimes()
{
	return win;
}
int RollingResult::getLoseTimes()
{
	return lose;
}
void RollingResult::resetResult()
{
	win = 0;
	lose = 0;
	cont = 0;
}
void RollingResult::printWinTimes()
{
	cout << "Number of win times are: " << win << endl;
}
void RollingResult::printLoseTimes()
{
	cout << "Number of lose times are: " << lose << endl;
}
void RollingResult::printContTimes()
{
	cout << "Number of continues times are: " << cont << endl;
}
void RollingResult::printResult()
{
	printWinTimes();
	printLoseTimes();
}