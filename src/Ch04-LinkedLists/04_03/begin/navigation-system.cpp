#include <iostream>
#include <list>
using namespace std;

class Route
{
private:
  list<string> stopStations;
  list<string>::iterator current;

public:
  Route()
  {
    current = stopStations.end();
  }

  void addStop(const string &stop)
  {
    stopStations.push_back(stop);

    // if it is the first stop to add
    if (current == stopStations.end())
    {
      current = stopStations.begin();
    }

    cout << "stop station \"" << stop << "\" is added to the route.\n";
  }

  void nextStop()
  {
    if (!stopStations.empty())
    {
      // instead of "advance()", you can use "current++"
      advance(current, 1);
      if (current == stopStations.end())
      {
        current = stopStations.begin();
      }
    }
  }

  void prevStop()
  {
    if (!stopStations.empty())
    {
      if (current == stopStations.begin())
      {
        current = stopStations.end();
      }
      advance(current, -1);
    }
  }

  string currentStop()
  {
    if (!stopStations.empty())
    {
      return *current;
    }
    else
    {
      return "No stops in the route.";
    }
  }
};

int main()
{
  Route stopStation;
  stopStation.addStop("1");
  stopStation.addStop("2");
  stopStation.addStop("3");

  cout << "\nCurrent stop is: " << stopStation.currentStop();

  stopStation.prevStop();
  cout << "\nCurrent stop is: " << stopStation.currentStop();

  stopStation.nextStop();
  cout << "\nCurrent stop is: " << stopStation.currentStop();

  stopStation.nextStop();
  cout << "\nCurrent stop is: " << stopStation.currentStop();

  stopStation.nextStop();
  cout << "\nCurrent stop is: " << stopStation.currentStop();

  stopStation.nextStop();
  cout << "\nCurrent stop is: " << stopStation.currentStop() << endl;

  return 0;
}
