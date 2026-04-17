#pragma once
#include "LinkedQueue.h"
#include "Action.h"
#include "LinkedPriorityQueue.h"
#include "Order.h"
#include "ArrayStack.h"
#include "Chefs.h"
#include "CancelQueue.h"
#include "TablePriQueue.h"
#include "Table.h"
#include "Scooter.h"


class Restaurant
{
private:
	//Action Lists: 
	LinkedQueue<Action*>   Request;
	LinkedQueue<Action*>  Cancellation;  //For Phase 2
	

	//Pending Orders :
	
	//The Dine_in Orders Lists --> 2
	LinkedQueue<Order*> Pending_ODN;
	LinkedQueue<Order*> Pending_ODG;
	//The Takeaway Orders --> 1
	LinkedQueue<Order*> Pending_OT;
	//The Delivery Orders --> 3
	LinkedQueue<Order*> Pending_OVN;
	LinkedPriorityQueue<Order*>  Pending_OVG; //Grilled
	CancelQueue<Order*>  Pending_OVC;  //Cold orders


	//The Chefs :
	LinkedQueue<Chefs*>  Chef_N;
	LinkedQueue<Chefs*>  Chef_S;


	//The Tables :
	TablePriQueue<Table*> Free_Tables;
	TablePriQueue<Table*> Busy_Sharable;
	TablePriQueue<Table*> Busy_No_Share;


	//The Ready Orders :
	LinkedQueue<Order*>  Ready_OD;
	LinkedQueue<Order*>  Ready_OT;
	CancelQueue<Order*>  Ready_OV;  //Available to cancel the Order


	//Finished Orders :
	ArrayStack<Order*>  Finished_O;


	//The Scooters :  -->3
	LinkedPriorityQueue<Scooter*> Free_Scot;
	LinkedPriorityQueue<Scooter*> Back_Scot;
	LinkedQueue<Scooter*> Maint_Scot;


	//Cooking Orders : 
	CancelQueue<Order*> Cook_O;


	//Insevise Orders :
	LinkedPriorityQueue<Order*>  Inserv_O;


public:

	void AddOrder(Order* O);
	bool CancelOrder(int id);

	//To print the information
	void Print_PendingOrders() ;
	void PrintChefs() ;
	
	~Restaurant();
	Restaurant();


};

