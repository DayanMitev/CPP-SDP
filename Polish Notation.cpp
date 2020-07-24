
#include <iostream>
#include <stack>
#include <cstring>
#include <cassert>

//Stack type
int precedence(char c)
{
	if (c == '*' || c == '/' || c == '%') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	return 0;
}
// ((2+3) * 5) / 6  2 3 + 5 *6/
std::string inFixToPostfix(const std::string& expr)
{
	std::string postfixNotation;
	std::stack<char> s;
	for (size_t i = 0; i < expr.size(); i++) {
		if (expr[i] == '(')
		{
			s.push(expr[i]);
		}
		else if (expr[i] == ')')
		{
			while (s.size() && s.top() != '(') {
				postfixNotation.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
		else if ((expr[i] >= 'a' && expr[i] <= 'z') ||
			(expr[i] >= '0' && expr[i] <= '9'))
		{
			postfixNotation.push_back(expr[i]);
		}
		else {
			while (s.size() && precedence(s.top()) >= precedence(expr[i])) {
				postfixNotation.push_back(s.top());
				s.pop();
			}
			s.push(expr[i]);
		}
	}
	while (s.size()) {
		postfixNotation.push_back(s.top());
		s.pop();
	}
	return postfixNotation;
}


int main()
{
	std::cout << inFixToPostfix("a+b*c-d*e") << "\n";
	std::cout << inFixToPostfix("(a+b)*c") << "\n";
	std::cin.get();
}

