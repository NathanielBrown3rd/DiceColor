#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	string p1, p2;
	int die, p1Score, p2Score;
	unsigned seed;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	seed = time(0);
	srand(seed);

    
	cout << "===============================================================================" << endl;
	cout << "This program will roll a 20 sided die for each player and compare the 2 scores." << endl;
	cout << "===============================================================================" << endl;
	cout << "Please input player 1's name: ";
	getline(cin, p1);
	cout << "\nPlease input player 2's name: ";
	getline(cin, p2);
	cout << "\n";

	p1Score  = die = (rand() % (20 - 1 + 1)) + 1;
	p2Score = die = (rand() % (20 - 1 + 1)) + 1;

	if(p1Score == 1)
	{
		SetConsoleTextAttribute(screen, 4);
		cout << p1 << "'s roll was a ";
		cout << "Critical Failure!" << endl;
		SetConsoleTextAttribute(screen, 7);
	}
	else if(p1Score == 20)
	{
		cout << p1 << "'s roll was a ";
		SetConsoleTextAttribute(screen, 2);
		cout << "Critical Success!" << endl;
		SetConsoleTextAttribute(screen, 7);
	}

	if(p2Score == 1)
	{
		cout << p2 << "'s roll was a ";
		SetConsoleTextAttribute(screen, 4);
		cout << "Critical Failure!" << endl;
		SetConsoleTextAttribute(screen, 7);
	}
	else if(p2Score == 20)
	{
		cout << p2 << "'s roll was a ";
		SetConsoleTextAttribute(screen, 2);
		cout << "Critical Success!" << endl;
		SetConsoleTextAttribute(screen, 7);
	}

	if(p1Score > p2Score)
	{
		cout << p1 << " Roll:" << setw(4) << p1Score << setw(12) << p2 << " Roll:" << setw(4) << p2Score << endl;
		cout << "The Winner is " << p1 << "!!" << endl;
	}
	else if(p1Score < p2Score)
	{
		cout << p1 << " Roll:" << setw(4) << p1Score << setw(12) << p2 << " Roll:" << setw(4) << p2Score << endl;
		cout << "The Winner is " << p2 << "!!" << endl;
	}
	else
	{
		cout << p1 << " Roll:" << setw(4) << p1Score << setw(12) << p2 << " Roll:" << setw(4) << p2Score << endl;
		cout << "The Players are Evenly Matched."<< endl;
	}

	return 0;
}
