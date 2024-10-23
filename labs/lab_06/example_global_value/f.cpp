#include <iostream>

void hello(int);

void hello(int value) {
    std::cout << "Processed Value: " << value + 1 << std::endl;
}