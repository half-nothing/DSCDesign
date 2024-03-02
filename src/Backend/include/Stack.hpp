/**********************************************
 * @file Stack.hpp
 * @brief 顺序栈头文件
 * @author Half_nothing
 * @email Half_nothing@163.com
 * @version 1.0.0
 * @date 2024.2.29
 * @license GNU General Public License (GPL)
 **********************************************/
#ifndef DAC_SEQUENTIAL_STACK_H
#define DAC_SEQUENTIAL_STACK_H

#include <exception>
#include <iostream>
#include "LimitedSequentialStructure.h"

/**
 * @class Stack
 * @brief 顺序栈
 * @tparam T 链表存储的数据类型
 */
template<typename T>
class Stack final : public LimitedSequentialStructure<T> {
public:
    Stack() {
        data = new T[capacity];
    }

    Stack(InitList<T> init) {
        data = new T[capacity];
        push(init);
    }

    ~Stack() override{
        delete[] data;
    }

    /**
     *
     * @param src
     */
    void push(const T &src) override {
        if (now < capacity - 1) {
            data[++now] = src;
            return;
        }
        resize(capacity * 2);
        data[++now] = src;
    }

    void push(InitList<T> src) override {
        for (const T &tmp: src) {
            push(tmp);
        }
    }

    T &pop() override {
        if (now == -1) throw std::exception();
        T &temp = data[now--];
        if (now <= capacity / 4 && capacity / 2 >= STACK_MINIMUM_SIZE) {
            resize(capacity / 2);
        }
        return temp;
    }

    T &top() override {
        if (now == -1) throw std::exception();
        return data[now];
    }

    bool isEmpty() override {
        return now == -1;
    }

    void clear() override {
        delete[] data;
        now = -1;
        data = new T[capacity];
    }

    uint size() override {
        return now + 1;
    }

    friend Logger &operator<<(Logger &os, const Stack &stack) {
        os << "Stack Capacity Usage: " << stack.now + 1 << "/" << stack.capacity << std::endl
           << "Content: ";
        for (int i = 0; i < stack.now + 1; ++i) {
            std::cout << stack.data[i] << " ";
        }
        return os;
    }

private:
    T *data = nullptr;
    int now = -1;
    int capacity = STACK_MINIMUM_SIZE;

    void resize(int newSize) {
        capacity = newSize;
        T *temp = data;
        data = new T[capacity];
        for (int i = 0; i < now + 1; ++i) {
            data[i] = temp[i];
        }
        delete[] temp;
    }
};

#endif
