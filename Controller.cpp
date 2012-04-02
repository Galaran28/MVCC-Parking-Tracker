#include <iostream>
#include "Lot.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	Lot Admin(40);
	Lot Lot1(500);
	Lot Lot2(600);
	Lot Lot3(200);
	Lot Dorm(200);
	Lot Open(500);
	Lot Maint(200);
	Lot Overflow(300);
	ofstream log;
	log.open ("log.txt");
	int lot, status, time;
	string line, sLot, sStatus, sTime;
	line = "1,2,0009";
	istringstream input(line);
	getline(input, sLot, ',');
	getline(input, sStatus, ',');
	getline(input, sTime, ',');
	cout << sLot << " " << sStatus << " " << sTime << endl;

	
	/*cin>>input;

			// Enter this loop if input fails because of invalid data.
			if ( ! (cin.good()))
			 {
				cout << "Invalid Input. "<<endl;
				cin.clear (); 
				cin.ignore (1000, '\n');
			}
				
			else
			{
				list.InsertItem(input);
			}*/


}



