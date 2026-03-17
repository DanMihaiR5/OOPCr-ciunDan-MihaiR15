#pragma once
#include <vector>
#include <initializer_list>
class Sort
{
private:
int* v;
int count;
void swap(int& a,int& b);
int partition(int low,int high,bool asc);
void quickSortRec(int low,int high,bool asc);
    // add data members
public:
    // add constuctors
Sort(int nrElemente,int min,int max);
Sort(int* list,int nr): v(list),count(nr) {}
Sort(std::vector<int> vec,int nrElemente);
Sort(int count, ...);
Sort(const char* numbers);
    // Destructor
~Sort();
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};