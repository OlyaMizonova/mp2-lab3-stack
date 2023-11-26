//// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include"TStack.h"
#include "Calculator.h"
bool TCalculator::isCorrect() {
    if (!c.is_empty()) {
        c.clear();
    }
    int res = 0;
    for (int i = 0; i < inf.size(); i++) {
        if (inf[i] == '(') {
            c.push(inf[i]);
        }
        if (inf[i] == ')') {
            if (!c.is_empty()) {
                c.pop();
            }
            else {
                res = 1;
            }

        }
    }
    if (!c.is_empty()) {
        res = 1;
    }
    return !res;
}


void TCalculator::set_infix(std::string str)
{
    inf = str;
}

std::string TCalculator::get_postfix()
{
    return postf;
}

std::string TCalculator::get_infix()
{
    return inf;
}

double TCalculator::CalcPostfix()
{
    if (!d.is_empty()) {
        d.clear();
    }
    for (int i = 0; i < postf.length(); i++) {
        if (postf[i] >= '0' && postf[i] <= '9')
        {
            d.push(postf[i] - '0');
        }
        if ((postf[i] == '+') || (postf[i] == '-') ||
            (postf[i] == '*') || (postf[i] == '/') ||
            (postf[i] == '^')) {
            double x1 = 0, x2 = 0, y = 0;
            if (!d.is_empty()) {
                x2 = d.pop();
            }
            if (!d.is_empty()) {
                x1 = d.pop();
            }
            if (postf[i] == '+')
                y = x1 + x2;
            if (postf[i] == '-')
                y = x1 - x2;
            if (postf[i] == '*')
                y = x1 * x2;
            if (postf[i] == '/')
                y = x1 / x2;
            if (postf[i] == '^')
                y = pow(x1, x2);
            d.push(y);
        }
    }
    double res;
    if (!d.is_empty())
    {
        res = d.pop();
    }
    else
    {
        throw "stack is empty";
    }
    if (!d.is_empty())
    {
        throw "wrong result";
    }
    return res;
}

void TCalculator::ToPostfix()
{
    //if (CheckExpression() == 0)
    //{
    //    throw "the_number_of_brackets_is_incorrect";
    //}
    if (!c.is_empty())
    {
        c.clear();
    }
    std::string str = '(' + inf + ')';
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            c.push('(');
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            postf += str[i];
        }
        if (str[i] == ')')
        {
            char opelement = c.pop();
            while (opelement != '(')
            {
                postf += opelement;
                opelement = c.pop();
            }
        }
        if ((str[i] == '+') || (str[i] == '-') ||
            (str[i] == '*') || (str[i] == '/') ||
            (str[i] == '^')) {
            char opelement = c.pop();
            if (prioritet(opelement) >= prioritet(str[i]))
            {
                postf += opelement;
                opelement = c.pop();
            }
            else
            {
                c.push(opelement);
            }
            c.push(str[i]);
        }
    }

}
//int main() {
//	std::string s;
//	std::cin >> s;
//	if (isCorrectBrackes(s)) {
//		std::cout << "everything is okay";
//	}
//	else {
//		std::cout << "something wrong";
//	}
//}