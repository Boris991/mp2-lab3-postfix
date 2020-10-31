#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
    T* pMem;
    int size;
    int top;
public:
    TStack(int _size = 1)
    {
        size = _size;
        top = -1;
        if ((size < 1) || (size > MaxStackSize))
            throw size;
        pMem = new T[size];
    }
    TStack(const TStack& tmp)
    {
        size = tmp.size;
        top = tmp.top;
        if ((size < 1) || (size > MaxStackSize))
            throw size;
        pMem = new T[size];
        for (int i = 0; i < size; i++)
        {
            pMem[i] = tmp.pMem[i];
        }
    }
    TStack& operator=(const TStack& tmp)
    {
        if (size != 0)
        {
            delete[]pMem;
        }
        size = tmp.size;
        top = tmp.top;
        if ((size < 1) || (size > MaxStackSize))
            throw size;
        pMem = new T[size];
        for (int i = 0; i < size; i++)
        {
            pMem[i] = tmp.pMem[i];
        }
        return *this;
    }
    ~TStack()
    {
        delete[] pMem;
    }
    void push(T tmp)
    {
        if (top < size)
        {
            pMem[++top] = tmp;
        }
    }
    bool isfull()
    {
        return top == size - 1;             // истина если стек  полон, ложь в противном случае   
    }
    T pop()
    {
        if (top >= 0)
        {
            return pMem[top--];
        }
        else
        {
            throw size;
        }

    }
    bool isempty()
    {
        return top < 0;                     // истина если стек  пуст, ложь в противном случае   
    }
    T Top()
    {
        if (top >= 0)
        {
            return pMem[top];
        }
        else
        {
            throw size;
        }
    }
};

#endif
