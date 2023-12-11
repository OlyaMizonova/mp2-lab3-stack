#pragma once
#pragma once
#include <string>
#include <cmath>
#include "TStack.h"
class TCalculator
{
	std::string  inf, postf;
	TListStack<char> operators = TListStack<char>();// 
	TListStack<double> operands = TListStack<double>();;// 
public:
	TCalculator(std::string& str) :inf(str) { ToPostfix(); };
	bool isCorrect();
private:
	int priority(char op)
	{
		if (op == '(' || op == ')')
			return 0;
		if (op == '+' || op == '-')
			return 1;
		if (op == '*' || op == '/')
			return 2;
		if (op == '^')
			return 3;
	}
	void ToPostfix();
public:
	double calc();
	void set_infix(std::string str);
	std::string get_postfix();
	std::string get_infix();
	double CalcPostfix();

};