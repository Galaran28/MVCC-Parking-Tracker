#include <iostream>
#include "Lot.h"
#include "randHead.h"
#include <fstream>
#include "Car.h"
#include <string>
#include <sstream>//needed to take care of istringstream line
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//void ChangeTotals(int, int, int);//function previews
//void LogChange(int, int, int, int);
void LotChooser(int, int, string);
void FindSpot(enum lotname, enum lotname);
enum names LotGroup(enum names entrance);
bool LotGroup1Full();
bool LotGroup2Full();
bool AllLotsFull();
// used same enum type (names) for lots and entrances so recursion would be possible
enum names { mall, //go to mall
			 admin, lot1, lot2, lot3, dorm, open, maint, overflow, //lot names
			 shermanA, shermanB, armory, tildenA, tildenB, //entrance names
			 lotGroupA, lotGroupB // group names
			};	


Lot Admin(40);//create class for each lot, starting maxSize is arg
Lot Lot1(500);
Lot Lot2(600);
Lot Lot3(200);
Lot Dorm(200);
Lot Open(500);
Lot Maint(200);
Lot Overflow(300);

int main()
{
	int lot, status, time;//declare variables that are the args for ChangeTotals
	string line, sLot, sStatus, sTime;//strings for reading and eventual conversion to int

	//randHead rand;
	//rand.generateCars(); //genertates number of cars going to each entrance
	int count = 0;
	
	while (count < 10)
	{
		line = "1,1,0009";//test line, to test splitting on commas, takes input in format lot,status,time
		istringstream input(line);//create an istringstream, input, that takes the current line as an argument
		getline(input, sLot, ',');//get the lot number
		getline(input, sStatus, ',');//get the status of the car, leaving or parking (0 or 1)
		getline(input, sTime, ',');//get the time
		lot = atoi (sLot.c_str());//convert the lot string to an int
		status = atoi (sStatus.c_str());//convert the status string to an int
		time = atoi (sStatus.c_str());
		bool goodInput = false;//define a boolean value to see if the input format is good
		while (!goodInput)
		{
			goodInput = true;
			if (!(lot > 0 && lot < 9))//check if the lot number is within it's boundaries
				goodInput = false;
			if (!(status == 1 || status == 0 || status == 2))//check if the car is coming or going
				goodInput = false;
			if (!(time >= 0 && time <= 2359))//check if the time is within bounds
				goodInput = false;
		}
		if (goodInput == true)//if the input is okay, update the totals
			LotChooser(lot, status, sTime);
		++count;
	}	
}

enum names LotGroup(enum names entrance)
{
	if (entrance >= 1 && entrance < 6)
	return lotGroupA;

	else if (entrance == 7 || entrance == 8)
	return lotGroupB;
}

bool LotGroupAFull() 
//checks if adjoining lots are full
{
	return (Admin.IsFull() && Lot1.IsFull() && Lot2.IsFull() && Lot3.IsFull() && Dorm.IsFull());
}

bool LotGroupBFull()
//checks if all adjoining lots are full
{
	return (Maint.IsFull() && Overflow.IsFull());
}

bool AllLotsFull()
//checks if all lots are full
{
	return (LotGroupAFull() && LotGroupBFull() && Open.IsFull());
}

