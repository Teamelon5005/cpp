#include <iostream>
#include <span>
#include <cassert>

void product(std::span<int> inputOutput, std::span<int> coefficients)
{
    assert(inputOutput.size() == coefficients.size());

    size_t i = 0;
    while (true)
    {
        if (i >= inputOutput.size())
            break;

        inputOutput[i] *= coefficients[i];
        i++;
    }
}

void product_while(std::span<int> inputOutput, std::span<int> coefficients)
{
    assert(inputOutput.size() == coefficients.size());

    size_t i = 0;
    while (i < inputOutput.size())
    {
        inputOutput[i] *= coefficients[i];
        i++;
    }
}

void product_for(std::span<int> inputOutput, std::span<int> coefficients)
{
    assert(inputOutput.size() == coefficients.size());

    for (size_t i = 0; i < inputOutput.size(); ++i)
        inputOutput[i] *= coefficients[i];
}


void printArray(int* arrayStart, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        int* elementAddress = arrayStart + i;
        int element = *elementAddress;
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    std::array<int, 4> inputOutputArr{ 1, 2, 3, 4 };
    std::array coefficientsArr{ 10, 20, 30, 40 };

    std::span<int> inputOutput{&inputOutputArr[0], inputOutputArr.size()};
    inputOutput = inputOutput.subspan(2, 1);

    std::span<int> coefficients(coefficientsArr);

    for (const auto& elem : inputOutput)
        std::cout << elem << " ";
    std::cout << std::endl;
    for (const auto& elem : coefficients)
        std::cout << elem << " ";
    std::cout << std::endl;

    char var;
    std::cout << "Choose the variant. '1' - infinite loop with break; '2' - while loop; '3' - for loop: ";
    std::cin >> var;
    switch (var)
    {
        case '1': product(inputOutput, coefficients); break;
        case '2': product_while(inputOutput, coefficients); break;
        case '3': product_for(inputOutput, coefficients); break;
    }

    for (const auto& elem : inputOutput)
        std::cout << elem << " ";

    return 0;
}
