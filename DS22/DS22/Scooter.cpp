#include <iostream>
using namespace std;
#include <string>
#include "Scooter.h"

Scooter::Scooter(int id, int s, int maind, int maxorders)
{
	ID = id;
	Speed = s;
	MainDuration = maind;
	maxOrdersBeforeMain = maxorders;
	status = AVAILABLE;
	OrdersCount = 0;
}

int Scooter::getID() const
{
	return ID;
}

int Scooter::getOrdersCount() const
{
	return OrdersCount;
}

int Scooter::getSpeed() const
{
	return Speed;
}

string Scooter::getStatus() const
{
	switch (status) {
	case AVAILABLE:
		return "Available";
	case IN_SERVICE:
		return "InService";
	case IN_MAINTENANCE:
		return "Maintenance";
	case BACK:
		return "Back";
	default:
		return "Available";
	}
}


void Scooter::AssignScooter()
{
	if (status == AVAILABLE) {
		status = IN_SERVICE;
		OrdersCount++;
	}
}

void Scooter::FinishDel()
{
	status = BACK;
}

void Scooter::Return()
{
	status = AVAILABLE;
}

void Scooter::SendToMain()
{
	status = IN_MAINTENANCE;
}

bool Scooter::NeedMain()
{
	return OrdersCount >= maxOrdersBeforeMain;
}

void Scooter::FinishMain()
{
	OrdersCount = 0;
	status = AVAILABLE;
}

void Scooter::PrintScooter()
{
	cout << "[S" << ID << ", Speed=" << Speed << ", Orders=" << OrdersCount << ", status=" << getStatus() << "]";
}

ostream& operator<<(ostream& Out, const Scooter& S)
{
	Out << "[S" << S.getID() << ", Speed=" << S.getSpeed() << ", Orders=" << S.getOrdersCount() << ", status=" << S.getStatus() << "]";
	return Out;
}


