//
// Created by glebg on 03.12.2021.
//
#include <iostream>
#include <vector>

int kn_01(std::vector<int>& weight, std::vector<int>& price, int capacity, int amount){
    // creating a vector for storing the maximum price of knapsack with capacity from 0 to capacity
    std::vector<int> result(capacity + 1, 0);
    // loop through all the elements that could be put into the knapsack
    for (int i = 0; i < amount; ++i){
        // loop through all the capacities, from the capacity of our main problem to 0
        for (int cap = capacity; cap >= 0; --cap){
            // if the weight of current element is less or equal to the length of current capacity, then
            if (weight[i] <= cap){
                // choosing the maximum value out of the current maximum and
                // the maximum current's element price + the maximum price of the knapsack with capacity, which equals
                // to the current capacity - weight of the current element
                result[cap] = std::max(result[cap],
                                       result[cap - weight[i]] + price[i]);
            }
        }
    }
    // return the maximum price of the knapsack with the capacity that is requested by a function call
    return result[capacity];
}

int main(){
    // dataset 1
    std::vector<int> weights1 {10, 20, 30};
    std::vector<int> prices1 {60, 100, 120};
    int capacity1{50};
    std::cout << "Max price of the knapsack: " << kn_01(weights1, prices1, capacity1, static_cast<int>(weights1.size())) << "\n";

    // dataset 2
    std::vector<int> weights2 {95, 4, 60, 32, 23, 72, 80, 62, 65, 46};
    std::vector<int> prices2 {55, 10, 47, 5, 4, 50, 8, 61, 85, 87};
    int capacity2{269};
    std::cout << "Max price of the knapsack: " << kn_01(weights2, prices2, capacity2, static_cast<int>(weights2.size())) << "\n";

    // dataset 3
    std::vector<int> weights3 {92, 4, 43, 83, 84, 68, 92, 82, 6, 44, 32, 18, 56, 83, 25, 96, 70, 48, 14, 58};
    std::vector<int> prices3 {44, 46, 90, 72, 91, 40, 75, 35, 8, 54, 78, 40, 77, 15, 61, 17, 75, 29, 75, 63};
    int capacity3{878};
    std::cout << "Max price of the knapsack: " << kn_01(weights3, prices3, capacity3, static_cast<int>(weights3.size())) << "\n";
    return 0;
}
