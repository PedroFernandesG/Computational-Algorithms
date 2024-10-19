#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(){
    sizeStack = 0;
    stack = new TypeItem[max_itens];
}
Stack::~Stack(){

    delete [] stack;
}
bool Stack::isFull(){
    return (sizeStack == max_itens ? true:false);
}
bool Stack::isEmpty(){
    return (sizeStack == 0 ? true:false);
}
void Stack::push(TypeItem item){

    if(!isFull()){
        stack[sizeStack] = item;
        sizeStack++;
    }else{
        cout << "Stack is Full" << endl;
    }
}
TypeItem Stack::pop(){

    if(~isEmpty()){
        sizeStack--;
        return stack[sizeStack];
    }else{
        cout << "Is empty " << endl;
    }
}
void Stack::show(){

    for(int i = 0;i < sizeStack;i++){
        cout << "Element " << i + 1 << " --> " << stack[sizeStack] << endl;
    }
}
void Stack::size(){
    cout << "Size is --> " << sizeStack << endl;
}