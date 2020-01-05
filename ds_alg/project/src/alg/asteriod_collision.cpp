#include <list>
#include <vector>
#include <iostream>


void find_final_state(std::list<int>& asteroids) {

    std::list<int>::iterator it = asteroids.begin();

    while(it != asteroids.end()) {

        int prev = *it;
        std::cout << "at value" << prev << '\n';
        
        if (++it == asteroids.end()) {
            return;
        }        
        int curr = *(it);
        
        if ((prev >= 0 && curr >= 0) || (prev < 0 && curr < 0)) {
            continue;
        }

        if (prev >=0 && curr < 0) {

            if (prev > abs(curr)) {

                asteroids.erase(it);
            }
            else if (prev < abs(curr)) {

                asteroids.erase(--it);
            }
            else if (prev == abs(curr)) {

                asteroids.erase(it);
                asteroids.erase(--it);
            }

            it = asteroids.begin();
            std::cout << "beginning element is now: " << *it << '\n';
        }
    }
}

int main() {

   //std::list<int> asteroids = {8, -8};
   std::list<int> asteroids = {10, 2, -5};
   // std::list<int> asteroids = {5, 10, -5};
   // std::list<int> asteroids = {-2, -1, 1, 2};

    find_final_state(asteroids);

    std::cout << "final state : " << '\n';
    for (auto x: asteroids) {

        std::cout << x << ' ';
    }

    std::cout << '\n';
}






