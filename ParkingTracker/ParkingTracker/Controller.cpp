#include <iostream>
#include "Lot.h"
#include "randHead.h"
#include <fstream>
#include "Car.h"
#include <string>
#include <sstream>//needed to take care of istringstream line
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

//void ChangeTotals(int, int, int);//function previews
//void LogChange(int, int, int, int);
void LotChooser(int, int, string);
int FindSpot(enum lotname, enum lotname);
int GoHome(int);
//enum names LotGroup(enum names entrance);
bool LotGroup1Full();
bool LotGroup2Full();
bool AllLotsFull();
int AllLotsTotal();
void PrintLots();
enum names unFullEntrance(enum lotname);
//sensors between lots functions
void AdminToLot1();
void Lot1ToAdmin();

void Lot1ToLot2();
void Lot2ToLot1();

void Lot1ToLot3();
void Lot3ToLot1();

void DormToLot2();
void Lot2ToDorm();

void OverflowToMaint();
void MaintToOverflow();
// used same enum type (names) for lots and entrances so recursion would be possible
enum names { mall, //go to mall
			 admin, lot1, lot2, lot3, dorm, open, maint, overflow, //lot names
			 shermanA, shermanB, armory, tildenA, tildenB, //entrance names
			 lotGroupA, lotGroupB // group names
			};	

string enumNames[16] = {"Mall",//mall
						"Admin", "Lot 1", "Lot2", "Lot3", "Dorm", "Open", "Maint", "Overflow", //lots
						"Sherman A", "Sherman B", "Armory", "Tilden A", "Tilden B", //entrances
						"Lot Group A", "Lot Group B"};//group names

int leaving();

//void LogChange(int, int, int);

Lot Mall(10000);
Lot Admin(40);//create instace of lot class for each lot, 
Lot Lot1(500);//starting maxSize is arg
Lot Lot2(600);
Lot Lot3(200);
Lot Dorm(150);
Lot Open(500);
Lot Maint(200);
Lot Overflow(300);

int round(double);
int round(double a)
{
	return (a+.5);
}

void PrintLots()//prints how many cars are currently in lots
{
	Admin.PercentageFull();
	Lot1.PercentageFull();
	Lot2.PercentageFull();
	Lot3.PercentageFull();
	Dorm.PercentageFull();
	Open.PercentageFull();
	Maint.PercentageFull();
	Overflow.PercentageFull();
	cout<<"Lot         Free Spots   Percent Full"<<endl;
	cout << enumNames[1] <<setfill(' ')<<setw (13) << Admin.getRemainingSpots() << setfill(' ') << setw (13) << round(Admin.getPercentage()) <<endl;
	cout << enumNames[2] << setfill(' ')<<setw (13) << Lot1.getRemainingSpots() << setfill(' ') << setw (13) <<round(Lot1.getPercentage()) <<endl;
	cout << enumNames[3] << setfill(' ')<<setw (14) << Lot2.getRemainingSpots() << setfill(' ') << setw (13) << round(Lot2.getPercentage()) <<endl;
	cout << enumNames[4] << setfill(' ')<<setw (14) << Lot3.getRemainingSpots() << setfill(' ') << setw (13) << round(Lot3.getPercentage()) <<endl;
	cout << enumNames[5] << setfill(' ')<<setw (14) << Dorm.getRemainingSpots() << setfill(' ') << setw (13) << round(Dorm.getPercentage()) <<endl;
	cout << enumNames[6] << setfill(' ')<<setw (14) << Open.getRemainingSpots() << setfill(' ') << setw (13) << round(Open.getPercentage()) <<endl;
	cout << enumNames[7] << setfill(' ')<<setw (13) << Maint.getRemainingSpots() << setfill(' ') << setw (13) << round(Maint.getPercentage()) <<endl;
	cout << enumNames[8] << setfill(' ')<<setw (10) << Overflow.getRemainingSpots() << setfill(' ') << setw (13) << round(Overflow.getPercentage()) <<endl;
	cout << Mall.getCurrentSize() << " students total gave up and went to the mall"<<endl;
}

