#include <stdio.h>
#include <stdlib.h>

// Define the structure for the queue node
struct Node {
    int data;               // Holds the data of the node
    struct Node* next;      // Pointer to the next node in the queue
};

// Global pointers to the front and back of the queue
struct Node* front = NULL;  // Points to the front of the queue
struct Node* back = NULL;   // Points to the back of the queue

// Function to insert an element at the back of the queue
void InsertElement(struct Node** back, struct Node** front) {
    int data;
    printf("Enter the element: ");
    scanf("%d", &data);

    // Allocate memory for the new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    if (*front == NULL && *back == NULL) {
        // If the queue is empty, both front and back will point to the new node
        *front = *back = newnode;
        printf("The element %d is added to the queue.\n", data);
        return;
    }

    // If the queue is not empty, add the new node to the back
    (*back)->next = newnode;
    *back = newnode;
    printf("The element %d is added to the queue.\n", data);
}

// Function to remove an element from the front of the queue
void RemoveElement(struct Node** back, struct Node** front) {
    printf("\nRemove Element\n");

    if (*front == NULL && *back == NULL) {
        // If the queue is empty, there's nothing to remove
        printf("The queue is empty.\n");
        return;
    }

    // If there's only one element in the queue
    if (*front == *back) {
        int temp = (*front)->data;
        *front = *back = NULL;  // Reset both front and back to NULL
        printf("The element %d is removed from the queue.\n", temp);
        return;
    }

    // Remove the front element
    int temp = (*front)->data;
    *front = (*front)->next;  // Move front to the next node
    printf("The element %d is removed from the queue.\n", temp);
}

// Function to display all the elements in the queue
void Display(struct Node* back, struct Node* front) {
    printf("\n-------------- Elements -------------\n");

    if (front == NULL && back == NULL) {
        // If the queue is empty, print a message
        printf("The queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    // Traverse the queue and print each element
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n-------------------------------------\n");
}

// Main function to test the queue operations
int main() {
    printf("\n.................Queue using Linked List................\n");

    // Insert 5 elements into the queue
    printf("\nInsert Elements\n");
    for (int i = 0; i < 5; i++) {
        InsertElement(&back, &front);
    }

    // Display the elements in the queue
    Display(back, front);

    // Remove an element from the queue
    RemoveElement(&back, &front);

    // Display the elements in the queue after removal
    Display(back, front);

    return 0;
}
