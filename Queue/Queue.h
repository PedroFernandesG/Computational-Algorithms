#ifndef QUEUE
#define QUEUE

typedef int TypeItem;
#define max_itens 10

class Queue{
    private:
        int sizeQueue;
        TypeItem *queue;
    public:

        Queue();
        ~Queue();
        bool isFull();
        bool isEmpty();
        void push(TypeItem element);
        TypeItem pop();
        void show();
        void getSize();

};
#endif