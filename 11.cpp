//tamar shear yeshov - 213290711
//11
#include <iostream>
#include "Family.h"
#include <fstream>
#include <Queue>
//-----------------------------------------------------


int const sizeOfFamily = sizeof(Family);

queue<Family> q;

void setFile(fstream& f) {
	for (int i = 0; i < 100; ++i) {
		Family family;
		f.write(((char*)&family), sizeOfFamily);
	}
}

void add(fstream& f) {
	Family family;
	int temp = 0;
	puts("enter family details");
	cin >> family.codeOfFamily;
	//gets_s(family.nameOfFamily);
	cin >> family.nameOfFamily;
	cin >> family.numOfSouls >> family.phone;
	f.seekg(double(family.codeOfFamily) * sizeOfFamily);
	f.read((char*)&temp, sizeof(int));
	if (family.codeOfFamily > 100 || family.codeOfFamily < 1) {
		throw "ERROR: Invalid family number";
	}
	if (temp)
	{
		throw "ERROR: Family is already in the file";
	}
	f.seekp(double(family.codeOfFamily) * sizeOfFamily);
	f.write((char*)&family, sizeOfFamily);
}

void del(fstream& f, int num) {
	if (num > 100 || num < 1) { throw "ERROR: Invalid family number"; }
	f.seekp(double(num) * sizeOfFamily);
	Family empty;
	f.write((char*)&empty, sizeof(Family));
}

bool checkIfInFile(fstream& f, int num) {
	int codeOfFamily;
	f.seekg(double(num) * sizeOfFamily);
	f.read((char*)&codeOfFamily, sizeof(int));
	if (codeOfFamily) {
		return true;
	}
	else {
		return false;
	}
}

void update(fstream& f, int num) {
	if (num > 100 || num < 1) {
		throw "ERROR: Invalid family number";
	}

	if (!checkIfInFile) {
		throw"ERROR: Family is not in the file";
	}
	Family family;
	f.seekg(double(num) * sizeOfFamily);
	f.read((char*)&family, sizeOfFamily);
	int counterForCourse[6] = {};
	for (int i = 0; i < sizeof(family.course); ++i) {
		cin >> family.course[i];
	}
	f.seekg(0, ios::beg);
	for (int i = 0; i < 100; ++i) {
		Family temp;
		f.read((char*)&temp, sizeOfFamily);
		if (temp.codeOfFamily) {
			for (int i = 0; i < sizeof(temp.course); ++i) {
				counterForCourse[i] += temp.course[i];
			}
		}
	}
	bool tempForWaitingQueue[6] = { false };
	for (int i = 0; i < sizeof(family.course); ++i) {
		if (counterForCourse[i] >= 10) {
			family.course[i] == true;
		}
		else {
			tempForWaitingQueue[i] = family.course[i];
			family.course[i] = false;
		}
	}

	q.push(family);
	for (int i = 0; i < sizeof(family.course); ++i) {
		family.course[i] = tempForWaitingQueue[i];
	}
	f.seekp(double(num) * sizeOfFamily);
	f.write((char*)&family, sizeOfFamily);
}

void waiting(fstream& f, queue<Family> q) {
	Family family = q.front();
	int counter[sizeof(family.course)] = {};
	for (int i = 0; i < 100; ++i) {
		Family familyTemp;
		f.read((char*)&familyTemp, sizeOfFamily);
		for (int i = 0; i < sizeof(familyTemp.course); ++i) {
			counter[i] += int(familyTemp.course[i]);
		}
	}
	for (int i = 0; i < sizeof(family.course); ++i) {
		bool isWaiting = false; char YorN;
		if (family.course[i]) {
			if (counter[i] < 10) {
				puts(family.nameOfFamily); cout << family.phone;
				YorN = getchar();
				if (YorN == 'Y') {
					++counter[i]; Family tempForCouse;
					f.seekp(double(family.codeOfFamily) * sizeOfFamily);
					f.seekg(double(family.codeOfFamily) * sizeOfFamily);
					f.read((char*)&tempForCouse, sizeOfFamily);
					tempForCouse.course[i] = true;
					f.write((char*)&tempForCouse, sizeOfFamily);
				}
				family.course[i] = false;
			}
			else isWaiting = true;
		}
		if (!isWaiting) {
			q.pop();
		}
	}

}

