#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(const string &input)
{
  stack<char> charStack;

  for (char c : input)
  {
    charStack.push(c);
  }

  string reversedString = "";

  while (!charStack.empty())
  {
    reversedString += charStack.top();
    charStack.pop();
  }

  return reversedString;
}

int main()
{
  string str = "Hello, World!";
  string reversedStr = reverseString(str);

  cout << "Original String: " << str << endl;
  cout << "Reversed String: " << reversedStr << endl;

  return 0;
}
