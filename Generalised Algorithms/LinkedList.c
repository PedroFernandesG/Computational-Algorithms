#include <stdio.h>

int main(void){

    struct list{
        int value;
        struct list *next;
    };

    struct list Est1, Est2, Est3;
    struct list *hook = &Est1;

    Est1.value = 5;
    Est2.value = 3;
    Est3.value = 8;

    Est1.next = &Est2;
    Est2.next = &Est3;
    Est3.next = NULL;

    while(hook != (struct list*)0){
       printf("%d\n",hook->value);
       hook = hook->next;
    }

    return 0;
}
