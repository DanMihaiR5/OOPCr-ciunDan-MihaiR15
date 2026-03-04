#include <iostream>
#include "Math.h"
using namespace std;

int main () {
    cout<<Math::Add(2,3)<<endl;
    cout<<Math::Add(1,2,3)<<endl;
    cout<<Math::Add(2.03,5.78)<<endl;
    cout<<Math::Add(5.61,8.30,16.27)<<endl;
    cout<<Math::Mul(9,9)<<endl;
    cout<<Math::Mul(9,9,9)<<endl;
    cout<<Math::Mul(1.25,4.87)<<endl;
    cout<<Math::Mul(3.04,6.08,8.09)<<endl;
    char* result = Math::Add("Hello ", "World!");
    if (result != nullptr)
    {
        std::cout << result << std::endl;
        delete[] result; 
    }
     char* testNull = Math::Add(nullptr, "Test");
    if (testNull == nullptr)
        std::cout << "Add(nullptr, ...): returned nullptr" << std::endl;
    return 0;
}