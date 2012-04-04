#include "Lot.h"

using namespace std;

Lot::Lot(int size)
{
	maxSize = size;
}

int Lot::getCurrentSize()
{
	return currentSize;
}

int Lot::getMaxSize()
{
	return maxSize;
}

void Lot::Add()
{
	++currentSize;
}

void Lot::Subtract()
{
	--currentSize;
}

void Lot::PercentageFull()
{ 
	percentage = (getCurrentSize()/getMaxSize()) * 100; 
}

bool Lot::IsFull()
{
	if (currentSize == maxSize)
		return true;
	else
		return false;
}

double Lot::getPercentage()
{
	return percentage;
}