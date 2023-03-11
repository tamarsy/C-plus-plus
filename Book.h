#pragma once
#include <string>
using namespace std;
class Book
{
public:
	Book(int = 0, string = "", string = "");
	bool operator>(Book& book);
	bool operator<(Book& book);
	bool operator>=(Book& book);
	bool operator<=(Book& book);
	bool operator==(Book& book);
	bool operator!=(Book& book);
	friend ostream& operator<<(ostream& o, Book& book);
	friend istream& operator>>(istream& i, Book& book);
private:
	int cdoe;
	string name;
	string righted;
};