//Between-lot sensors simulation
void AdminToLot1()
{
	Admin.Subtract();
	Lot1.Add();
}
void Lot1ToAdmin()
{
	Lot1.Subtract();
	Admin.Add();
}
void Lot1ToLot2()
{
	Lot1.Subtract();
	Lot2.Add();
}
void Lot2ToLot1()
{
	Lot2.Subtract();
	Lot1.Add();
}
void Lot1ToLot3()
{
	Lot1.Subtract();
	Lot3.Add();
}
void Lot3ToLot1()
{
	Lot3.Subtract();
	Lot1.Add();
}
void DormToLot2()
{
	Dorm.Subtract();
	Lot2.Add();
}
void Lot2ToDorm()
{
	Lot2.Subtract();
	Dorm.Add();
}
void OverflowToMaint()
{
	Overflow.Subtract();
	Maint.Add();
}
void MaintToOverflow()
{
	Maint.Subtract();
	Overflow.Add();
}

/*enum names LotGroup(enum names entrance)
{
	if (entrance >=10 && entrance <= 12)
	return lotGroupA;
	else if (entrance == 13)
	return lotGroupB;
	else if (entrance == 9)
	return open;
}
*/
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

int AllLotsTotal()
{
	return
	Admin.getCurrentSize()+
	Lot1.getCurrentSize()+
	Lot2.getCurrentSize()+
	Lot3.getCurrentSize()+
	Dorm.getCurrentSize()+
	Open.getCurrentSize()+
	Maint.getCurrentSize()+
	Overflow.getCurrentSize();
}

