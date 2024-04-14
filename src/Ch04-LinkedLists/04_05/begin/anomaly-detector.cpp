#include <iostream>
#include <list>
using namespace std;

class SensorData 
{
private:
    list<double> readings;

public:
    void addReading(double value)
    {
        readings.push_back(value);
    }

    void smoothData()
    {
        if (readings.size() > 1)
        {
            list<double>::iterator prev = readings.begin();

            list<double>::iterator current = prev;
            current++;

            while (current != readings.end())
            {
                double prevData = *prev;
                double currentData = *current;

                //check spike or dip
                if ((currentData >= 2 * prevData) || (currentData <= prevData / 2))
                {
                    *current = *prev;
                }

                prev++;
                current++;
            }
        }
    }

    void printData()
    {
        cout << "The readings are: ";
        for (double &element: readings )
        {
            cout << element << " ";
        }
    }
};

int main()
{
    SensorData sensorData;
    sensorData.addReading(10.0);
    sensorData.addReading(24.0);   // spike
    sensorData.addReading(6.0);
    sensorData.addReading(2.0);    // dip
    sensorData.addReading(4.0);

    cout << "Before smoothing the data\n";
    sensorData.printData();


    cout << "\n\nAfter smoothing the data\n";
    sensorData.smoothData();
    sensorData.printData();
    
    return 0;
}
