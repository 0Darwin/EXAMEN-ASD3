#include <stdio.h>
#include "list.h"

Node* reverse_list(Node* head) {
    if (head == NULL){
     return NULL;

    }
   
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = getNext(current);
        setNext(current, getPrev(current));
        setPrev(current, temp);

        head = current;
        current = temp;
    }

    return head;
}