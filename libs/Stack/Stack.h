#pragma once
#include "List/List.h"

template<typename T>
class Stack {
private:
    List<T> list;

public:
    void push(const T& value) {
        list.push_back(value);
    }

    void pop() {
        if (empty()) {
            throw std::runtime_error("Stack is empty!");
        }
        list.pop_back();
    }

    T& top() {
        if (empty()) {
            throw std::runtime_error("Stack is empty!");
        }
        return list.back();
    }

    const T& top() const {
        if (empty()) {
            throw std::runtime_error("Stack is empty!");
        }
        return list.back();
    }

    bool empty() const {
        return list.empty();
    }

    size_t size() const {
        return list.size();
    }
};