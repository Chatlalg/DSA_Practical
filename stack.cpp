#include <iostream>
#include "stack.h"
using namespace std;

template <typename T>
bool stack<T>::isEmpty(){
    return tos==NULL;
}

template <typename T>
T stack<T>::top(){
    return tos->data;
}

template <typename T>
void stack<T>::push(T c){
    node<T> *temp = new node<T>();
    temp->data = c;

    temp->next = tos;
    tos = temp;
}

template <typename T>
void stack<T>::pop(){
    if(tos != NULL){
        node<T> *temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template <typename T>
void stack<T>::display(){
    node<T> *temp = tos;
    cout << "Displaying Stack... " << endl;

    if (temp == NULL){
        cout << "The stack is empty." << endl;
    }

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
