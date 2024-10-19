#ifndef STACK
#define STACK

typedef int TypeItem;

struct Node{

    TypeItem value;
    Node *next;
};

class DynamicStack{
    private:
        Node* Top;
    public:
        DynamicStack();
        ~DynamicStack();
        bool isEmpty();
        bool isFull();
        void push(TypeItem item);
        TypeItem pop();
        void show();
        void size();
};
#endif