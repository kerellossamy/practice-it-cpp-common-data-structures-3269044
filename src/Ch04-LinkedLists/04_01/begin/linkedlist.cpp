#include <iostream>
#include <list>
using namespace std;

void printList(list<int> &intList)
{
  for (int &element : intList)
  {
    cout << element << " ";
  }
  cout << endl;
}

int main()
{
  list<int> intList = {1, 2, 3, 4, 5};
  intList.push_back(6);
  intList.push_front(0);

  auto it = intList.begin();
  advance(it, 2);
  intList.insert(it, -1);

  cout << "List in forward direction: ";
  printList(intList);

  intList.pop_back();
  intList.pop_front();
  cout << "List in forward direction after we pop the front and back element: ";
  printList(intList);

  intList.reverse();
  cout << "List after reversing: ";
  printList(intList);

  intList.sort();
  cout << "List after sorting: ";
  printList(intList);

  return 0;
}
