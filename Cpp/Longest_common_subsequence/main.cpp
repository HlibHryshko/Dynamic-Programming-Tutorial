//
// Created by glebg on 25.11.2021.
//
#include <iostream>
#include <sstream>
std::pair<std::string, int> lcs(const std::string& x, const std::string& y){
    // initializing the 2-dimensional matrix for the tabulation method
    // initializing the 2-dimensional array for the previous
    int ** z = new int*[x.length() + 1];
    auto ** prev = new std::pair<size_t, size_t>*[x.length() + 1];
    for (size_t i = 0; i <= x.length(); ++i){
        z[i] = new int[y.length() + 1];
        prev[i] = new std::pair<size_t, size_t>[y.length() + 1];
    }

    // this part loops through the whole matrix and fills it
    // loop for every row
    for (size_t i = 0; i <= x.length(); ++i){
        // loop for every column
        for (size_t j = 0; j <= y.length(); ++j){
            // if i and j are 0
            if (i == 0 || j == 0){
                z[i][j] = 0;

                // else if the element with index i in string x equals to the element with index j in string y
            } else if (x[i - 1] == y[j - 1]){
                // incrementing the lcs
                z[i][j] = z[i - 1][j - 1] + 1;
                // putting the previous indexes in the matrix of previous values, to be able to find the elements in lcs
                prev[i][j] = std::pair<size_t, size_t>{i - 1, j - 1};
            } else {
                // if the lcs for x[0:i] and y[j + 1] > lcs for x[0:i + 1][0:j]
                if (z[i - 1][j] > z[i][j - 1]){
                    // putting the value of the previous tile in the current one
                    z[i][j] = z[i - 1][j];
                    // putting the previous indexes in the matrix of previous values, to be able to find the elements in lcs
                    prev[i][j] = std::pair<size_t, size_t>{i - 1, j};
                } else {
                    // putting the value of the previous tile in the current one
                    z[i][j] = z[i][j - 1];
                    // putting the previous indexes in the matrix of previous values, to be able to find the elements in lcs
                    prev[i][j] = std::pair<size_t, size_t>{i, j - 1};
                }
            }
        }
    }
    // part for finding the elements in lcs
    std::ostringstream str_cs;
    size_t i = x.length();
    size_t j = y.length();
    // moving backwards from [n][m] till the row or column is not 0
    while (i != 0 && j != 0){
        auto indexes = prev[i][j];
        // if there was an equality of the elements of x and y
        if (indexes.first == i - 1 && indexes.second == j - 1){
            // adding the element in front of the previous lcs
            std::string new_sub_sequence = x[i - 1] + str_cs.str();
            str_cs = {};
            // putting the new lcs inside the element of ostringstream type
            str_cs << new_sub_sequence;
        }
        // updating the indexes
        i = indexes.first;
        j = indexes.second;
    }
    // returning a pair with the elements that are in the lcs and the length of lcs
    return {str_cs.str(), z[x.length()][y.length()]};
}

int main(){
    std::string str1;
    std::string str2;
    std::cin >> str1;
    std::cin >> str2;
    auto _lcs = lcs(str1, str2);
    std::cout << "The length of the LCS is " << _lcs.second << "\n";
    // if the length of the lcs is not 0, then output lcs
    if (_lcs.second > 0){
        std::cout << "The LCS is: " << _lcs.first;
    }
    return 0;
}