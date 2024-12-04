#include <iostream>

void f()
{
    int a = 6; // 301
    std::cout << a;
}

void g()
{
    int b; // 302
    std::cout << b;
}

int main() {

    // stack
    f();
    g();

    int i;
    i = 69;

    int number = 72;

    i += number;

    int array[3] = { };

    int* iPointer = &i;

    number = *iPointer;

    *iPointer = 15;

    iPointer = &array[0];

    iPointer += 2;

    array[0] = 5;
    *iPointer = 6;

    std::cout << "i: " << i << std::endl;
    std::cout << "number: " << number << std::endl;
    std::cout << "array: [" << array[0] << ", " << array[1] << ", " << array[2] << "]" << std::endl;

    return 0;
}
