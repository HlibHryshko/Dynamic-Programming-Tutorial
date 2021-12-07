#include <iostream>


int min_path(int** matrix, int rows, int columns){
    // initializing 2 dimensional array for calculating the path
    int ** table = new int* [rows + 1];
    for (int i = 0; i <= rows; ++i){
        table[i] = new int [columns + 1];
    }

    // filling first row and zero column with the minimal path
    // this path is the path from [1][1]
    table[1][1] = matrix[1][1];
    for (int i = 2; i <= columns; ++i){
        table[1][i] = table[1][i - 1] + matrix[1][i];
    }
    for (int i = 2; i <= rows; ++i){
        table[i][1] = table[i - 1][1] + matrix[i][1];
    }

    // performing dp algorithm for calculating the path with the smallest value
    for (int i = 2; i <= rows; ++i){
        for (int j = 2; j <= columns; ++j){
            table[i][j] = matrix[i][j] + std::min(table[i - 1][j], table[i][j - 1]);
        }
    }
    return table[rows][columns];
}


int main(){
    int rows{};
    int columns{};
    std::cin >> rows >> columns;
    int ** matrix = new int* [rows + 1];
    for (int i = 0; i <= rows; ++i){
        matrix[i] = new int[columns + 1];
    }
    for (int i = 1; i <= rows; ++i){
        for (int j = 1; j <= columns; ++j){
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "The smallest value, that could be achieved is " << min_path(matrix, rows, columns) << "\n";
    return 0;
}

