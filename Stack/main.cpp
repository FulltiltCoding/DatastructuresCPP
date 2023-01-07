// g++ -std=c++17 main.cpp && ./a.out

#include <iostream>
#include "stack.h"

int main(int argc, const char *argv[])
{
    Stack<int> list;
    int size = 20;

    for (int i = 0; i < size; i++)
    {
        list.push(i);
    }

    std::cout << "size: " << list.size() << "\n";
    std::cout << "isEmpty: " << list.isEmpty() << "\n";
    std::cout << "removelast" << list.pop() << "\n";
    std::cout << "contains 3:" << list.contains(3) << "\n";
    std::cout << "peek:" << list.peek() << "\n";
    list.clear();
    std::cout << "size: " << list.size() << "\n";
}