#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DLLNode
{
public:
    T data;
    DLLNode<T> *next;
    DLLNode<T> *prev;

    DLLNode<T>() {}

    DLLNode<T>(T x) : data(x), next(NULL), prev(NULL) {}

    ~DLLNode<T>() {}
};

template <typename T>
class DoublyLinkedList
{
private:
    DLLNode<T> *head;
    DLLNode<T> *tail;
    int n;
    T null;

public:
    DoublyLinkedList() : head(NULL), tail(NULL), n(0), null((T)NULL) {}

    ~DoublyLinkedList()
    {
        this->clear();
    }

    int size() const
    {
        return n;
    }

    bool isEmpty() const
    {
        return (n == 0 ? true : false);
    }

    bool addLast(const T &x)
    {
        DLLNode<T> *node = new DLLNode<T>(x);
        node->prev = tail;
        n == 0 ? head = node : tail->next = node;
        tail = node;
        n++;
        return true;
    }

    T addFirst(const T &x)
    {

        DLLNode<T> *node = new DLLNode<T>(x);
        node->next = head;
        n == 0 ? tail = node : head->prev = node;
        head = node;
        n++;
        return x;
    }

    T removeFirst()
    {
        if (n == 0)
            return null;
        T x = head->data;
        DLLNode<T> *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        if (--n == 0)
            tail = NULL;
        return x;
    }

    T removeLast()
    {
        if (n == 0)
            return null;
        T x = tail->data;
        DLLNode<T> *temp = tail;
        tail = tail->prev;
        delete temp;
        if (--n == 0)
            head = NULL;
        return x;
    }

    T peekFirst() const
    {
        return (n == 0 ? null : head->data);
    }

    T peekLast() const
    {
        return (n == 0 ? null : tail->data);
    }

    T clear()
    {
        while (n > 0)
            this->removeFirst();

        return null;
    }

    int contains(const T &x) const
    {
        if (n == 0)
            return null;

        DLLNode<T> *temp = head;
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

    T get(const int i) const
    {
        return (n == 0 ? null : getNode(i)->data);
    }

    T set(const int i, const T &x) const
    {
        DLLNode<T> *temp = getNode(i);
        T current = temp->data;
        temp->data = x;
        return current;
    }

    DLLNode<T> *getNode(const int i) const
    {
        DLLNode<T> *temp;
        if (i < n / 2)
        {
            temp = head->next;
            for (int j = 0; j < i; j++)
                temp = temp->next;
        }
        else
        {
            temp = tail;
            for (int j = n; j > i; j--)
                temp = temp->prev;
        }
        return temp;
    }

    void print() const
    {
        if (n == 0)
        {
            std::cout << "Empty"
                      << "\n";
            return;
        }

        DLLNode<T> *temp = head;
        int i = 0;

        while (temp)
        {
            std::cout << i << " : " << temp->data << "\n";
            temp = temp->next;
            i++;
        }
    }
};

#endif