#ifndef STACK_H
#define STACK_H

template <typename T>
class StackNode
{
public:
    T data;
    StackNode<T> *next;

    StackNode<T>() {}

    StackNode<T>(T x) : data(x), next(NULL) {}

    ~StackNode<T>() {}
};

template <typename T>
class Stack
{
private:
    StackNode<T> *top;
    int n;
    T null;
    StackNode<T> *getNode(const int i) const;

public:
    Stack() : top(NULL), n(0), null((T)NULL) {}

    ~Stack()
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

    T push(const T &x)
    {
        StackNode<T> *node = new StackNode<T>(x);
        node->next = top;
        top = node;
        n++;
        return x;
    }

    T pop()
    {
        if (n == 0)
            return null;
        T x = top->data;
        StackNode<T> *temp = top;
        top = top->next;
        delete temp;
        n--;
        return x;
    }

    T peek() const
    {
        return (n == 0 ? null : top->data);
    }

    T clear()
    {
        while (n > 0)
            this->pop();

        return null;
    }

    int contains(const T &x) const
    {

        if (n == 0)
            return null;

        StackNode<T> *temp = top;
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

    T set(const int i, const T &x)
    {
        if (n == 0 || i > n - 1)
            return null;
        StackNode<T> *temp = getNode(i);
        T current = temp->data;
        temp->data = x;
        return current;
    }

    void print() const
    {
        if (n == 0)
        {
            std::cout << "Empty"
                      << "\n";
            return;
        }

        StackNode<T> *temp = top;
        int i = 0;

        while (temp)
        {
            std::cout << i << " : " << temp->data << "\n";
            temp = temp->next;
            i++;
        }
    }
};

template <typename T>
StackNode<T> *Stack<T>::getNode(const int i) const
{
    StackNode<T> *temp = top;

    for (int j = 0; j < i; j++)
        temp = temp->next;

    return temp;
}

#endif