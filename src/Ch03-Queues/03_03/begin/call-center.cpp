#include <iostream>
#include <queue>
using namespace std;

class CallCenter
{
private:
  queue<int> callQueue;
  static int id;

public:
  void receiveCall()
  {
    id++;
    callQueue.push(id);
    cout << "Received call with ID: " << id << "\n";
  }

  int processCall()
  {
    if (!callQueue.empty())
    {
      int callID = callQueue.front();
      callQueue.pop();
      return callID;
    }
    else
    {
      return -1;
    }
  }
};
int CallCenter::id = 0;

int main()
{

  CallCenter customers;

  customers.receiveCall();
  customers.receiveCall();
  customers.receiveCall();
  customers.receiveCall();
  customers.receiveCall();

  int callID;

  while ((callID = customers.processCall()) != -1)
  {
    cout << "\nSuccessfully processed call: " << callID;
  }

  cout << "\n\nNo calls to process." << endl;

  return 0;
}
