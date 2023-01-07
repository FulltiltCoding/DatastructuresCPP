#ifndef MINSTACK_H
#define MINSTACK_H

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
class MinStack
{
private:
    StackNode<T> *top;
    int n;
    T null;
    T min;

public:
    MinStack() : top(NULL), n(0), null((T)NULL), min((T)NULL) {}

    ~MinStack()
    {
        this->clear();
    }

    int size() const
    {
        return n;
    }

    int getMin() const
    {
        return min;
    }

    bool isEmpty() const
    {
        return (n == 0 ? true : false);
    }

    T push(const T &x)
    {
        if (n == 0)
            min = x;

        StackNode<T> *node = new StackNode<T>(x);

        if (x > min)
        {
            node->data = x;
        }
        else
        {
            node->data = (2 * x - min);
            min = x;
        }
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

        if (x < min)
        {
            min = 2 * min - x;
            x = (x + min) / 2;
        }

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
};

#endif