#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert in order
void insertInOrder(Node** head, int new_data) {
    // Create new node
    Node* newNode = createNode(new_data);
    
    // Case 1: Empty list or new node should be at the beginning
    if (*head == NULL || (*head)->data >= new_data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    // Case 2: Insert in the middle or at the end
    Node* current = *head;
    while (current->next != NULL && current->next->data < new_data) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the list (for testing)
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the list (memory management)
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Main function for testing
int main() {
    Node* head = NULL;
    
    // Test cases
    insertInOrder(&head, 5);
    insertInOrder(&head, 3);
    insertInOrder(&head, 8);
    insertInOrder(&head, 1);
    insertInOrder(&head, 6);
    
    printf("Ordered list: ");
    printList(head);
    
    // Free memory
    freeList(head);
    
    return 0;
}