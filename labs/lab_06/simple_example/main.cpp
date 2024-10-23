#include <iostream>

int hello(int);

/*
    The error undefined reference to `hello(int)` occurs because:
        - The function 'hello' is declared, meaning the compiler knows its signature (the return type, name, and parameters).
        - However, since there is no definition (implementation) of the function in the code, the linker cannot find the actual code to execute when 'hello' is called in 'main'.
*/

int hello(int x) {
    return x + 1;
}

int main() {
    int result = hello(5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}