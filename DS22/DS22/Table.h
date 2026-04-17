#pragma once
#include <iostream>
using namespace std;
class Table
{
private:
	int ID;
	int Capacity;
	int FreeSeats;
public:
	Table(int id, int cap);

	int getID() const;
	int getCapacity() const;
	int getFreeSeats() const;

	void reservetable(int seats);
	void releasetable(int seats);
	void resettable();

	bool canfit(int seats);
	bool isFull();
	bool isEmpty();

	void PrintTable();
	friend ostream& operator<< (ostream& Out, const Table& T);

};

