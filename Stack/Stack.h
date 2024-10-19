#ifndef STACK
#define STACK

typedef int TypeItem;
#define max_itens 10

class Stack{
    private:
        int sizeStack;
        TypeItem* stack;
    public:
        Stack();
        ~Stack();   
        bool isFull();//Verify if stack has elements
        bool isEmpty();//Verify if stack no has elements
        void push(TypeItem item);//push element
        TypeItem pop();//pop element and show which element was removed
        void show();//just show elements 
        void size();//show teh size 
};

#endif