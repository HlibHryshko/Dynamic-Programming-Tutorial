#include <iostream>
#include <vector>
class Fibonacci{
public:
    virtual int calculate_fibonacci(int n){
        if (n==0){
            return 0;
        }
        // creating 1-dimensional table
        std::vector<int> tab(n + 1, -1);
        // solving the easiest sub-problems, needed for calculation
        // of the following ones
        tab[0] = 0;
        tab[1] = 1;
        //solving the other sub-problems and the main problem as well
        for (int i = 2; i <= n; ++i){
            tab[i] = tab[i - 1] + tab[i - 2];
        }
        return tab[n];
    }
    virtual ~Fibonacci() = default;
};

int main(){
    Fibonacci* fibonacci{new Fibonacci};
    std::cout << "7th Fibonacci number is: " << fibonacci->calculate_fibonacci(7) << std::endl;
    std::cout << "8th Fibonacci number is: " << fibonacci->calculate_fibonacci(8) << std::endl;
    std::cout << "9th Fibonacci number is: " << fibonacci->calculate_fibonacci(9) << std::endl;
    return 0;
}

