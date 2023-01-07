// g++ -std=c++17 main.cpp && ./a.out

#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main(int argc, const char *argv[])
{
    DoublyLinkedList<int> list;
    int size = 10;

    list.print();

    for (int i = 0; i < size; i++)
    {
        list.addFirst(i);
        // list.addLast(i);
    }

    list.print();
    cout << "size: " << list.size() << endl;
    cout << "isEmpty: " << list.isEmpty() << endl;
    cout << "removelast" << list.removeLast() << endl;
    cout << "removelast" << list.removeLast() << endl;
    cout << "removeFirst" << list.removeFirst() << endl;
    cout << "removeFirst" << list.removeFirst() << endl;
    cout << "peekFirst" << list.peekFirst() << endl;
    cout << "peekLast" << list.peekLast() << endl;
    cout << "contains 9:" << list.contains(9) << endl;
    cout << "get 5:" << list.get(1) << endl;
    cout << "set 5:" << list.set(1, 100) << endl;
    cout << "get 5:" << list.get(1) << endl;
    list.clear();
    cout << "size: " << list.size() << endl;
}