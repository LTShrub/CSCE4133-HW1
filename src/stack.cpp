#include <stack.hpp>

template<class T>
StackNode<T>::StackNode(T value, StackNode<T> *next, StackNode<T> *prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
StackNode<T>::~StackNode() {
    this->next = this->prev = NULL;
}

template<class T>
Stack<T>::Stack() {
    this->head = this->tail = NULL;
}

template<class T>
Stack<T>::~Stack() {
    while(head != NULL){
        StackNode<T> *temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
}

template<class T>
bool Stack<T>::empty() {
    return head == nullptr;
}

template<class T>
T Stack<T>::pop() {
    T value = this->head->value;
    StackNode<T> *temp = this->head;
    this->head = this->head->next;
    delete temp;

    return value;
}

template<class T>
void Stack<T>::push(T value) {
    StackNode<T> *p = new StackNode<T>(value, NULL, NULL);
    if(this->empty()){
        this->head = this->tail = p;
    }else{
        p->next = this->head;
        this->head->prev = p;
        this->head = p;
    }
}

template class Stack<int>;
