#include <iostream>

int globalValue = 5;

void hello(int);

int main() {
    std::cout << "Global Value: " << globalValue << std::endl;

    hello(globalValue);

    return 0;
}