#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* next;//pointer to structure node
};

// Function to build a linked list with nodes containing the values 1, 2, and 3
struct node* BuildOneTwoThree() {
    // Declare pointers for the nodes
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    // Allocate memory for the three nodes
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    // Check if memory allocation was successful
    if (head == NULL || second == NULL || third == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Assign values and set up links between the nodes
    head->data = 5;
    head->next = second;
    second->data = 6;
    second->next = third;
    third->data = 7;
    third->next = NULL;

    // Return the head of the linked list
    return head;
}

// Function to print the linked list
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