enum names unFullEntrance(enum names entrance)
//returns an entrance with attached available parking
{
	if (entrance == shermanA)						//Wants to enter at Sherman A			
	{
		if (!Open.IsFull())							//If Open lot isn't full
		{
			return shermanA;							//enters at Sherman A
		}
		else	
		{											
			if (!LotGroupAFull())					//If Open lot is full
				return unFullEntrance(shermanB);		//tries to enter at Sherman B, recursion

			else if (!LotGroupBFull())				//If Sherman B is full 
				return unFullEntrance(tildenB);		//tries to enter at Tilden B, recursion

			else
				return mall;						//heads to Mall			
			
		}
	}
	else if (entrance == shermanB)	//Wants to enter at Sherman B
	{
		if (!LotGroupAFull())		//If attached lots aren't full
		{
			return shermanB;	
		}
		else									
			if(!Open.IsFull())					//If attached lots are full
				return unFullEntrance(shermanA);	//Tries to enter at Sherman A (Open lot)

			else if (!LotGroupBFull())			//If Open lot is full
				return unFullEntrance(tildenB);	//Tries to enter at tolden B

			else return mall;					//heads to mall
	}
	else if (entrance == armory)	//Wants to enter at Armory
	{
		if (!LotGroupAFull())
		{
			return armory;		//heads to Dorm lot
		}
		else
		{
			if (!LotGroupBFull())				//if attached lots are full (LotGroupA)
				return unFullEntrance(tildenB);	//Tries to enter at tilden B

			else if(!Open.IsFull())				//If attached lots are full	(LotGroupB)							
				return unFullEntrance(shermanA);	//Tries to enter at Sherman A (Open lot)
			else
				return mall;					//heads to mall
		}

	}

	else if (entrance == tildenA)	//Wants to enter at Tilden A
	{
		if (!LotGroupAFull())
		{
			return tildenA;		//heads to Dorm
		}
		else
		{
			if (!LotGroupBFull())				//if attached lots are full (LotGroupA)
				return unFullEntrance(tildenB);	//Tries to enter at tilden B

			else if(!Open.IsFull())				//If attached lots are full	(LotGroupB)							
				return unFullEntrance(shermanA);	//Tries to enter at Sherman A (Open lot)
			else
				return mall;					//heads to mall


		}
	}
	else if (entrance == tildenB)	//Wants to enter at Tilden B
	{
		if (!LotGroupBFull())	
		{
			return tildenB;
		}
		else
		{
			if (!LotGroupAFull())				//If attached lots are full	(LotGroupB)	
				return unFullEntrance(armory);	//Tries to enter at Armory

			else if(!Open.IsFull())				//If attached lots are full	(LotGroupA)							
				return unFullEntrance(shermanA);	//Tries to enter at Sherman A (Open lot)

			else
				return mall;					//heads to mall

		}
	}	


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
		{
			return open;							//heads to Open lot
		}
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

int FindSpot(enum names entrance, enum names destination)
{//takes destination from ParkingIntent
	//it is assumed that a spot is available in an attached lot
	//if a car was able to enter
	if (entrance == tildenA || entrance == shermanB || entrance == armory)
	{
		switch(entrance)
		{
		case tildenA:
			switch(destination)
			{
				case dorm:
					Dorm.Add();//Drives in Dorm
					if (Dorm.OverFull())		//if car + currentSize > maxSize
					{
						DormToLot2();		//drives to lot2
						if (Lot2.OverFull())
						{							//searches for spot in remaining attached lots
							Lot2ToLot1();
							if (Lot1.OverFull())
							{						//searches for spot in remaining attached lots
								Lot1ToLot3();
								if (Lot3.OverFull())
								{					//parks in admin (last remaining lot)
									Lot3ToLot1();
									Lot1ToAdmin();	
									return admin;
								}
								return lot3;
							}
							return lot1;
						}
						return lot2;
					}
					return dorm;
					break;
				case lot2:
					Lot2.Add();
					if (Lot2.OverFull())
					{
						Lot2ToDorm();
						if(Dorm.OverFull())
						{
							DormToLot2();
							Lot2ToLot1();
							if (Lot1.OverFull())
							{
								Lot1ToLot3();
								if (Lot3.OverFull())
								{	
									Lot3ToLot1();
									Lot1ToAdmin();
									return admin;
								}
								return lot3;	
							}
							return lot1;
						}
						return dorm;
					}
					return lot2;
					break;
				case lot1:
					Lot2.Add();  //drives through lot 2
					Lot2ToLot1();//to park in lot 1
					if (Lot1.OverFull())
					{
						Lot1ToLot3();
						if (Lot3.OverFull())
						{
							Lot3ToLot1();
							Lot1ToLot2();
							if (Lot2.OverFull())
							{
								Lot2ToDorm();
								if (Dorm.OverFull())
								{
									DormToLot2();
									Lot2ToLot1();
									Lot1ToAdmin();
									return admin;
								}
								return dorm;									
							}
							return lot2;
						}
						return lot3;
					}
					return lot1;
					break;
				case lot3:
					Lot2.Add();  //drives through lot 2
					Lot2ToLot1();//and drives through lot 1
					Lot1ToLot3();//to park in lot 3
					if (Lot3.OverFull())
					{
						Lot3ToLot1();
						if (Lot1.OverFull())
						{
							Lot1ToLot2();
							if (Lot2.OverFull())
							{
								Lot2ToDorm();
								if (Dorm.OverFull())
								{
									DormToLot2();
									Lot2ToLot1();
									Lot1ToAdmin();
									return admin;
								}
								return dorm;
							}
							return lot2;
						}
						return lot1;
					}
					return lot3;
					break;
				}
			break;
		case armory:
			switch(destination)
			{
				case lot3:
					Lot3.Add();
					if (Lot3.OverFull())
					{
						Lot3ToLot1();
						if (Lot1.OverFull())
						{
							Lot1ToLot2();
							if (Lot2.OverFull())
							{
								Lot2ToDorm();
								if (Dorm.OverFull())
								{
									DormToLot2();
									Lot2ToLot1();
									Lot1ToAdmin();
									return admin;
								}
								return dorm;
							}
							return lot2;
						}
						return lot1;
					}
					return lot3;
					break;
				case lot2:
					Lot3.Add();
					Lot3ToLot1();
					Lot1ToLot2();
					if (Lot2.OverFull())
					{
						Lot2ToDorm();
						if (Dorm.OverFull())
						{
							DormToLot2();
							Lot2ToLot1();
							if (Lot1.OverFull())
							{
								Lot1ToLot3();
								if (Lot3.OverFull())
								{
									Lot3ToLot1();
									Lot1ToAdmin();
									return admin;
								}
								return lot3;
							}
							return lot1;
						}
						return dorm;
					}
					return lot2;
					break;
				case lot1:
					Lot3.Add();
					Lot3ToLot1();
					if (Lot1.OverFull())
					{
						Lot1ToLot3();
						if (Lot3.OverFull())
						{
							Lot3ToLot1();
							Lot1ToLot2();
							if (Lot2.OverFull())
							{
								Lot2ToDorm();
								if(Dorm.OverFull())
								{
									DormToLot2();
									Lot2ToLot1();
									Lot1ToAdmin();
									return admin;
								}
								return dorm;
							}
							return lot2;
						}
						return lot3;
					}
					return lot1;
					break;
				case dorm:
					Lot3.Add();
					Lot3ToLot1();
					Lot1ToLot2();
					Lot2ToDorm();
					if (Dorm.OverFull())
					{
						DormToLot2();
						if (Lot2.OverFull())
						{
							Lot2ToLot1();
							if (Lot1.OverFull())
							{
								Lot1ToLot3();
								if (Lot3.OverFull())
								{
									Lot3ToLot1();
									Lot1ToAdmin();
									return admin;
								}
								return lot3;
							}
							return lot1;
						}
						return lot2;
					}
					return dorm;
					break;
			}//destination
			break;
		case shermanB:
			switch(destination)
			{
				case admin:
					Admin.Add();
					if (Admin.OverFull())
					{
						AdminToLot1();
						if (Lot1.OverFull())
						{
							Lot1ToLot3();
							if (Lot3.OverFull())
							{
								Lot3ToLot1();
								Lot1ToLot2();
								if (Lot2.OverFull())
								{
									Lot2ToDorm();
									return dorm;
								}
								return lot2;
							}
							return lot3;
						}
						return lot1;
					}
					return admin;
					break;
				case lot1:
					Lot1.Add();
					if (Lot1.OverFull())
					{
						Lot1ToLot3();
						if (Lot3.OverFull())
						{
							Lot3ToLot1();
							Lot1ToLot2();
							if(Lot2.OverFull())
							{
								Lot2ToDorm();
								if(Dorm.OverFull())
								{	
									DormToLot2();
									Lot2ToLot1();
									Lot1ToAdmin();
									return admin;
								}
								return dorm;
							}
							return lot2;
						}
						return lot3;
					}
					return lot1;
					break;
				case lot3:
					Lot1.Add();
					Lot1ToLot3();
					if (Lot3.OverFull())
					{
						Lot3ToLot1();
						if (Lot1.OverFull())
						{
							Lot1ToLot2();
							if (Lot2.OverFull())
							{
								Lot2ToDorm();
								if (Dorm.OverFull())
								{
									DormToLot2();
									Lot2ToLot1();
									Lot1ToAdmin();
									return admin;
								}
								return dorm;
							}
							return lot2;
						}
						return lot1;
					}
					return lot3;
					break;
				case lot2:
					Lot1.Add();
					Lot1ToLot2();
					if (Lot2.OverFull())
					{
						Lot2ToDorm();
						if (Dorm.OverFull())
						{
							DormToLot2();
							Lot2ToLot1();
							if (Lot1.OverFull())
							{
								Lot1ToLot3();
								if (Lot3.OverFull())
								{
									Lot3ToLot1();
									Lot1ToAdmin();
									return admin;
								}
								return lot3;
							}
							return lot1;
						}
						return dorm;
					}
					return lot2;
					break;
				case dorm:
					Lot1.Add();
					Lot1ToLot2();
					Lot2ToDorm();
					if (Dorm.OverFull())
					{
						DormToLot2();
						if (Lot2.OverFull())
						{
							Lot2ToLot1();
							if (Lot1.OverFull())
							{
								Lot1ToLot3();
								if (Lot3.OverFull())
								{
									Lot3ToLot1();
									Lot1ToAdmin();
									return admin;
								}
							return lot3;
							}
							return lot1;
						}
						return lot2;
					}
					return dorm;
					break;
			}
			break;//destination
		}//entrance
	}//lotgroup A
	else if (entrance == shermanA)
	{
		Open.Add();
		return open;
	}
	else if (entrance == tildenB)
	{
		Maint.Add(); //drives into Maint lot
		if ((destination == overflow)||(Maint.OverFull()))
		{	
			MaintToOverflow();
			if (Overflow.OverFull())
			{
				OverflowToMaint();
				return maint;
			}
		return overflow;
		}
	}
}

int GoHome(int lot)
{
	//takes lot to leave from
	//if lot is already empty, choses the next lot
	if (AllLotsTotal() > 0)
	{
		switch(lot)
		{
		case admin:
			if (!Admin.IsEmpty())
			{
				Admin.Subtract();
				return admin;
			}
			else
				GoHome(lot1);
			break;
		case lot1:
			if (!Lot1.IsEmpty())
			{
				Lot1.Subtract();
				return lot1;
			}
			else
				GoHome(lot2);
			break;
		case lot2:
			if (!Lot2.IsEmpty())
			{
				Lot2.Subtract();
			return lot2;
			}
			else
				GoHome(lot3);
			break;
		case lot3:
			if (!Lot3.IsEmpty())
			{	
				Lot3.Subtract();
				return lot3;
			}
			else
				GoHome(dorm);
			break;
		case dorm:
			if (!Dorm.IsEmpty())
			{
				Dorm.Subtract();
				return dorm;
			}
			else
				GoHome(open);
			break;
		case open:
			if (!Open.IsEmpty())
			{
				Open.Subtract();
				return open;
			}
			else
				GoHome(maint);
			break;
		case maint:
			if (!Maint.IsEmpty())
			{
				Maint.Subtract();
				return maint;
			}
			else
				GoHome(overflow);
			break;
		case overflow:
			if (!Overflow.IsEmpty())
			{
				OverflowToMaint();
				Maint.Subtract();
				return overflow;
			}
			else
				GoHome(admin);
			break;
		}
	}
}
/*
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
*/



int main()
{
	int lot, status, time;//declare variables that are the args for ChangeTotals
	string line, sLot, sStatus, sTime;//strings for reading and eventual conversion to int

	
	//rand.generateCars(); //genertates number of cars going to each entrance
	
	/*  I didn't know how or why to implement this
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
	}	*/
	int hours, hour;
	int mall = 0;
	int count = 0;
	randHead rand;
	cout<<"Enter number of hours to run Simulation"<<endl;
	cin>>hours;
	
	for(hour = 0; hours >= hour; hour++)//hours of simulation
{
	int incars = rand.generateCars(hour);//each hour generates number coming in
	int outcars = rand.generateLeaving(hour);//and number going out
	for(outcars; outcars > 0; --outcars)//for every car going home
	{
		int spot = GoHome(rand.leavingLot());// decides where its leaving from and route it drives outs
		//LogChange(spot, 0, hour);
	}
	for(incars; incars > 0; --incars)//for each car generated
	{	
		int spot = 0;//eventual location of parking spot
		int input = rand.distributeCars(); //assign an entrance based on percentages
		int intent = ParkingIntent((names)input);//returns entrance (for logging?)
		if (unFullEntrance((names)input) != mall)
		spot = FindSpot(unFullEntrance((names)input), ParkingIntent((names)input));	//returns parking lot parked in
		else
			Mall.Add();//to the mall with you!
	}

	cout<<"Hour = "<<hour<<endl;//prints once an hour
	PrintLots();
	cout<<endl;
}
	

	return 0;
}