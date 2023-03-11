////tamar share yshov - 213290711
////9.1
//#include <iostream>
//#include "SearchTree.h"
//#include "Book.h"
//using namespace std;
//
//int main() {
//	Book newBook;
//	SearchTree<Book> labrary;
//	char choice;
//	bool end = false;
//	puts("enter a-e:");
//	choice = getchar();
//	while (end) {
//		switch (choice) {
//		case 'a': {
//			puts("enter a book");
//			cin >> newBook;
//			labrary.add(newBook);
//		}
//		case 'b': {
//			puts("enter a book:");
//			cin >> newBook;
//			try { labrary.remove(newBook); }
//			catch (const char*){
//				cerr << "not exist" << endl;}
//		}
//		case 'c': {
//			puts("enter a book:");
//			cin >> newBook;
//			try { labrary.search(newBook);
//				puts("exist");}
//			catch (const char*) {
//				cerr << "not exist" << endl;
//			}
//		}
//		case 'd': {
//			labrary.inOrder();
//		}
//		case 'e': {
//			end == true;
//			break;
//		}
//		default: {
//			cerr << "error" << endl;
//		}
//	}
//}
//	return 0;
//}
////example for running progrem:
////enter a - e:
////a
////enter a book :
////2 b b
////enter a - e :
////	a
////	enter a book :
////5 e e
////enter a - e :
////	a
////	enter a book :
////1 a a
////enter a - e :
////	a
////	enter a book :
////4 d d
////enter a - e :
////	a
////	enter a book :
////7 g g
////enter a - e :
////	a
////	enter a book :
////3 c c
////enter a - e :
////	b
////	enter a book :
////5 e e
////enter a - e :
////	d
////	1 a a
////	2 b b
////	3 c c
////	4 d d
////	7 g g
////	enter a - e:
////e
