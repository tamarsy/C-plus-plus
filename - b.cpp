// Lesson12 - b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
struct worker
{
	long id;
	char name[15];
	float hours;
	float salary;
};

int main()
{
	//cout << sizeof(long);
	ofstream f1;
	f1.open("workers.bin", ios::binary); //
	if (!f1)
	{
		cout << "Error...";
		return 1;
	}
	worker  worker1;
	for (int i = 0; i < 3; i++)
	{
		cout << "enter workers name ";
		cin >> worker1.name;
		cout << "enter " << worker1.name << "'s id ";
		cin >> worker1.id;
		cout << "enter number of hours ";
		cin >> worker1.hours;
		cout << "enter a salary per hour ";
		cin >> worker1.salary;

		f1.write((char*)&worker1, sizeof(worker));
	}
	f1.close();

	ifstream f2("workers.bin");
	f2.read((char*)&worker1, sizeof(worker));
	cout << worker1.name << worker1.id << worker1.hours << worker1.salary << endl;

	while (!f2.eof())
	{
		f2.read((char*)&worker1, sizeof(worker));
		cout << worker1.name << worker1.id << worker1.hours << worker1.salary << endl;
	}

	f2.close();
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
