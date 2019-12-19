#include <vector>
#include <array>
#include <memory>
#include <iostream>

#define MAX_STACK_SIZE 10

class StackOfPlates {

private:
    
    std::shared_ptr<int> stack_ptr;
    int current_index = -1;
    std::vector<std::shared_ptr<int>> vv;

public:
    void push(int);
    int pop();
};

void StackOfPlates::push(int value) {

    if (vv.size() == 0 || current_index == 0) {

        current_index = MAX_STACK_SIZE-1;
        
        // deleter is needed because unable to create shared pointer for primitive array. 
        std::shared_ptr<int> arr_ptr(new int[MAX_STACK_SIZE], [](int *x) { std::cout << "deleter called" << '\n';  delete[] x;});
        stack_ptr = arr_ptr;

        arr_ptr.get()[current_index] = value;
        vv.emplace_back(arr_ptr);

        return;
    }

    current_index -= 1;
    stack_ptr.get()[current_index] = value;
}

int StackOfPlates::pop() {

    if (vv.size() == 0) {

        std::cout << "stack is empty" << '\n';
    }

    // if last item in the stack, then pop it and change the stack_ptr to 
    // pointing to the top of next stack stored in vector. 
    if (current_index == MAX_STACK_SIZE-1) {

        int temp = stack_ptr.get()[current_index];
        vv.pop_back();

        if (!vv.empty()) {
            stack_ptr = vv.back();
            current_index = 0;
        }
        return temp;
    }

    return stack_ptr.get()[current_index++];
}

int main() {

    StackOfPlates st;

    for (int i=0; i < 100; i++) {

        st.push(i);
    }

        for (int i=0; i < 100; i++) {

        std::cout << st.pop() << '\n';
    }
}


