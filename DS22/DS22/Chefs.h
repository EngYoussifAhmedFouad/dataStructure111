#pragma once
#include "GenericDefs.h"
#include"Order.h"




class Chefs
{
private:
	int ID;
	CHEF_TYPE Type;
	int Speed;
	Order* Hold_Order;
public:
	Chefs(int id, CHEF_TYPE T, int S);

	//getters
	int Get_ID()const;
	CHEF_TYPE Get_Type()const;
	int Get_Speed()const;
	Order* Get_Current_Order()const;

	//To setting the Order
	void Assign_Order(Order* O);

	//After Finishing Orders
	Order* Finish_Order();

	friend ostream& operator<<(ostream& C, const Chefs* Chef);

	bool Is_Avalable()const; // To chech the Avalabelity


};

