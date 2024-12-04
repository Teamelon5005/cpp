#include "dynamicArray.h"

int main() {
    // Test default constructor and add method
    DynamicArray<int> arr;
    assert(arr.getSize() == 0);
    arr.add(10);
    assert(arr.getSize() == 1);
    assert(arr[0] == 10);

    // Test constructor with capacity
    DynamicArray<int> arrWithCapacity(2);
    arrWithCapacity.add(20);
    arrWithCapacity.add(30);
    assert(arrWithCapacity[0] == 20);
    assert(arrWithCapacity[1] == 30);

    // Test resizing
    arrWithCapacity.add(40); // This should trigger resizing
    assert(arrWithCapacity.getCapacity() == 4);

    // Test copy constructor
    DynamicArray<int> copyArr = arrWithCapacity;
    assert(copyArr.getSize() == arrWithCapacity.getSize());
    assert(copyArr.getCapacity() == arrWithCapacity.getCapacity());
    for(size_t i = 0; i < copyArr.getSize(); i++)
        assert(copyArr[i] == arrWithCapacity[i]);


    // Test move constructor
    DynamicArray<int> movedArr = std::move(arrWithCapacity);
    assert(movedArr.getSize() == 3);
    assert(movedArr.getCapacity() == 4);
    assert(movedArr[0] == 20);
    assert(movedArr[1] == 30);
    assert(movedArr[2] == 40);

    // Test assignment operator
    DynamicArray<int> assignedArr;
    assignedArr = copyArr;
    assert(assignedArr.getSize() == copyArr.getSize());
    assert(assignedArr.getCapacity() == copyArr.getCapacity());
    for(size_t i = 0; i < assignedArr.getSize(); i++)
        assert(assignedArr[i] == copyArr[i]);

    // Test span method
    std::span<int> span = copyArr.getCurrentSpan();
    assert(span.size() == copyArr.getSize());
    for (size_t i = 0; i < span.size(); ++i)
        assert(span[i] == copyArr[i]);

    // Clean up is automatic due to the destructor
    return 0;
}
