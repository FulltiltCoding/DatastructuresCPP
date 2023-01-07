// g++ -std=c++17 main.cpp && ./a.out

#include <iostream>
#include "singlylinkedlist.h"

int main(int argc, const char *argv[])
{
    SinglyLinkedList<int> list;
    int size = 10;

    for (int i = 0; i < size; i++)
    {
        list.addFirst(i);
        list.addLast(i);
    }

    SinglyLinkedList<int> list2;
    list2 = list;

    std::cout << "List 1=======\n";
    list.print();
    std::cout << "List 2=======\n";
    list2.print();
    std::cout << "size: " << list.size() << "\n";
    std::cout << "isEmpty: " << list.isEmpty() << "\n";
    std::cout << "removelast" << list.removeLast() << "\n";
    std::cout << "removelast" << list.removeLast() << "\n";
    std::cout << "contains 2:" << list.contains(2) << "\n";
    std::cout << "get 5:" << list.get(1) << "\n";
    std::cout << "set 5:" << list.set(1, 100) << "\n";
    std::cout << "get 5:" << list.get(1) << "\n";
    std::cout << "peekFirst: " << list.peekFirst() << "\n";
    std::cout << "peekLast: " << list.peekLast() << "\n";
    list.clear();
    std::cout << "size: " << list.size() << "\n";
    list2.print();
}