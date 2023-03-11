//#include "StackList.h"
//#include <iostream>
//#include <string>
//using namespace std;
//
//string& infixToPostfix(string infix) {
//	string postfix;
//	StackList stk;
//
//	char ch;
//	while (infix != ""){
//		ch = infix.front();
//		if (ch == '('){
//			stk.push(ch);
//		}
//		else if (ch == ')') {
//			ch = stk.pop();
//			while (ch != '('){
//				postfix += ' '; postfix += ch;
//				ch = stk.pop();
//			}
//			
//		}
//		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'
//			|| ch == '%' || ch == 'x') {
//			stk.push(ch);
//		}
//		else if (ch >'0' && ch <= '9') {
//			postfix += ' '; postfix += ch;
//		}
//		infix.erase(infix.begin()); infix.erase(infix.begin());
//	}
//	while (!stk.isEmpty()) {
//		postfix += ' '; postfix += stk.pop();
//	}
//	while (postfix != "")
//	{
//		cout << postfix.front();
//		postfix.erase(postfix.begin());
//	}
//	return postfix;
//}
//
//float calcPostfix(string postfix) {
//
//	StackList stk;
//	char ch;
//	while (postfix != ""){
//		ch = postfix.front();
//		postfix.erase(postfix.begin());
//		if (ch > 47 && ch < 56){
//			stk.push(ch);
//		}
//		else {
//			int num1 = stk.pop();
//			int num2 = num1 + stk.pop();
//			stk.push(num2);
//		}
//		ch = postfix.front();
//		postfix.erase(postfix.begin());
//	}
//	return stk.pop();
//}
//
//int main()
//{
//	string exp;
//	cout << "enter an infix expression as a string" << endl;
//	cin >> exp;
//	string postfix = infixToPostfix(exp);
//	cout << postfix << endl;
//	cout << calcPostfix(postfix) << endl;
//	return 0;
//}
//
////example for running progrem:
////enter an infix expression as a string
////(5 + 3)ª((20 / 10) + (8 - 6))
////(5+3)ª((20/10)+(8-6))
////5 3 + 20 10 / 8 6 - + *
////32
