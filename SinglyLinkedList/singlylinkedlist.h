#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

template <typename T>
class SLLNode
{
public:
    T data;
    SLLNode<T> *next;

    SLLNode<T>(){};
    SLLNode<T>(T x) : data(x), next(NULL) {}
    ~SLLNode<T>() {}
};

template <typename T>
class SinglyLinkedList
{
private:
    SLLNode<T> *head;
    SLLNode<T> *tail;
    int n;
    T null;

    SLLNode<T> *getNode(const int i) const;
    SinglyLinkedList(const SinglyLinkedList &obj) {}

public:
    SinglyLinkedList() : head(NULL), tail(NULL), n(0), null((T)NULL) {}
    ~SinglyLinkedList() {} // use clear here

    int size() const;
    bool isEmpty() const;
    void clear();
    T addFirst(const T &x);
    T addLast(const T &x);
    T removeFirst();
    T removeLast();
    T peekFirst() const;
    T peekLast() const;
    T contains(const T &x) const;
    T get(const int i) const;
    T set(const int i, const T &x);
    void print() const;
    void operator=(const SinglyLinkedList &list);
};

template <class T>
int SinglyLinkedList<T>::size() const
{
    return n;
}

template <class T>
bool SinglyLinkedList<T>::isEmpty() const
{
    return (n == 0 ? true : false);
}

template <class T>
T SinglyLinkedList<T>::addLast(const T &x)
{
    SLLNode<T> *node = new SLLNode<T>(x);
    (n == 0 ? head = node : tail->next = node);
    tail = node;
    n++;
    return x;
}

template <class T>
T SinglyLinkedList<T>::addFirst(const T &x)
{
    SLLNode<T> *node = new SLLNode<T>(x);
    node->next = head;
    head = node;
    if (n == 0)
        tail = node;
    n++;
    return x;
}

template <class T>
T SinglyLinkedList<T>::removeFirst()
{
    if (n == 0)
        return null;
    T x = head->data;
    SLLNode<T> *temp = head;
    head = head->next;
    delete temp;
    if (--n == 0)
        tail = NULL;
    return x;
}

template <class T>
T SinglyLinkedList<T>::removeLast()
{
    if (n == 0)
        return null;

    T x = tail->data;
    SLLNode<T> *temp = head;

    while (temp->next != tail)
    {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    if (--n == 0)
        head = NULL;
    return x;
}

template <class T>
T SinglyLinkedList<T>::peekFirst() const
{
    return (n == 0 ? null : head->data);
}

template <class T>
T SinglyLinkedList<T>::peekLast() const
{
    return (n == 0 ? null : tail->data);
}

template <class T>
void SinglyLinkedList<T>::clear()
{
    while (n > 0)
        this->removeFirst();
}

template <class T>
T SinglyLinkedList<T>::contains(const T &x) const
{
    if (n == 0)
        return null;

    SLLNode<T> *temp = head;
    int i = 0;

    while (temp->next)
    {
        if (x == temp->data)
            return i;
        i++;
        temp = temp->next;
    }
    return null;
}

template <class T>
T SinglyLinkedList<T>::get(const int i) const
{
    return (n == 0 ? null : getNode(i)->data);
}

template <class T>
T SinglyLinkedList<T>::set(const int i, const T &x)
{
    if (n == 0 || i > n - 1)
        return null;
    SLLNode<T> *temp = getNode(i);
    T current = temp->data;
    temp->data = x;
    return current;
}

template <class T>
void SinglyLinkedList<T>::print() const
{
    if (n == 0)
    {
        std::cout << "Empty"
                  << "\n";
        return;
    }

    SLLNode<T> *temp = head;
    int i = 0;

    while (temp)
    {
        std::cout << i << " : " << temp->data << "\n";
        temp = temp->next;
        i++;
    }
}

template <class T>
void SinglyLinkedList<T>::operator=(const SinglyLinkedList &list)
{
    this->clear();

    int size = list.size();
    for (int i = 0; i < size; i++)
    {
        this->addLast(list.get(i));
    }
}

template <class T>
SLLNode<T> *SinglyLinkedList<T>::getNode(const int i) const
{
    SLLNode<T> *temp = head;

    for (int j = 0; j < i; j++)
        temp = temp->next;

    return temp;
}

#endif