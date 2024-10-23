#include <iostream>
#include <string_view>
#include <cassert>

size_t countOnes(std::string_view str)
{
    size_t count = 0;

    for (char c : str)
        if (c == '1')
            count++;

    return count;
}

int main()
{
    assert(countOnes("00000000") == 0);

    assert(countOnes("10101010") == 4);

    assert(countOnes("11111111") == 8);

    assert(countOnes("") == 0);

    assert(countOnes("abcde") == 0);

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}