#include "Book.h"
#include <string>
#include <iostream>
using namespace std;
Book::Book(int code, string name, string righted) :
	cdoe(code), name(name), righted(righted) {}

bool Book::operator>(Book& book) {
	int biger = this->righted.compare(book.righted);
	if (biger > 0) { return true; }
	if (biger < 0) { return false; }
	biger = this->name.compare(book.name);
	if (biger > 0) { return true; }
	if (biger < 0) { return false; }
	return (this->cdoe > book.cdoe);
}

bool Book::operator<(Book& book) {
	return (!(*this > book) && !(*this == book));
}

bool Book::operator>=(Book& book) {
	return (!(*this < book));
}

bool Book::operator<=(Book& book) {
	return (!(*this > book));
}

bool Book::operator==(Book& book) {
	return !(*this != book);
}

bool Book::operator!=(Book& book) {
	bool flug = true;
	if (!(this->righted.compare(book.righted))) { flug = false; }
	if (!(this->name.compare(book.name))) { flug = false; }
	return flug && (this->cdoe != book.cdoe);
}

ostream& operator<<(ostream& o, Book& book) {
	o << book.cdoe << book.righted << book.name;
	return o;
}

istream& operator>>(istream& i, Book& book) {
	i >> book.cdoe >> book.righted >> book.name;
	return i;
}