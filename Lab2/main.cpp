#include <iostream>
#include "NumberList.h"
using namespace std;
int main()
{
    NumberList list;
    list.Init();
    list.Add(2);
    list.Add(9);
    list.Add(3);
    list.Add(8);
    list.Add(4);
    list.Print();
    cout<<endl;
    list.Sort();
    list.Print();
    return 0;
}