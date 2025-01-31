#include <stdio.h>
#include "list.h"

Node* initializeList() {
    Node* head = createNode(1);
    Node* current = head;

    for (int i = 2; i <= 5; i++) {
        Node* newNode = createNode(i);
        setNext(current, newNode);
        current = newNode;
    }
    return head;
}

//  insert node at the head 
Node* insert_Head(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        setNext(newNode, *head);
        *head = newNode;
    }
    return *head;
}

// insert node in the middle of the list
 void insert_middle(node* head, int x, int position) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node* newNode = createNode(x);
    node* current = head;
    int counter = 0;
    
   while (current != NULL && counter < position - 1) {
        current = getNext(current);
        counter++;
    }

    if (current != NULL) {
        setNext(newNode, getNext(current)); 
        setNext(current, newNode);  
    } else {
        printf("Position is out of bounds.\n");
    }
    
// insert node at the end 
void insert_End(Node* head, int value) {
    Node* newNode = createNode(value);
    Node* current = head;

    while (getNext(current) != NULL) {
        current = getNext(current);
    }
    setNext(current, newNode);
}

}


void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

int main() {
    // Initialize the list
    Node* list = initializeList();
    printf("Initial list:\n");
    printList(list);


    // Insert a value at the head
    printf("Inserting  at the head:\n");
    insert_Head(&list, 0);
    printList(list);
    
   // Insert a value in the middle
    printf("Inserting  in the middle:\n");
   insert_middle(list, 3);
    printList(list);

    // Insert a value at the end
    printf("Inserting  at the end:\n");
    insert_End(list, 6);
    printList(list);

    return 0;
}