#include <iostream>
#include <vector>

class Fibonacci{
public:

    virtual int calculate_fibonacci(int n){
        std::vector<int> memoize(n + 1, -1);
        return recursion_fibonacci(memoize, n);
    }
    virtual int recursion_fibonacci(std::vector<int>& memoize, int n){
        if (n < 2){
            return n;
        }

        if (memoize[n] != -1){
            return memoize[n];
        }

        memoize[n] = recursion_fibonacci(memoize, n - 1) + recursion_fibonacci(memoize, n - 2);
        return memoize[n];
    }
    virtual ~Fibonacci() = default;
};


int main(){
    Fibonacci* fibonacci{new Fibonacci};
    std::cout << "6th Fibonacci number is: " << fibonacci->calculate_fibonacci(6) << std::endl;
    std::cout << "7th Fibonacci number is: " << fibonacci->calculate_fibonacci(7) << std::endl;
    std::cout << "8th Fibonacci number is: " << fibonacci->calculate_fibonacci(8) << std::endl;
}