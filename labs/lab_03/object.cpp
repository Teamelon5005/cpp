#include <array>
struct Leg
{
    int length;
};

struct Arm
{
    int power;
};

class Person
{
    std::array<Leg, 2> legs;
    Arm arms[2];
};

int main()
{
    Person personA;
    Person personB;

    personB = personA;
}

/*
    Types:
        1. int: A basic integer type with size of 4 bytes (32 bits), used to store the values for length and power.
        2. Leg: A user-defined structure that contains one variable, length of type int.
        3. Arm: A user-defined structure that contains one variable, power of type int.
        4. Person: A user-defined structure that contains:
            - An array of 2 Leg objects - 'legs'.
            - An array of 2 Arm objects - 'arms'.
        5. std::array<Leg, 2>: A standard library container that holds two Leg objects.
        6. Arm[2]: A C-style array of two Arm objects.

    Objects:
        1. person: An object of type Person. It contains:
            - person.legs: An object of type std::array<Leg, 2>, which stores two Leg objects:
                * person.legs[0]: A Leg object (the first leg).
                * person.legs[1]: A Leg object (the second leg).
            - person.arms: An array of two Arm objects:
                * person.arms[0]: An Arm object (the first arm).
                * person.arms[1]: An Arm object (the second arm).
*/
