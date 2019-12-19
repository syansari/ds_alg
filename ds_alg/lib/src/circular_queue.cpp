#include "../incl/circular_queue.hpp"

template<typename T>
Queue<T>::Queue() : front_(-1), rear_(-1) {

    queue.resize(MAX_QUEUE_SIZE);
}


template<typename T> 
bool Queue<T>::isEmpty() const {

    return front_ == -1;
}

template<typename T>
bool Queue<T>::isFull() const {

    return (rear_+1) %10 == front_; 
}

template<typename T>
void Queue<T>::enqueue(T t) {

    if (isFull()) {

        std::cout << "Unable to add, queue is full" << '\n';
    }

    if (rear_ == -1) {

        queue[0] = t;
        rear_ = front_ = 0;
        return;
    }

    rear_ = (rear_ + 1) % MAX_QUEUE_SIZE;
    queue[rear_] = t;
}

template<typename T>
T Queue<T>::deque() {

    if (isEmpty()) {
        
        std::cout << "Unable to dequeue, queue is empty" << '\n';
    }

    int temp = front_;

    if (front_ == rear_) {

        front_ = rear_ = -1;
        return queue[temp];
    }
    
    front_ = (front_+ 1) % MAX_QUEUE_SIZE;
    return queue[temp];
}

template class Queue<int>;




