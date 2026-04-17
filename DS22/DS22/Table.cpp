#include "Table.h"
#include <iostream>
using namespace std;

Table::Table(int id, int cap)
{
	ID = id;
	Capacity = cap;
	FreeSeats = cap;
}

int Table::getID() const
{
	return ID;
}

int Table::getCapacity() const
{
	return Capacity;
}

int Table::getFreeSeats() const
{
	return FreeSeats;
}

void Table::reservetable(int seats)
{
	if (seats <= FreeSeats)
		FreeSeats = FreeSeats - seats;
}

void Table::releasetable(int seats)
{
	if (FreeSeats + seats <= Capacity)
		FreeSeats = FreeSeats + seats;
}

void Table::resettable()
{
	FreeSeats = Capacity;
}

bool Table::canfit(int seats)
{
	return FreeSeats >= seats;
}

bool Table::isFull()
{
	return FreeSeats == 0;
}

bool Table::isEmpty()
{
	return FreeSeats == Capacity;
}

void Table::PrintTable()
{
	cout << "[T" << ID << "," << Capacity << "," << FreeSeats << "]";
}

ostream& operator<< (ostream& Out, const Table& T) {
	Out << "[T" << T.getID() << "," << T.getCapacity() << "," << T.getFreeSeats() << "]";
	return Out;
}