#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;

void Print(const vector<int>& v)
{
    for (auto x : v)
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    try
    {
        vector<int> v1;
        Sorter<int>::BubbleSort(v1);

        cout << "TEST 1 PASSED\n";
    }
    catch (...)
    {
        cout << "TEST 1 FAILED - crash pe vector gol\n";
    }

    vector<int> v2 = {5};

    try
    {
        Sorter<int>::BubbleSort(v2);

        if (v2[0] == 5)
            cout << "TEST 2 PASSED\n";
        else
            cout << "TEST 2 FAILED\n";
    }
    catch (...)
    {
        cout << "TEST 2 FAILED - exceptie\n";
    }

    vector<int> v3 = {3, 2};

    Sorter<int>::BubbleSort(v3);

    if (v3[0] == 2 && v3[1] == 3)
        cout << "TEST 3 PASSED\n";
    else
    {
        cout << "TEST 3 FAILED\n";
        Print(v3);
    }

    vector<int> v4 = {5, 1, 4, 2, 8};

    Sorter<int>::BubbleSort(v4);

    bool sorted = true;

    for (int i = 0; i < v4.size() - 1; i++)
    {
        if (v4[i] > v4[i + 1])
            sorted = false;
    }

    if (sorted)
        cout << "TEST 4 PASSED\n";
    else
    {
        cout << "TEST 4 FAILED\n";
        Print(v4);
    }

    vector<int> v5 = {2, 2, 1, 1};

    Sorter<int>::BubbleSort(v5);

    sorted = true;

    for (int i = 0; i < v5.size() - 1; i++)
    {
        if (v5[i] > v5[i + 1])
            sorted = false;
    }

    if (sorted)
        cout << "TEST 5 PASSED\n";
    else
    {
        cout << "TEST 5 FAILED\n";
        Print(v5);
    }

    return 0;
}