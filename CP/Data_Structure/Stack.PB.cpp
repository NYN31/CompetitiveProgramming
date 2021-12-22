/*
  C++ Program to check for balanced parentheses in an expression using stack.
  Given an expression as string comprising of opening and closing characters
  of parentheses - (), curly braces - {} and square brackets - [], we need to 
  check whether symbols are balanced or not. 
*/

#include<iostream>
#include<stack>
using namespace std;

bool cheak(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

int is_balance(string exp)
{
    stack <char> S;
    for(int i = 0; i<exp.size(); i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(S.empty() || !cheak(S.top(), exp[i])) return 0;
            else S.pop();
        }
    }
    if(S.empty()) return 1;
    else return 0;
}

int main()
{
    string exp;
    while(cin >> exp)
    {
        if(is_balance(exp))
            cout << "Balance\n";
        else
            cout << "Not Balance\n";
    }
    return 0;
}
