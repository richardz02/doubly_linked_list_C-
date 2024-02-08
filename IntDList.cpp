/*
.cpp file that implements intDList.hpp file definitions. Only modify this file
*/

// Richard Zhou
// Rima El Brouzi

#include "IntDList.hpp"
#include <iostream>
#include <sstream>


IntDLList::IntDLList() {

    // Initialize ListHead
    ListHead = nullptr;
}


IntDLList::~IntDLList() {

    IntDLLNode* current = ListHead;

    // Destructor to delete every single node
    while (current != nullptr) {
        IntDLLNode* next = current->next;
        delete current;
        current = next;
    }

    ListHead = nullptr;
}

void IntDLList::insertInOrder(int value) {
    IntDLLNode* current;
    IntDLLNode* previous;
    IntDLLNode* temp = new IntDLLNode(value);


    // If the linked list is empty, set new node to be head
    if (!ListHead) {
        temp->prev = nullptr;
        temp->next = nullptr;
        ListHead = temp;
    }

    // Find position to insert
    for (previous = nullptr, current = ListHead; 
        current != nullptr && current->info < value; 
        previous = current, current = current->next);

    if (!previous) {
        // Insert node at the beginning of the linked list
        temp->prev = nullptr;
        temp->next = current;
        if (current) {
            current->prev = temp;
        }
        ListHead = temp;        
    } else {
        // Insert in the middle or end of the linked list
        previous->next = temp;
        temp->prev = previous;
        temp->next = current;
        if (current) {
            current->prev = temp;
        }
    }
}


void IntDLList::addToTail(int value) {
    IntDLLNode* newNode = new IntDLLNode(value);

    // If the linked list is empty, make the new node the ListHead in the linked list
    if (ListHead == nullptr) {
        ListHead = newNode;
    }

    // Traverse to the last node in the linked list
    IntDLLNode* current = ListHead;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Update new node's next and prev pointer
    current->next = newNode;
    newNode->prev = current;
    newNode->next = nullptr;
}


int IntDLList::deleteFromHead() {
    int value;

    IntDLLNode* temp = ListHead;
    value = temp->info;
    ListHead = ListHead->next;
    ListHead->prev = nullptr;
    delete temp;

    return value;
} 


int IntDLList::deleteFromTail() {
    // If the linked list in empty, return 0
    if (!ListHead) {
        return 0;
    }

    int value;
    IntDLLNode* current = ListHead;

    // Traverse to the last node in the linked list
    while (current->next != nullptr) {
        current = current->next;
    }
    
    // Does deleting the node automatically make the previous node point to nullptr?
    value = current->info;
    delete current;

    return value;
}  


void IntDLList::deleteNode(int value) {
    // If linked list is empty, return
    if (!ListHead) {
        return;
    }

    IntDLLNode* previous;
    IntDLLNode* current;

    // Traverse through the linked list and stop when counter the value to delete
    for (previous = nullptr, current = ListHead; current != nullptr && current->info != value; previous = current, current = current->next);

    // If deleteNode is ListHead
    if (current == ListHead) {
        ListHead = ListHead->next;
        ListHead->prev = nullptr;
        delete current;
    }

    if (current->next != nullptr) {
        IntDLLNode* temp;
        temp = current->next;
        previous->next = temp;
        temp->prev = previous;
        delete current;
    } else {
        previous->next = nullptr;
        delete current;
    }
}


bool IntDLList::isInList(int value) const {
    for (IntDLLNode* current = ListHead; current != nullptr; current = current->next) {
        if (current->info == value) {
            return true;
        }
    }

    return false; 
}


string IntDLList::addToString() const {
    
    // If the linked list is empty, return
    if (!ListHead) {
        return "";
    }

    // declare stringstream, traverse through linked list and add each node's value to the stream
    std::stringstream ss;
    for (IntDLLNode* current = ListHead; current != nullptr; current = current->next) {
        ss << current->info << " ";
    }

    return ss.str(); 
}

