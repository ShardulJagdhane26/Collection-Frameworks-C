#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly circular linked list node
struct Node {
    int data;               // The data of the node
    struct Node* next;      // Pointer to the next node in the list
    struct Node* previous;  // Pointer to the previous node in the list
};

struct Node* head = NULL; // Pointer to the head (start) of the doubly circular linked list

// Function to insert an element at the first position in the DLL
void InsertAtFirst(struct Node** head) {
    int data;
    printf("Enter the element: ");
    scanf("%d", &data);

    // Create a new node and initialize its values
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->previous = NULL;

    // If the list is empty, the new node points to itself (circular linked list)
    if (*head == NULL) {
        printf("The DCLL is empty.\n");
        *head = newnode;
        (*head)->next = *head;
        (*head)->previous = *head;
        printf("The element %d has been added.\n", (*head)->data);
        return;
    }

    // Insert the new node at the beginning (adjust pointers)
    newnode->next = *head;
    newnode->previous = (*head)->previous;
    (*head)->previous->next = newnode;
    (*head)->previous = newnode;
    *head = newnode; // Update the head to the new node
    printf("The element %d has been added.\n", data);
}

// Function to insert an element at the last position in the DLL
void InsertAtLast(struct Node** head) {
    int data;
    printf("Enter the element: ");
    scanf("%d", &data);

    // Create a new node and initialize its values
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->previous = NULL;

    // If the list is empty, the new node points to itself (circular linked list)
    if (*head == NULL) {
        printf("The DLL is empty.\n");
        *head = newnode;
        (*head)->next = *head;
        (*head)->previous = *head;
        printf("The element %d has been added.\n", data);
        return;
    }

    // Insert the new node at the end (adjust pointers)
    newnode->next = *head;
    newnode->previous = (*head)->previous;
    (*head)->previous->next = newnode;
    (*head)->previous = newnode;
    printf("The element %d has been added.\n", data);
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

    // If the list is empty, the new node points to itself (circular linked list)
    if (*head == NULL) {
        printf("The DLL is empty.\n");
        *head = newnode;
        (*head)->next = *head;
        (*head)->previous = *head;
        printf("The element %d has been added.\n", data);
        return;
    }

    struct Node* temp = *head;
    // Traverse to the node at the specified index (index starts from 0)
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    // Insert the new node at the specified position
    newnode->next = temp->next;
    temp->next->previous = newnode;
    temp->next = newnode;
    newnode->previous = temp;
    printf("The element %d has been added.\n", data);
}

// Function to delete the first element in the DLL
void DeleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("The DLL is empty.\n");
        return;
    }

    // Update the pointers to remove the first node
    (*head)->previous->next = (*head)->next;
    (*head)->next->previous = (*head)->previous;
    struct Node* temp = *head;  // Save the current head node
    *head = (*head)->next;      // Update head to the next node
    printf("The first element is deleted.\n");
    free(temp);  // Free the memory of the deleted node
}

// Function to delete the last element in the DLL
void DeleteAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("The DLL is empty.\n");
        return;
    }

    // Update the pointers to remove the last node
    (*head)->previous->previous->next = *head;
    (*head)->previous = (*head)->previous->previous;
    printf("The last element is deleted.\n");
}

// Function to delete an element at a random index in the DLL
void DeleteAtRandom(struct Node** head) {
    if (*head == NULL) {
        printf("The DLL is empty.\n");
        return;
    }

    int index;
    printf("Enter the index: ");
    scanf("%d", &index);

    struct Node* temp = *head;
    // Traverse to the node at the specified index (index starts from 0)
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    // Update pointers to delete the node at the specified index
    temp->next->next->previous = temp;
    temp->next = temp->next->next;
    printf("The element at index %d is deleted.\n", index);
}

// Function to display all the elements in the DLL
void Display(struct Node* head) {
    if (head == NULL) {
        printf("The DLL is empty.\n");
        return;
    }

    printf("Linked list elements:\n");
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);  // Print the data of each node
        temp = temp->next;          // Move to the next node
    } while (temp != head);        // Stop when we complete a full circle
    printf("\n\n");
}

int main() {
    // Create and interact with the doubly circular linked list

    printf("\n---------------Doubly Circular Linked List----------------\n\n");

    // Insert elements at the beginning of the DLL
    printf("Inserting Elements\n");
    for (int i = 0; i < 5; i++) {
        InsertAtFirst(&head);  // Call the function to insert an element at the first position
    }
    Display(head);  // Display the current DLL

    // Insert an element at the last position
    InsertAtLast(&head);
    Display(head);  // Display the current DLL

    // Insert an element at a random index
    InsertAtRandom(&head);
    Display(head);  // Display the current DLL

    // Delete the first element
    DeleteAtFirst(&head);
    Display(head);  // Display the current DLL

    // Delete the last element
    DeleteAtLast(&head);
    Display(head);  // Display the current DLL

    // Delete an element at a random index
    DeleteAtRandom(&head);
    Display(head);  // Display the current DLL

    return 0;
}
