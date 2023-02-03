#include "Queue.h"

/**
 * Implement Queue constructor
 */
Queue::Queue() {
    /* YOUR CODE HERE */
    numElements = 0; 
    head = nullptr;
    tail = nullptr; 
}

/**
 * Implement the Queue destructor
 */
Queue::~Queue() {
    /* YOUR CODE HERE */
    clear(); 
    head = nullptr;
    tail = nullptr;


}

/**
 * Implement size() correctly
 */
unsigned int Queue::size() {
    /* YOUR CODE HERE */
    return numElements; 
}

/**
 * Implement clear() correctly without memory leaks
 */
void Queue::clear() {
    /* YOUR CODE HERE */
    
    Node * previous = head; 
    while (head != nullptr){
        head = head->next;
        delete previous; 
        previous = head;
    }
    numElements = 0;
    
}

/**
 * Implement push() correctly
 */
void Queue::push(string s) {
    /* YOUR CODE HERE */
    Node * toAdd = new Node(s); 
    if (head == nullptr){
        head = toAdd; 
        tail = toAdd; 
    }
    else{
        tail->next = toAdd; 
        tail = tail->next; 
        //don't have to reassign head pointer since it is already pointing to end.
    }
    numElements += 1; 
}

/**
 * Implement pop() correctly without memory leaks
 */
string Queue::pop() {
    /* YOUR CODE HERE */
    Node * toDelete = head; 
    string toReturn = head->data; 
    head = head->next; 
    delete toDelete;  
    numElements -= 1; 
    return toReturn; 



}
