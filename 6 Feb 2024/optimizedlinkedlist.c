#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* BuildOneTwoThree() {
    // Allocate memory for three nodes
    struct node* head = (struct node*)malloc(sizeof(struct node) * 3);

    // Assign data values to the nodes
    head[0].data = 1;
    head[1].data = 2;
    head[2].data = 3;

    // Set up the next pointers
    head[0].next = &head[1];
    head[1].next = &head[2];
    head[2].next = NULL;

    // Return the head of the linked list
    return &head[0];
}

void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Build the linked list
    struct node* myList = BuildOneTwoThree();

    // Print the linked list
    printf("Linked list: ");
    printList(myList);

    // Free memory allocated for the linked list
    free(myList);

    return 0;
}
