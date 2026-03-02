#include "NumberList.h"
#include <iostream>
using namespace std;
void NumberList::Init()
{
    this->count=0;
}

bool NumberList::Add(int x)
{
    if (this->count >= 10)
    {
        return false;
    }
    else
    {
        this->numbers[this->count] = x;
        this->count++;
        return true;
    }
}

void NumberList::Sort()
{
    for (int i = 0; i < this->count - 1; i++)
    {
        for (int j = 0; j < this->count - i - 1; j++)
        {
            if (this->numbers[j] > this->numbers[j + 1])
            {
                int temp = this->numbers[j];
                this->numbers[j] = this->numbers[j + 1];
                this->numbers[j + 1] = temp;
            }
        }
    }
}
void NumberList::Print()
{
   for (int i=0;i<this->count;i++)
   {
    std::cout<<this->numbers[i]<<" ";
   }
}