#include <iostream>
#include "math_utils.h"

int main() {
    std::cout << "Welcome to Stratum C++ Project!" << std::endl;
    
    int result1 = MathUtils::add(5, 3);
    std::cout << "5 + 3 = " << result1 << std::endl;
    
    int result2 = MathUtils::multiply(5, 3);
    std::cout << "5 * 3 = " << result2 << std::endl;
    
    return 0;
}
