//
// Created by glebg on 03.12.2021.
//
#include <iostream>
#include <vector>

int rod(std::vector<int>& length, std::vector<int>& price, size_t total_length){
    std::vector<int> max_price{};
    // loops through all the lengths from 0 to total_length
    for (size_t i = 0; i <= total_length; ++i){
        // if i is less than the size of the array of lengths(it is assumed that weight[i] == i)
        if (i < price.size()){
            // putting the default value in the end of the max_length value
            // it is needed in order to work with max_length[i] later
            max_price.emplace_back(price[i]);
        } else {
            // putting the default value, which equals the previous length max_length + the price of rod with length 1,
            // in the end of the max_length value
            // it is needed in order to work with max_length[i] later
            max_price.emplace_back(max_price[i - 1] + max_price[1]);
        }
        // loop through all the available length that were given to the function
        for (size_t len: length){
            // if the length of the element is less or equal to the length of the rod that is needed to cut
            if (i >= len){
                // comparing the current maximum price with
                // the maximum price of the sum of rod with length len and result with length i - len
                // if cutting the piece of length len is giving bigger price then
                if (max_price[i - len] + max_price[len] > max_price[i]){
                    // change current result to a bigger one
                    max_price[i] = max_price[i - len] + max_price[len];
                }
            }
        }
    }
    // return the maximum price of the rod
    return max_price[total_length];
}
int main(){
    // first dataset
    std::vector<int> lengths1{0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> prices1{0, 1, 5, 8, 9, 10, 17, 17, 20};
    size_t length1 {8};
    std::cout << "Maximal obtainable value is : " << rod(lengths1, prices1, length1) << std::endl;
    // second dataset
    std::vector<int> lengths2{0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> prices2{0, 3, 5, 8, 9, 10, 17, 17, 20};
    size_t length2 {8};
    std::cout << "Maximal obtainable value is : " << rod(lengths2, prices2, length2);
    return 0;
}