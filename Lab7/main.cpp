#include <iostream>
#include "temp.h"
#include "tree.h"

bool compare_int(int a, int b)
{
    return a == b;
}

bool sort_int(int a, int b)
{
    return a < b;
}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << std::endl;
    std::cout << "120 Fahrenheit in Celsius: " << b << std::endl;

    Tree<int> tree;

    auto root = tree.add_node(nullptr, 10);
    auto child1 = tree.add_node(root, 5);
    auto child2 = tree.add_node(root, 20);

    tree.add_node(child1, 3);
    tree.add_node(child1, 7);

    tree.insert(root, 1, 15);

    std::cout << "Total nodes: " << tree.count(nullptr) << std::endl;

    auto found = tree.find(7, compare_int);

    if(found)
        std::cout << "Found node with value 7\n";

    tree.sort(root, sort_int);

    tree.delete_node(child2);

    std::cout << "Total nodes after delete: " << tree.count(nullptr) << std::endl;

    return 0;
}