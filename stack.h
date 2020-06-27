/*
  Lightweight implementation of Stack

  Copyright (C) 2019-2020 Calcitem <calcitem@outlook.com>
  Licensed under the MIT License.
*/

#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <cassert>

template <typename T, size_t capacity = 128>
class Stack
{
public:
    Stack()
    {
        arr = new T[capacity];
    }

    Stack(const Stack &other)
    {
        *this = other;
    }

    ~Stack()
    {        
        //memset(arr, 0, sizeof(T) * capacity);
        //delete[] arr;
    }

    Stack &operator= (const Stack &other)
    {
        memcpy(arr, other.arr, length());
        p = other.p;
        return *this;
    }

    bool operator== (const T &other) const
    {
        return (p == other.p &&
                memcmp(arr, other.arr, size()));
    }

#if 0
    T operator*(const Stack<T> &obj)
    {
        return (obj.arr);
    };
#endif

    T &operator[](int i)
    {
        return arr[i];
    }

    const T &operator[](int i) const
    {
        return arr[i];
    }

    inline void push(const T &obj)
    {
        p++;
        memcpy(arr + p, &obj, sizeof(T));

        assert(p < capacity);
    }

    inline void push_back(const T &obj)
    {
        p++;
        arr[p] = obj;

        assert(p < capacity);
    }

    inline void pop()
    {
        p--;
    }

    inline T *top()
    {
        return &(arr[p]);
    }

    inline int size() const
    {
        return p + 1;
    }

    inline size_t length()
    {
        return (sizeof(T) * size());
    }

    inline T *begin()
    {
        return &arr[0];
    }

    inline T *end()
    {
        return &arr[p + 1];
    }

    inline bool empty() const
    {
        return (p < 0);
    }

    inline void clear()
    {
        p = -1;
    }

    inline void erase(int index)
    {
        for (int i = index; i < capacity - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        p--;
    }

private:
    T *arr;
    int p { -1 };
};

#endif // STACK_H
