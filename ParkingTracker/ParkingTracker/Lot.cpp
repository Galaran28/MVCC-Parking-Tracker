#include "Lot.h"

using namespace std;

Lot::Lot(int size)//constructor that stores the intial maxsize of the lot
{
	maxSize = size;
}

int Lot::getCurrentSize()//get the current size of the lot
{
	return currentSize;
}

int Lot::getMaxSize()//return the current max size of the lot
{
	return maxSize;
}

void Lot::Add()//add to current size
{
	++currentSize;
}

void Lot::Subtract()//subtract from current size
{
	--currentSize;
}

void Lot::PercentageFull()//get the percentage full
{ 
	percentage = (getCurrentSize()/getMaxSize()) * 100;
}

bool Lot::IsFull()//see if the lot is full
{
	if (currentSize == maxSize)
		return true;
	else
		return false;
}

double Lot::getPercentage()
{
	return percentage;//return the percentage
}

void Lot::ChangeTotals(string lot, int status, string time)
{
	if (status == 1)//if parking
			{
				Add();//add the car initially
				if (!(IsFull()))
					LogChange(lot, 1, time); //if room, the car parks, outputs to the log
				else
				{
					LogChange(lot, 0, time);//output if car can't find a spot to the log
					status = 0;//change status 
				}
			}
	if (status == 0)//hopefully this will catch if the status changed
			{
				Subtract();//subtract a car from the lot
				LogChange(lot, 2, time);//output if car leaves
			}
}

void Lot::LogChange(string lot, int status, string time)//logging function
{
	ofstream log;//creat the log object
	log.open ("log20122012201220122012.txt", ios::app);//open file for editing
	if (status == 1)//if the car parks
		log << time << " :: car parks in " << lot << " lot"  << endl;
	else if (status == 0)//if the car leaves
		log << time << " :: car leaves " << lot << " lot" << endl;
	else if (status == 2)//if the car can't find a spot
		log << time << " :: car can't find a parking spot" << endl;
	log.close();

}