bool rishum(fstream& f, int num, int numOfCourse) {
	if (num > 100 || num < 1) { throw "ERROR: Invalid family number"; }
	if (!checkIfInFile) { throw"ERROR: Family is not in the file"; }
	if (numOfCourse > 6 || numOfCourse < 1) { "ERROR: Invalid class number"; }
	bool course = false;
	f.seekp(double((num + 1) * sizeOfFamily - sizeof(int)));
	f.read((char*)&course, sizeof(bool));
	return course;
}

void print(fstream& f, int num) {
	if (num > 100 || num < 1) {
		throw "ERROR: Invalid family number";
	}

	if (!checkIfInFile) {
		throw"ERROR: Family is not in the file";
	}
	Family family;
	f.seekg(double(num) * sizeOfFamily);
	f.read((char*)&family, sizeOfFamily);
	puts(family.nameOfFamily);
	cout << family.numOfSouls << endl << family.phone << endl;
	for (int i = 0; i < sizeof(family.course); ++i) {
		family.course[i] ? (cout << 'Y') : (cout << 'N');
		cout << '\t';
	}
}

void inClass(fstream& f, int numOfCourse) {
	if (numOfCourse > 6 || numOfCourse < 1) { throw "ERROR: Invalid class number"; }
	f.seekg(0, ios::beg);
	for (int i = 0; i < 100; ++i) {
		Family familyTemp;
		f.read((char*)&familyTemp, sizeOfFamily);
		if (familyTemp.course[numOfCourse]) {
			puts(familyTemp.nameOfFamily);
		}
	}
}

//-----------------------------------------------------

using namespace std;
enum MyEnum { ADD = 1, DEL, UPDATE, WAITING, RISHUM, PRINT, CLASS };
int main(){
	fstream file;
	file.open("families.txt", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}
	setFile(file);
	int choice;
	int snum;
	int cnum;
	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to update rishum to classes\n4 to update waiting to classes \n5 to check rishum for a classas\n6 to print a family\n7 to print all the families that participate in a specific class\n";
	cout << "enter 0-7:\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case ADD://add to the file
			try { add(file); }
			catch (const char* msg) { cout << msg; }
			break;
		case DEL://delete from file
			cout << "enter number of family to delete:\n";
			cin >> snum;
			try { del(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case UPDATE://update the list of classes of a family
			cout << "enter number of family to update:\n";
			cin >> snum;
			try { update(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case WAITING://update the list of classes of a waiting family
			waiting(file, q);
			break;
		case RISHUM://check rishum to a specific class
			cout << "enter number of family to check rishum:\n";
			cin >> snum;
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try
			{
				cout << "The family is" << (rishum(file, snum, cnum) ? " " : " not ") << "taking the class\n";
			}
			catch (const char* msg) { cout << msg; }
			break;
		case PRINT://print the details of a specific family
			cout << "enter number of family to print:\n";
			cin >> snum;
			try { print(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;
		case CLASS://print the details of all the families that are taking a specific class
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try { inClass(file, cnum); }
			catch (const char* msg) { cout << msg; }
			break;
		default:
			cout << "ERROR: invalid choice\n";

		}
		cout << "\nenter 0-7:\n";
		cin >> choice;
	}
	file.close();
	return 0;
}
//exaple for running progrem
//Choices are:
//0 to exit
//1 to add a family
//2 to delete a family
//3 to update rishum to classes
//4 to update waiting to classes
//5 to check rishum for a classas
//6 to print a family
//7 to print all the families that participate in a specific class
//enter 0 - 7 :
//	1
//	enter family details
//	4
//	fhdg
//	8
//	888888888
//
//	enter 0 - 7:
//1
//enter family details
//3
//gfh
//888888888
//1
//
//enter 0 - 7:
//9
//ERROR : invalid choice
//
//enter 0 - 7 :
//0