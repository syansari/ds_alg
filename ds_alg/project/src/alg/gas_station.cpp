// https://leetcode.com/problems/gas-station/

#include <iostream>
#include <vector>

int starting_gas_index(std::vector<int>& gas, std::vector<int>& distance_cost) {

    for (int i = 0; i < gas.size(); i++) {

        int j = i, count = 0, total_gas = 0, prev_dist_cost = 0;

        while (count < gas.size()) {
        
            total_gas -= prev_dist_cost;
            total_gas += gas[j];

            if (total_gas < distance_cost[j]) {
                break;
            }
            
            else {

                prev_dist_cost = distance_cost[j];
                j = ++j % gas.size();
                count++;
            }
        }

        if (count == gas.size()) {
            return j;
        }
    }

    return -1;
}



int main() {

      std::vector<int> gas =  {1, 2, 3, 4, 5};
      std::vector<int> distance_cost = {3, 4, 5, 1, 2};

    //std::vector<int> gas = {4,5,2,6,5,3};
   // std::vector<int> distance_cost = {3,2,7,3,2,9};

    std::cout <<  "starting gas index: " << starting_gas_index(gas, distance_cost) << '\n';
}

