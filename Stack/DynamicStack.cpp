#include "DynamicStack.h"
#include <iostream>

using namespace std;

DynamicStack::DynamicStack(){
    Top == NULL;
}
DynamicStack::~DynamicStack(){

    Node *tempNode;
    while(Top != NULL){
        tempNode = Top;
        Top = Top->next;
        delete tempNode;
    }
}
bool DynamicStack::isEmpty(){
    return (Top == NULL ? true:false);
}
bool DynamicStack::isFull(){

    Node* newNode;
    try{
      newNode = new Node;
      delete newNode;
      return false;
    }catch(bad_alloc exception){
      return true;
    }
}
void DynamicStack::push(TypeItem item){

    if(isFull()){
        cout << "The stack is full " << endl;
    }else{
        Node *newNode = new Node;
        newNode->value = item;
        newNode->next = Top;
        Top = newNode;
    }
}
TypeItem DynamicStack::pop(){
    if(!isEmpty()){
        cout << "Stack empty" << endl;
    }
    else{
        Node *tempNode = new Node;
        tempNode = Top;
        TypeItem item = Top->value;
        Top = Top->next;
        delete tempNode;
        return item;
    }
}
void DynamicStack::show(){

    if(isEmpty()){
        cout << "The stack is empty " << endl;
    }else{
        Node* tempNode = Top;
        int count = 1;
        while(tempNode != NULL){
            cout << "Element " << count << " -->" << tempNode->value;
            tempNode = tempNode->next;
            count++;
        }
    }
}
void DynamicStack::size(){
    Node* tempNode = Top;
    int count = 1;
    while(tempNode != NULL){
        tempNode = tempNode->next;
        count++;
    }

    cout << "Size is --> " << count << endl;
}