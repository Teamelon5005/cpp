#include <string.h>  // For memset
#include <iostream>  // For console input/output

// Define a struct 'TwoInts' with two integers
struct TwoInts
{
    int a;
    int b;
};

// Define a struct 'StructWithArray' with an integer array of size 4 and a pointer to an integer
struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    // Initialize 'i2' as an instance of struct 'TwoInts' with default values and predefined 'a' and 'b'
    TwoInts i2 = { };
    i2.a = 5;
    i2.b = 7;

    // Output the values of 'a' and 'b'
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;

    // Initialize 's' as an instance of struct 'StructWithArray' and set its first array element to 10 (others are default)
    StructWithArray s = { };
    s.arr[0] = 10;

    // Initialize another instance of struct 'StructWithArray' as 's1' and set its first array element to 15 (others are default)
    StructWithArray s1 = { };
    s1.arr[0] = 15;

    // Create a pointer 'sPointer' that points to the instance of struct 'StructWithArray' - 's'
    StructWithArray* sPointer = &s;

    // Using the pointer, modify the first element of the array in 's' to 20
    sPointer->arr[0] = 20;

    // Output the modified value of 's.arr[0]'
    std::cout << s.arr[0] << std::endl;

    // Modify the first element of the array in 's' directly to 25
    s.arr[0] = 25;
    std::cout << s.arr[0] << std::endl;

    // Using the pointer again, modify the first element of the array in 's' to 30
    sPointer->arr[0] = 30;
    std::cout << s.arr[0] << std::endl;

    // Change the pointer to point to 's1' instead of 's'
    sPointer = &s1;

    // Using the pointer, modify the first element of the array in 's1' to 35
    sPointer->arr[0] = 35;

    // Output the values of 's.arr[0]' and 's1.arr[0]'
    std::cout << s.arr[0] << std::endl;  // Outputs '30' since 's' wasn't modified after switching the pointer
    std::cout << s1.arr[0] << std::endl; // Outputs '35' (the new value assigned to 's1' in the previous step)

    // Define an array of two 'StructWithArray' instances
    StructWithArray structArray[2] = { };

    // Set the 4th element of the array in the first 'StructWithArray' to 77
    structArray[0].arr[3] = 77;

    // Set the 'someNumber' pointer of the second 'StructWithArray' to point to the 4th element of the first array
    structArray[1].someNumber = &structArray[0].arr[3];

    // Point 'sPointer' back to 's'
    sPointer = &s;

    // Create a pointer to the 4th element of 's.arr'
    int* pointer = &sPointer->arr[3];

    // Modify the 4th element of 's.arr' to 72
    s.arr[3] = 72;

    // Output the value pointed to by 'pointer' which points to 's.arr[3]'
    std::cout << *pointer << std::endl;  // Outputs '72'

    // Declare an instance of 'StructWithArray' named 'memory' and initialize it to all zeros using 'memset' function
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));

    return 0;
}