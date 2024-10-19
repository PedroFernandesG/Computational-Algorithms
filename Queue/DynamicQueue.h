#ifndef QUEUE
#define QUEUE

typedef int TypeItem;

struct Node{

    TypeItem value;
    Node* next;
};

class DynamicQueue{
    private:    
        Node* first;
        Node* last;
    public:
        DynamicQueue();
        ~DynamicQueue();
        bool isFull();
        bool isEmpty();
        void push(TypeItem element);
        TypeItem pop();
        void show();
        void getSize();
};





#endif