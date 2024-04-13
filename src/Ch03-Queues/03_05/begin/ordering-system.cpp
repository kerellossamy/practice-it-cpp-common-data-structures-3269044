#include <iostream>
#include <queue>
using namespace std;

class MerchOrderSystem
{
private:
    queue<int> priorityOrders, regularOrders;
    static int orderID;

public:
    void placeOrder(bool isPriority = false)
    {
        orderID++;

        if (isPriority)
        {
            priorityOrders.push(orderID);
            cout << "Placed order with ID: " << orderID << " (has priority)" << endl;
        }
        else
        {
            regularOrders.push(orderID);
            cout << "Placed order with ID: " << orderID << endl;
        }
    }

    int fulfillOrder()
    {
        if (!priorityOrders.empty())
        {
            int fulfilledOrder = priorityOrders.front();
            priorityOrders.pop();
            return fulfilledOrder;
        }

        if (!regularOrders.empty())
        {
            int fulfilledOrder = regularOrders.front();
            regularOrders.pop();
            return fulfilledOrder;
        }

        return -1;
    }
};
int MerchOrderSystem::orderID = 0;

int main()
{
    MerchOrderSystem orders;

    orders.placeOrder();
    orders.placeOrder();
    orders.placeOrder(true);
    orders.placeOrder();
    orders.placeOrder(true);
    orders.placeOrder();
    orders.placeOrder(true);

    int orderId;
    while ((orderId = orders.fulfillOrder()) != -1)
    {
        cout << "\nOrder no." << orderId << " has been fulfilled.";
    }

    cout << "\n\nAll orders are fulfilled\n";

    return 0;
}
