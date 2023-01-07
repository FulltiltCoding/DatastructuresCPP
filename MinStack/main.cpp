// g++ -std=c++17 main.cpp && ./a.out

#include <iostream>
#include "minstack.h"

int main(int argc, const char *argv[])
{
    MinStack<int> list;
    int size = 0;

    list.push(20);
    list.push(38);
    list.push(9);
    list.push(29);
    list.push(99);
    list.push(10);
    list.push(5);
    list.push(66);
    list.push(100);

    std::cout << "size: " << list.size() << "\n";
    std::cout << "isEmpty: " << list.isEmpty() << "\n";
    std::cout << "min: " << list.getMin() << "\n";
    std::cout << "removelast" << list.pop() << "\n";
    std::cout << "min: " << list.getMin() << "\n";
    std::cout << "removelast" << list.pop() << "\n";
    std::cout << "min: " << list.getMin() << "\n";
    std::cout << "removelast" << list.pop() << "\n";
    std::cout << "min: " << list.getMin() << "\n";
    std::cout << "removelast" << list.pop() << "\n";
    std::cout << "min: " << list.getMin() << "\n";
    std::cout << "contains 4:" << list.contains(3) << "\n";
    list.clear();
    std::cout << "size: " << list.size() << "\n";
}