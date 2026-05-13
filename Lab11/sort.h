#pragma once
#include <vector>
using namespace std;

template<typename T>
class Sorter {
public:
    static void BubbleSort(std::vector<T>& v)
    {
        int n = v.size();

        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                if (v[j] > v[j + 1])
                {
                    T aux = v[j];

                    v[j] = v[j + 1];
                    v[j + 1] = v[j];
                }
            }
        }
    }
};