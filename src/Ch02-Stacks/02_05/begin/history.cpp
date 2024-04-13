#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BrowserHistory
{
private:
  stack<string> history;

public:
  void visit(const string &url)
  {
    cout << "Visiting " << url << endl;
    history.push(url);
  }

  void back()
  {
    cout << "Navigating back" << endl;
    if (!history.empty())
    {
      history.pop();
    }
  }

  string current()
  {
    if (!history.empty())
    {
      return history.top();
    }

    return "No sites currently being viewed.";
  }
};

int main()
{
  BrowserHistory history;
  history.visit("www.google.com");
  history.visit("www.youtube.com");
  history.visit("www.twitter.com");

  cout << "\nCurrent site: " << history.current() << endl
       << endl;

  history.back();
  cout << "Current site: " << history.current() << endl
       << endl;

  history.visit("www.facebook.com");
  cout << "Current site: " << history.current() << endl
       << endl;

  history.back();
  cout << "Current site: " << history.current() << endl;

  return 0;
}
