#include <iostream>
#include <vector>

#ifndef DS_ALG_CIRCULAR_QUEUE_HPP
#define DS_ALG_CIRCULAR_QUEUE_HPP

#define MAX_QUEUE_SIZE 100

template <typename T>
class Queue {

    public:
        int front_;
        int rear_;
        Queue();
        void enqueue(T t);
        T deque();
        bool isEmpty() const;
        bool isFull() const;
        std::vector<T> queue;
};

#endif