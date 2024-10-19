#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue(){

    sizeQueue = 0;
    queue = new TypeItem[max_itens];

}
Queue::~Queue(){

    delete [] queue;

}
bool Queue::isFull(){
    
    return (sizeQueue == max_itens ? true:false);

}
bool Queue::isEmpty(){

    return (sizeQueue == 0 ? true:false);
}
void Queue::push(TypeItem element){
    
    if(~isFull()){
        queue[sizeQueue] = element;
        sizeQueue++;
    }else{
        cout << "Queue is full" << endl;
    }

}
TypeItem Queue::pop(){

    if(isEmpty()){

        cout << "it's empty" << endl;
    }
    else{
        for(int i = 0;i < sizeQueue- 1;i++){

        queue[i] = queue[i+1];
        }
        queue[sizeQueue - 1] = NULL;
        sizeQueue--;
    }
}
void Queue::show(){

    for(int i = 0;i < sizeQueue;i++){
        cout << "Element " << i + 1 << " --> " << queue[i];
    }
}
void Queue::getSize(){

    cout << "Size is --> " << sizeQueue << endl;
}
