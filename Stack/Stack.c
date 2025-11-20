#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node in the stack
struct Node {
    int data;               // Holds the data of the node
    struct Node* next;      // Pointer to the next node in the stack
};

struct Node* head = NULL;   // Initialize the stack as empty

// Function to push an element onto the stack
void Push(struct Node** head) {
    int data;
    printf("\nEnter the element: ");
    scanf("%d", &data);

    // Allocate memory for a new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = data;  // Assign data to the new node
    newnode->next = NULL;   // Set the next pointer of the new node to NULL

    // If the stack is empty, the new node becomes the head of the stack
    if (*head == NULL) {
        printf("The Stack is empty.\n");
        *head = newnode;   // Set head to point to the new node
        printf("The element %d is pushed at the top of the stack.\n", data);
        return;
    }

    // If the stack is not empty, push the new node onto the top of the stack
    newnode->next = *head;  // Point new node to the current top of the stack
    *head = newnode;        // Update the head to the new node
    printf("The element %d is pushed at the top of the stack.\n", data);
}

// Function to pop an element from the stack
void Pop(struct Node** head) {
    // Check if the stack is empty
    if (*head == NULL) {
        printf("The Stack is empty.\n");
        return;
    }

    // Get the data from the top of the stack
    int data = (*head)->data;

    // Remove the top node from the stack
    struct Node* temp = *head;
    *head = (*head)->next;  // Update the head to the next node

    // Free the memory of the popped node
    free(temp);

    printf("The element %d is popped from the stack.\n", data);
}

// Function to peek the top element of the stack
void Peek(struct Node* head) {
    // Check if the stack is empty
    if (head == NULL) {
        printf("The Stack is empty.\n");
        return;
    }

    // Print the data at the top of the stack
    printf("The element %d is at the top of the stack.\n", head->data);
}

// Function to print all elements of the stack
void Print(struct Node* head) {
    printf("\n\nDisplay Elements\n");

    // Check if the stack is empty
    if (head == NULL) {
        printf("The Stack is empty.\n");
        return;
    }

    // Traverse through the stack and print each element
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main() {
    printf("\n---------------Stack----------------\n\n");

    printf("Inserting Elements\n");
    // Push 5 elements onto the stack
    for (int i = 0; i < 5; i++) {
        Push(&head);
    }

    // Display the stack
    Print(head);

    // Pop an element from the stack
    Pop(&head);

    // Display the stack after pop
    Print(head);

    // Peek at the top element of the stack
    Peek(head);

    // Free all remaining nodes in the stack
    while (head != NULL) {
        Pop(&head);  // Pop and free each element until the stack is empty
    }

    return 0;
}
