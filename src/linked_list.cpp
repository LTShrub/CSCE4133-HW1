#include <linked_list.hpp>

template<class T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T>* next, LinkedListNode<T>* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
    this->next = NULL;
}


template<class T>
LinkedList<T>::LinkedList() {
     this->root = NULL;
}

template<class T>
LinkedList<T>::~LinkedList() {
LinkedListNode<T>* current = this->root;
while (current != nullptr) {
        LinkedListNode<T>* next = current->next;
        delete current;  
        current = next;
    }
    this->root = nullptr;
}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
    LinkedListNode<T>* newNode = new LinkedListNode<T>(value, this->root, nullptr);
    this->root = newNode;

    return newNode;
}

template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {
    LinkedListNode<T>* current = this->root; 
    while (current != nullptr) {
        if (current->value == value) {
            return current; 
        }
        current = current->next; 
    }
    return nullptr;
}

template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
    LinkedListNode<T>* current = this->root;
    LinkedListNode<T>* prev = nullptr;
    while(current != nullptr){
        if(current->value == value){
            if(prev != nullptr){
                prev->next = current->next;
            }else{
                this->root = current->next;
            }
            LinkedListNode<T>* nextNode = current->next;

            delete current;

            return nextNode;
        } 
        prev = current;
        current = current->next;
    }
    return nullptr;
}

template<class T>
int LinkedList<T>::size() {
LinkedListNode<T>* current = this->root;
int count = 0;
while (current != nullptr) {
        LinkedListNode<T>* next = current->next;
        count++;  
        current = next;
    }
    return count;
}

template class LinkedListNode<int>;
template class LinkedList<int>;