enum names ParkingIntent(enum names entrance)
/*	
	Entrance Function
	Takes desired entrance, returns desired destination lot
	Considers if all attached lots are full
	If all attached lots are full, sends car to different "lot group"

*/
{
	int intent = rand() % 100 + 1; //Generates number from 1 to 100

	if (entrance == shermanA)						//Wants to enter at Sherman A			
	{
		if (!Open.IsFull())							//If Open lot isn't full
			return open;							//heads to Open lot
		else	
		{											
			if (!LotGroupAFull())					//If Open lot is full
				return ParkingIntent(shermanB);		//tries to enter at Sherman B, recursion

			else if (!LotGroupBFull())				//If Sherman B is full 
				return ParkingIntent(tildenB);		//tries to enter at Tilden B, recursion

			else
				return mall;						//heads to Mall			
			
		}
	}
	else if (entrance == shermanB)	//Wants to enter at Sherman B
	{
		if (!LotGroupAFull())		//If attached lots aren't full
		{
			if (intent == 1)		//heads to Admin lot
				return admin;
	
			else if (intent <= 76)	//heads to Lot 1
				return lot1;

			else if (intent <= 96)	//heads to Lot 2
				return lot2;

			else if (intent <= 98)	//heads to Lot 3
				return lot3;

			else
				return dorm;		//heads to Dorm lot
		}
		else									
			if(!Open.IsFull())					//If attached lots are full
				return ParkingIntent(shermanA);	//Tries to enter at Sherman A (Open lot)

			else if (!LotGroupBFull())			//If Open lot is full
				return ParkingIntent(tildenB);	//Tries to enter at tolden B

			else return mall;					//heads to mall
	}
	else if (entrance == armory)	//Wants to enter at Armory
	{
		if (!LotGroupAFull())
		{
			if (intent <= 78)		//heads to Lot 1
				return lot1;

			else if (intent <= 96)	//heads to Lot 2
				return lot2;

			else if (intent <= 99)	//heads to Lot 3
				return lot3;

			else
				return dorm;		//heads to Dorm lot
		}
		else
		{
			if (!LotGroupBFull())				//if attached lots are full (LotGroupA)
				return ParkingIntent(tildenB);	//Tries to enter at tilden B

			else if(!Open.IsFull())				//If attached lots are full	(LotGroupB)							
				return ParkingIntent(shermanA);	//Tries to enter at Sherman A (Open lot)
			else
				return mall;					//heads to mall
		}

	}

	else if (entrance == tildenA)	//Wants to enter at Tilden A
	{
		if (!LotGroupAFull())
		{
			if (intent <= 58)		//heads to Lot 1
				return lot1;

			else if (intent <= 88)	//heads toLot 2
				return lot2;

			else if (intent <= 90)	//heads toLot 3
				return lot3;

			else
				return dorm;		//heads to Dorm
		}
		else
		{
			if (!LotGroupBFull())				//if attached lots are full (LotGroupA)
				return ParkingIntent(tildenB);	//Tries to enter at tilden B

			else if(!Open.IsFull())				//If attached lots are full	(LotGroupB)							
				return ParkingIntent(shermanA);	//Tries to enter at Sherman A (Open lot)
			else
				return mall;					//heads to mall


		}
	}
	else if (entrance == tildenB)	//Wants to enter at Tilden B
	{
		if (!LotGroupBFull())	
		{
		if (intent <= 80)			//heads to Maint
			return maint;

		else						//heads to Overflow
			return overflow;
		}
		else
		{
			if (!LotGroupAFull())				//If attached lots are full	(LotGroupB)	
				return ParkingIntent(armory);	//Tries to enter at Armory

			else if(!Open.IsFull())				//If attached lots are full	(LotGroupA)							
				return ParkingIntent(shermanA);	//Tries to enter at Sherman A (Open lot)

			else
				return mall;					//heads to mall

		}
	}	
}

void FindSpot(enum names entrance, enum names destination)
{
	if (LotGroup(entrance) == lotGroupA)
	{
		int emptylot[4];
		if 
	}
	/*else if (entrance == open)

	else */
	if (LotGroup(entrance) == lotGroupB)
	{
		ChangeTotals(maint, 1, time);//Total increases as car drives in

			if ((destination == overflow)||(Maint.IsFull()))
		{	
			{
				ChangeTotals(maint, 0, time);
				ChangeTotals(overflow, 1, time);
			}
		}////Left off here!!!
		else


	}
}

void LotChooser(int lot, int status, string time)//a function that provides lot-specific info, like the name and which lot
	//the car is parking in, as well as status. Time is a string here for easier formatting in the log
	
	
	/* !! doesn't account for lot intention, i.e. 
	A car drives into lot 1 and wants to park in the Dorm lot
		- it enters lot 1, and need to traverse thorough lot 2 and 3 before it gets to Dorm.  This
			should increment and decrement the lots that the car is traveling through.  When it gets to 
			Dorm it need to check to see if its full.  If it is, it leaves that lot and tries the adjacent 
			lot, lot3, and must again trigger the increment/decrement.  
		- this problem doesn't apply to Open lot and is easily solved in LotGroupB (Maint and Overflow) but is a concern in
			LotGroupA(Admin, Lot1, Lot2, Lot3, Dorm)
		- I think it could be done with an int array[4] that takes the enum lot names returned from ParkingIntent.  It could check 
			each one and then specify a route.  

		- I have an idea how to implement this but I have to go to work.  I should be able to get it done tonight.  
			
	*/
{
	switch (lot)
	{
	case 1:
		Admin.ChangeTotals("Admin", status, time);
		break;
	case 2:
		Lot1.ChangeTotals("Lot 1", status, time);
		break;
	case 3:
		Lot2.ChangeTotals("Lot 2", status, time);
		break;
	case 4:
		Lot3.ChangeTotals("Lot 3", status, time);
		break;
	case 5:
		Dorm.ChangeTotals("Dorm", status, time);
		break;
	case 6:
		Maint.ChangeTotals("Maintenance", status, time);
		break;
	case 7:
		Overflow.ChangeTotals("Overflow", status, time);
		break;
	case 8:
		Open.ChangeTotals("Open", status, time);
		break;
	}

}







