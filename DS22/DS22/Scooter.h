#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "GenericDefs.h"

class Scooter
{
	
private:

	int ID;
	int Speed;
	int MainDuration;
	int OrdersCount;
	int maxOrdersBeforeMain;
	Status status;



public:
	Scooter(int id, int s, int maind, int maxorders);

	int getID() const;
	int getOrdersCount() const;
	int getSpeed() const;
	string getStatus() const;

	void AssignScooter();
	void FinishDel();
	void Return();


	void SendToMain();
	bool NeedMain();
	void FinishMain();

	void PrintScooter();
	friend ostream& operator<<(ostream& Out, const Scooter& S);



};

