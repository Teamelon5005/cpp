#include <iostream>

struct FruitCounts
{
    int apples;
    int pears;
    int oranges;
};

int main()
{
    FruitCounts fruitCounts;

    std::cout << "Apples: ";
    std::cin >> fruitCounts.apples;

    std::cout << "Pears: ";
    std::cin >> fruitCounts.pears;

    std::cout << "Oranges: ";
    std::cin >> fruitCounts.oranges;

    bool conditionMet;

    {
        bool applesCondition = fruitCounts.apples > 5;
        bool pearsCondition = fruitCounts.pears < 8;
        bool orangesCondition = fruitCounts.oranges == 2 * fruitCounts.apples;

        conditionMet = applesCondition && pearsCondition && orangesCondition;
    }

    if (conditionMet)
    {
        std::cout << "Hello" << std::endl;
    }

    return 0;
}