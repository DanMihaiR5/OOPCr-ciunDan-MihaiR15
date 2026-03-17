#include "Sort.h"
#include <iostream>

int main() {
    Sort s1(5, 1, 100);
    s1.Print();
    int arr[] = {10, 40, 100, 5, 70};
    Sort s2(arr, 5);
    s2.Print();

    std::vector<int> vec = {1,2,3,4,5};
    Sort s3(vec, 3);
    s3.Print();

    Sort s4(4, 10, 20, 30, 40);
    s4.Print();

    Sort s5("10,40,100,5,70");
    s5.Print();

    s5.InsertSort(true);
    s5.Print();

    s5.BubbleSort(false);
    s5.Print();

    s5.QuickSort(true);
    s5.Print();

    std::cout << "Count: " << s5.GetElementsCount() << '\n';
    std::cout << "Element[2]: " << s5.GetElementFromIndex(2) << '\n';

    return 0;
}