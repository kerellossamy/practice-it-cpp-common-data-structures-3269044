#include <iostream>
#include <string>
using namespace std;

template <typename T>
int findItem(const T arr[], size_t size, T target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(numbers) / sizeof(numbers[0]);
    int targetNumber = 3;
    int intIndex = findItem(numbers, intSize, targetNumber);

    if (intIndex != -1)
    {
        cout << "The number " << targetNumber << " is found at index " << intIndex << ".\n";
    }
    else
    {
        cout << "The number " << targetNumber << " is not found in the array.\n";
    }

    string food[] = {"bread", "apple", "banana", "egg"};
    size_t strSize = sizeof(food) / sizeof(food[0]);
    string targetFood = "meat";
    int strIndex = findItem(food, strSize, targetFood);

    if (strIndex != -1)
    {
        cout << "The string \"" << targetFood << "\" is found at index " << strIndex << ".\n";
    }
    else
    {
        cout << "The string \"" << targetFood << "\" is not found in the array.\n";
    }

    return 0;
}
