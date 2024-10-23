#pragma once

#include <cassert>
#include <span>
#include <iostream>

template <typename T>
class DynamicArray {
private:
    T* buffer;
    size_t length;
    size_t capacity;

public:
    DynamicArray()
        : buffer(new T[4]), length(0), capacity(4) {}

    DynamicArray(size_t capacity)
        : buffer(new T[capacity]), length(0), capacity(capacity) {}

    DynamicArray(const DynamicArray& other)
        : length(other.length), capacity(other.capacity), buffer(new T[other.capacity]) {
        for (size_t i = 0; i < length; ++i)
            buffer[i] = other.buffer[i];
    }

    DynamicArray(DynamicArray&& other) noexcept
        : buffer(other.buffer), length(other.length), capacity(other.capacity) {
        other.buffer = nullptr;
        other.length = 0;
        other.capacity = 0;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] buffer;
            length = other.length;
            capacity = other.capacity;
            buffer = new T[other.capacity];
            for (size_t i = 0; i < length; ++i)
                buffer[i] = other.buffer[i];
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] buffer;
            buffer = other.buffer;
            length = other.length;
            capacity = other.capacity;
            other.buffer = nullptr;
            other.length = 0;
            other.capacity = 0;
        }
        return *this;
    }

    T& operator[](size_t index) {
        assert(index < length);
        return buffer[index];
    }

    void add(const T& value) {
        if (length >= capacity)
            resize();
        buffer[length] = value;
        length++;
    }

    size_t getSize() const {
        return length;
    }

    size_t getCapacity() const {
        return capacity;
    }

    ~DynamicArray() {
        delete[] buffer;
    }

    std::span<T> getCurrentSpan() const {
        return std::span<T>(buffer, length);
    }

private:
    void resize() {
        size_t newCapacity = capacity * 2;
        T* newBuffer = new T[newCapacity];
        for (size_t i = 0; i < length; ++i)
            newBuffer[i] = buffer[i];
        delete[] buffer;
        buffer = newBuffer;
        capacity = newCapacity;
    }
};