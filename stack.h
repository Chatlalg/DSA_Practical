#ifndef STACK_H
#define STACK_H
#include <iostream>

template <typename T>
class node {
public:
    T data;
    node<T> *next;
};

template <typename T>
class stack {
public:
    node<T> *tos = NULL;
    bool isEmpty();
    void push(T c);
    void pop();
    void display();
    T top();
};

#endif
