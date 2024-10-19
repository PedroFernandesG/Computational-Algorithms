#include <iostream>
#include "DynamicQueue.h"

using namespace std;

DynamicQueue::DynamicQueue(){
    first = NULL;
    last = NULL;
}
DynamicQueue::~DynamicQueue(){
    Node *temp;

    while(first != NULL){
        temp = first;
        first = first->next;
        delete temp;
    } 
    last = NULL;
}
bool DynamicQueue::isFull(){

    Node *tempNode;
    try{
        tempNode = new Node;
        delete tempNode;
        return 0;

    }catch(bad_alloc exception){
        cout << "Error" << endl;
        return  1;
    }
}
bool DynamicQueue::isEmpty(){
    if(first == NULL){
        return 1;
    }
    return 0;

}
void DynamicQueue::push(TypeItem element){

    if(isFull()){
        cout << "The Queue is Empty " << endl;
    }else{
        Node *newNode = new Node;
        newNode->value = element;
        newNode->next = NULL;
        if(first == NULL){
            first = newNode;
        }else{
            last->next = newNode;
        }
        last = newNode;
    }
}
TypeItem DynamicQueue::pop(){

    if(isEmpty()){
        cout << "The queue is empty " << endl;
    }else{
        Node *newNode;
        newNode = first;
        TypeItem value = newNode->value;
        first = first->next;
        if(first == NULL){
            last == NULL;
        }
        delete newNode;
        return value;
    }
}
void DynamicQueue::show(){
    
    if(isEmpty()){
        cout << "The queue is empty " << endl;
    }else{
        Node* tempNode = first;
        int count = 1;
        while(tempNode != NULL){
            
            cout << "Element " << count << " -->" << tempNode->value;
            tempNode = tempNode->next;
            count++;
        }
    }
}
void DynamicQueue::getSize(){
    Node* tempNode = first;
    int count = 0;
    while(tempNode != NULL){
        tempNode = tempNode->next;
        count++;
    }
    cout << "Size --> " << count << endl;
}