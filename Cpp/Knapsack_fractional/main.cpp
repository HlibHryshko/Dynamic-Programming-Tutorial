//
// Created by glebg on 30.11.2021.
//
#include <iostream>
#include <vector>

double kn_fractional(double capacity, std::vector<double> weight, std::vector<double> price){
    // creating and filling the vector of pairs with index and double value of price/weight
    std::vector<std::pair<size_t, double>> relation{};
    for (size_t i = 0; i < weight.size(); ++i){
        relation.emplace_back(i, price[i]/weight[i]);
    }
    // sorting the vector by the relation value(second value)
    std::sort(relation.begin(), relation.end(), [](auto relation_a, auto relation_b){
        return relation_a.second < relation_b.second;
    });
    double c_copy{capacity};
    double max_price{0};
    // decreasing the capacity while it is not 0
    while (c_copy > 0){
        // if the weight of the element with the highest available relation of price to weight
        // is less than left capacity then
        if (c_copy - weight[relation.back().first] >= 0){
            // increasing the max price by the price of the element with the index that is stored in the pair
            max_price += price[relation.back().first];
            // decreasing the left capacity by the weight of the element with the index that is stored in the pair
            c_copy -= weight[relation.back().first];
            // deleting the element with the highest relation, because it has been already used
            relation.pop_back();
        } else {
            // increasing the max price by the price of the element with the index that is stored in the pair
            // multiplied by the relation of the left capacity to the weight of the element
            max_price += price[relation.back().first] * (c_copy / weight[relation.back().first]);
            c_copy = 0;
        }
    }
    // returning the maximum price of the knapsack
    return max_price;
}

int main(){
    // dataset 1
    double capacity1{50};
    std::vector<double> weight1{10, 20, 30};
    std::vector<double> price1{60, 100, 120};
    // dataset 2
    double capacity2{60};
    std::vector<double> weight2{5, 10, 15, 22, 25};
    std::vector<double> price2{30, 40, 45, 77, 90};
    std::cout << "The biggest value that could be placed in the knapsack: " << kn_fractional(capacity1, weight1, price1) << "\n";
    std::cout << "The biggest value that could be placed in the knapsack: " << kn_fractional(capacity2, weight2, price2) << "\n";
    return 0;
}

