#include "Restaurant.h"

Restaurant::Restaurant()
{}

void Restaurant::AddOrder(Order* O)
{
    ORD_TYPE type = O->Get_Type();
    switch (type) {
    case ODN:
        Pending_ODN.enqueue(O);
        break;
    case ODG:
        Pending_ODG.enqueue(O);
        break;
    case OT:
        Pending_OT.enqueue(O);
        break;
    case OVN:
        Pending_OVN.enqueue(O);
        break;
    case OVC:
        Pending_OVC.enqueue(O);
        break;
    case OVG:
    {
        int price = O->Get_Price();
        int size = O->Get_Size();
        float distance = O->Get_Distance();
        int tq = O->Get_TQ();

        int priority = (price * 10) - (distance * 2) - (size * 1) - (tq * 5); //The Equation of piriorety
        Pending_OVG.enqueue(O, priority);
        break;

    }
    }


}

bool Restaurant::CancelOrder(int id)
{  
    bool isFound = Pending_OVC.CancelOrder(id);

    if (!isFound) {
        return false;
    }
    return true;
}

void Restaurant::Print_PendingOrders() 
{
    cout << "Pending Orders : " << endl;
    cout << "Normal Dine-in (ODN): ";
    Pending_ODN.Print();

    cout << "\n Special Dine-in (ODG): ";
    Pending_ODG.Print();

    cout << "\n Take Away orders (OT): ";
    Pending_OT.Print();

    cout << "\n Normal Delivery Orders(OVN): ";
    Pending_OVN.Print();

    cout << "\n Cold Delivery Orders(OVC): ";
    Pending_OVC.Print();
    

    cout << "\n Grilled Delivery Orders (OVG): ";
    Pending_OVG.print();


}

void Restaurant::PrintChefs()
{
    cout << "Chefs Status : " << endl;

    cout << "Normal Chefs (CN): ";
    Chef_N.Print(); 
    cout << endl;

    cout << "Special Chefs (CS): ";
    Chef_S.Print();
    cout << endl;


}

Restaurant::~Restaurant()
{
    Order* pOrd;
    Chefs* pChef;
    Action* pAct;
    Table* pTable;
    Scooter* pScooter;

    //Delete the Actions
    while (Request.dequeue(pAct)) { delete pAct; }
    while (Cancellation.dequeue(pAct)) { delete pAct; }

    //Delete the Chefs
    while (Chef_N.dequeue(pChef)) { delete pChef; }
    while (Chef_S.dequeue(pChef)) { delete pChef; }

    //Delete the tables
    while (Free_Tables.dequeue(pTable)) { delete pTable; }
    while (Busy_Sharable.dequeue(pTable)) { delete pTable; }
    while (Busy_No_Share.dequeue(pTable)) { delete pTable; }

    //Delete the Scooter
    while (Free_Scot.dequeue(pScooter)) { delete pScooter; }
    while (Back_Scot.dequeue(pScooter)) { delete pScooter; }
    while (Maint_Scot.dequeue(pScooter)) { delete pScooter; }

    //Delete The All Orders

    // 1 - Pending Orders
    while (Pending_ODN.dequeue(pOrd)) { delete pOrd; }
    while (Pending_ODG.dequeue(pOrd)) { delete pOrd; }
    while (Pending_OT.dequeue(pOrd)) { delete pOrd; }
    while (Pending_OVN.dequeue(pOrd)) { delete pOrd; }
    while (Pending_OVG.dequeue(pOrd)) { delete pOrd; }
    while (Pending_OVC.dequeue(pOrd)) { delete pOrd; } 

    // 2 - Cooking & In-Service
    while (Cook_O.dequeue(pOrd)) { delete pOrd; }
    while (Inserv_O.dequeue(pOrd)) { delete pOrd; }

    // 3 - Ready Orders
    while (Ready_OD.dequeue(pOrd)) { delete pOrd; }
    while (Ready_OT.dequeue(pOrd)) { delete pOrd; }
    while (Ready_OV.dequeue(pOrd)) { delete pOrd; }

    // 4 - Finished Orders 
    while (Finished_O.pop(pOrd)) { delete pOrd; }




}



