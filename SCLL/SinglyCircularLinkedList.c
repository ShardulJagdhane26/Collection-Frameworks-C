#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node in the circular linked list
struct Node {
    int data;               // Holds the data of the node
    struct Node* next;      // Pointer to the next node in the list
};

// Global head pointer to the circular linked list
struct Node* head = NULL;

// Function to insert an element at the beginning of the circular linked list
void InsertAtFirst(struct Node** head) {
    int data;
    printf("\nEnter the element: ");
    scanf("%d", &data);

    // Allocate memory for the new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, the new node points to itself
        *head = newnode;
        (*head)->next = *head;
        printf("The element %d has been added.\n", (*head)->data);
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Insert the new node at the beginning and update the last node's next pointer
    newnode->next = *head;
    temp->next = newnode;
    *head = newnode;  // Update head to point to the new node
    printf("The element %d has been added.\n", (*head)->data);
}

// Function to insert an element at the end of the circular linked list
void InsertAtLast(struct Node** head) {
    int data;
    printf("\nEnter the element: ");
    scanf("%d", &data);

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, the new node points to itself
        *head = newnode;
        (*head)->next = *head;
        printf("The element %d has been added.\n", (*head)->data);
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newnode;
    newnode->next = *head;  // Point new node to head to maintain circularity
    printf("The element %d has been added.\n", newnode->data);
}

// Function to insert an element at a specific index in the circular linked list
void InsertAtRandom(struct Node** head) {
    int data, index;
    printf("\nEnter the element: ");
    scanf("%d", &data);
    printf("Enter the index: ");
    scanf("%d", &index);

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, the new node points to itself
        *head = newnode;
        (*head)->next = *head;
        printf("The element %d has been added.\n", (*head)->data);
        return;
    }

    struct Node* temp = *head;

    // Traverse to the node just before the desired index
    for (int i = 0; i < index - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    // Insert the new node at the specified position
    newnode->next = temp->next;
    temp->next = newnode;
    printf("The element %d has been added.\n", newnode->data);
}

// Function to delete the first element from the circular linked list
void DeleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (*head == (*head)->next) {
        // If there is only one element in the list, deleting it leaves the list empty
        *head = NULL;
    }
    else {
        // Traverse to the last node to update its next pointer
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;  // Point the last node to the second node
        *head = (*head)->next;       // Update head to the second node
    }

    printf("The first element has been deleted.\n");
}

// Function to delete the last element from the circular linked list
void DeleteAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (*head == (*head)->next) {
        // If there is only one element, deleting it leaves the list empty
        *head = NULL;
    }
    else {
        // Traverse to the second-last node to delete the last node
        while (temp->next->next != *head) {
            temp = temp->next;
        }
        struct Node* toDelete = temp->next;
        temp->next = *head;  // Update the second-last node's next pointer to head
        free(toDelete);      // Free the memory of the deleted node
    }

    printf("The last element has been deleted.\n");
}

// Function to delete an element at a specific index in the circular linked list
void DeleteAtRandom(struct Node** head) {
    int index;
    printf("\nEnter the index: ");
    scanf("%d", &index);

    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // Traverse to the node just before the node to be deleted
    for (int i = 0; i < index - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    if (temp->next == *head) {
        printf("Invalid index.\n");
        return;
    }

    // Delete the node at the specified index
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);

    printf("The element at index %d has been deleted.\n", index);
}

// Function to display all the elements in the circular linked list
void Display(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("\nLinked list elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    printf("\n-----------------Singly Circular Linked List------------\n");

    // Test Insert at First
    printf("\nInsert At First\n");
    for (int i = 0; i < 5; i++) {
        InsertAtFirst(&head);
    }
    Display(head);

    // Test Insert at Last
    InsertAtLast(&head);
    Display(head);

    // Test Insert at Random (insert at index 2)
    InsertAtRandom(&head);
    Display(head);

    // Test Delete at First
    DeleteAtFirst(&head);
    Display(head);

    // Test Delete at Last
    DeleteAtLast(&head);
    Display(head);

    // Test Delete at Random (delete at index 1)
    DeleteAtRandom(&head);
    Display(head);

    return 0;
}
