/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef ROLLINGRESULT_H
#define ROLLINGRESULT_H
#include <iostream>
using namespace std;

class RollingResult
{
private:
	int win;//number of win times
	int lose;//number of lose times
	int cont;//number of continues times
public:
	RollingResult();
	virtual ~RollingResult();
	template <class T>
	RollingResult(T, T, T);
	template <class T>
	void setWinTimes(T);
	template <class T>
	void setLoseTimes(T);
	template <class T>
	void setContTimes(T);
	int getWinTimes();
	int getLoseTimes();
	int getContTimes();
	void resetResult();
	void addWinTimes();
	void addLoseTimes();
	void addContTimes();
	void printWinTimes();
	void printLoseTimes();
	void printContTimes();
	void printResult();
	const RollingResult operator=(const RollingResult&);
	friend ostream &operator<<(ostream&strm, const RollingResult&);
	friend istream &operator>>(istream&strm, RollingResult&);
};

template <class T>
RollingResult::RollingResult(T win, T lose, T cont)
{
	this->win = win;
	this->lose = lose;
	this->cont = cont;
}
#endif /* ROLLINGRESULT_H */