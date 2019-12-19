
#include "../../lib/incl/circular_queue.hpp"

int main() {

    Queue<int> queue;
    std::cout << "front: " << queue.front_ << " rear: " << queue.rear_ << '\n'; 
    
    queue.enqueue(10);
    std::cout << "front: " << queue.front_ << " rear: " << queue.rear_ << '\n'; 

    queue.enqueue(12);
    std::cout << "front: " << queue.front_ << " rear: " << queue.rear_ << '\n'; 

    queue.deque();
    std::cout << "front: " << queue.front_ << " rear: " << queue.rear_ << '\n'; 

    queue.deque();
    std::cout << "front: " << queue.front_ << " rear: " << queue.rear_ << '\n'; 

    std::cout << "is queue empty: " << (queue.isEmpty() ? "yes" : "no") << '\n'; 

}