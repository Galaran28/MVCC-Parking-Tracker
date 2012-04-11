#include "Car.h"
using namespace std;

Car::Car(int input) //takes status 1 = parking, 0 ==leaving
{
	status = input;
}

void Car::SetEntrance(int input)
{
	entrance == input;
}

void Car::SetDestination(int input)
{
	destination == input;
}

int Car::GetDestination()
{
	return destination;
}

int Car::GetEntrance()
{
	return entrance;
}

int Car::GetStatus()
{
	return status;
}