#include "dynamicArray.h"

int main() {
    // Test default constructor and add method
    DynamicArray<int> arr;
    assert(arr.getSize() == 0);
    arr.add(10);
    assert(arr.getSize() == 1);
    assert(arr[0] == 10);
    std::cout << "Added element: " << arr[0] << ", Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << std::endl;

    // Test constructor with capacity
    DynamicArray<int> arrWithCapacity(2);
    arrWithCapacity.add(20);
    arrWithCapacity.add(30);
    std::cout << "Added elements: " << arrWithCapacity[0] << ", " << arrWithCapacity[1] << ", Size: " << arrWithCapacity.getSize() << ", Capacity: " << arrWithCapacity.getCapacity() << std::endl;

    // Test resizing
    arrWithCapacity.add(40); // This should trigger resizing
    std::cout << "After adding one more element: " << arrWithCapacity[2] << ", Size: " << arrWithCapacity.getSize() << ", Capacity: " << arrWithCapacity.getCapacity() << std::endl;

    // Test copy constructor
    DynamicArray<int> copyArr = arrWithCapacity;
    std::cout << "Copy constructor: " << copyArr[0] << ", " << copyArr[1] << ", " << copyArr[2] << ", Size: " << copyArr.getSize() << ", Capacity: " << copyArr.getCapacity() << std::endl;

    // Test move constructor
    DynamicArray<int> movedArr = std::move(arrWithCapacity);
    std::cout << "Move constructor: " << movedArr[0] << ", " << movedArr[1] << ", " << movedArr[2] << ", Size: " << movedArr.getSize() << ", Capacity: " << movedArr.getCapacity() << std::endl;

    // Test assignment operator
    DynamicArray<int> assignedArr;
    assignedArr = copyArr;
    std::cout << "After assignment: " << assignedArr[0] << ", " << assignedArr[1] << ", " << assignedArr[2] << ", Size: " << assignedArr.getSize() << ", Capacity: " << assignedArr.getCapacity() << std::endl;

    // Test span method
    std::span<int> span = copyArr.getCurrentSpan();
    std::cout << "Span size: " << span.size() << ", Elements: ";
    for (size_t i = 0; i < span.size(); ++i)
        std::cout << span[i] << " ";
    std::cout << std::endl;

    // Clean up is automatic due to the destructor
    return 0;
}