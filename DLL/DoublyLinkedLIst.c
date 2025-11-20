#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;               // The data of the node
    struct Node* next;      // Pointer to the next node in the list
    struct Node* previous;  // Pointer to the previous node in the list
};

struct Node* head = NULL; // Pointer to the head (start) of the doubly linked list

// Function to insert an element at the beginning of the DLL
void InsertAtBeg(struct Node** head) {
    int data;
    printf("Enter the element: ");
    scanf("%d", &data);

    // Create a new node and initialize its values
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->previous = NULL;

    // If the DLL is empty, make the new node the head of the list
    if (*head == NULL) {
        printf("The DLL is empty.\n");
        *head = newnode;
        printf("The element %d has been added.\n", data);
        return;
    }

    // If the list is not empty, insert the new node at the beginning
    newnode->next = *head;
    (*head)->previous = newnode;
    *head = newnode;  // Update the head to the new node
    printf("The element %d has been added.\n", data);
}

// Function to insert an element at the end of the DLL
void InsertAtEnd(struct Node** head) {
    int data;
    printf("Enter the element: ");
    scanf("%d", &data);

    // Create a new node and initialize its values
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->previous = NULL;

    // If the DLL is empty, make the new node the head of the list
    if (*head == NULL) {
        printf("The DLL is empty.\n");
        *head = newnode;
        printf("The element %d has been added.\n", data);
        return;
    }

    // Otherwise, traverse to the end of the list and insert the new node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->previous = temp;  // Link the new node back to the previous node

    printf("The element %d has been added at the end.\n", data);
}

// Function to insert an element at a random index in the DLL
void InsertAtRandom(struct Node** head) {
    int data, index;
    printf("Enter the element: ");
    scanf("%d", &data);
    printf("Enter the index: ");
    scanf("%d", &index);

    // Create a new node and initialize its values
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->previous = NULL;

    // If the DLL is empty, add the new node as the first node
    if (*head == NULL) {
        printf("The DLL is empty.\n");
        *head = newnode;
        printf("The element %d has been added.\n", data);
        return;
    }

    // Traverse the list until the specified index
    struct Node* temp = *head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If the index is out of bounds, print an error message
    if (temp == NULL) {
        printf("Invalid index.\n");
        free(newnode);
        return;
    }

    // Insert the new node at the specified index
    newnode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->previous = newnode;  // Adjust the previous pointer of the next node
    }
    temp->next = newnode;
    newnode->previous = temp;  // Link the new node to the previous node

    printf("The element %d has been added at index %d.\n", data, index);
}

// Function to delete the first element of the DLL
void DeleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("The DLL is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;  // Update the head to the second node
    if (*head != NULL) {
        (*head)->previous = NULL;  // Update the previous pointer of the new head
    }

    printf("The first element %d has been deleted.\n", temp->data);
    free(temp);  // Free the memory allocated for the deleted node
}

// Function to delete the last element of the DLL
void DeleteAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("The DLL is empty.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;  // Traverse to the last node
    }

    if (temp->previous != NULL) {
        temp->previous->next = NULL;  // Remove the last node from the list
    }
    else {
        *head = NULL;  // If there was only one node, set the head to NULL
    }

    printf("The last element %d has been deleted.\n", temp->data);
    free(temp);  // Free the memory allocated for the deleted node
}

// Function to delete an element at a random index in the DLL
void DeleteAtRandom(struct Node** head) {
    int index;
    printf("Enter the index to delete: ");
    scanf("%d", &index);

    if (*head == NULL) {
        printf("The DLL is empty.\n");
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;  // Traverse the list to the desired index
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid index.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->previous = temp;  // Adjust the previous pointer of the next node
    }

    printf("The element %d at index %d has been deleted.\n", nodeToDelete->data, index);
    free(nodeToDelete);  // Free the memory allocated for the deleted node
}

// Function to display all the elements in the DLL
void Display(struct Node* head) {
    printf("\nDisplay Elements\n");
    if (head == NULL) {
        printf("The DLL is empty.\n");
        return;
    }
    printf("Linked list elements:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);  // Print the data of each node
        temp = temp->next;  // Move to the next node
    }
    printf("\n\n");
}

// Main function where the user can interact with the DLL
int main() {
    printf("\n---------------Doubly Linked List----------------\n\n");

    // Insert elements at the beginning of the DLL
    printf("Inserting Elements\n");
    for (int i = 0; i < 5; i++) {
        InsertAtBeg(&head);  // Call the function to insert an element at the beginning
    }
    Display(head);  // Display the current DLL

    InsertAtEnd(&head);  // Insert an element at the end
    Display(head);

    InsertAtRandom(&head);  // Insert an element at a random index
    Display(head);

    DeleteAtFirst(&head);  // Delete the first element
    Display(head);

    DeleteAtLast(&head);  // Delete the last element
    Display(head);

    DeleteAtRandom(&head);  // Delete an element at a random index
    Display(head);  // Display the final state of the DLL

    return 0;
}
