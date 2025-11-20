#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;               // Data to store the value of the node
    struct Node* next;      // Pointer to the next node in the linked list
};

// Global head pointer to keep track of the linked list
struct Node* head = NULL;

// Function to insert an element at the beginning of the list
void InsertAtFirst(struct Node** head) {
    int element;
    printf("Enter the element: ");
    scanf("%d", &element);

    // Allocate memory for the new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = element;
    newnode->next = *head;  // Link the new node to the current head
    *head = newnode;        // Update the head pointer to the new node

    printf("The element %d is inserted at the beginning.\n", element);
}

// Function to insert an element at the end of the list
void InsertAtLast(struct Node** head) {
    printf("Insert At End\n");

    int element;
    printf("Enter the element: ");
    scanf("%d", &element);

    // Allocate memory for the new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = element;
    newnode->next = NULL;   // The new node will be the last node

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newnode;
        printf("The linked list is empty. The element %d is inserted at the end.\n", element);
        return;
    }

    // Traverse to the last node and update its next pointer to the new node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;

    printf("The element %d is inserted at the end.\n", element);
}

// Function to insert an element at a specific position in the list
void InsertAtRandom(struct Node** head) {
    printf("\nInsert At Random Position\n");
    int index, element;

    printf("Enter the index: ");
    scanf("%d", &index);

    printf("Enter the element: ");
    scanf("%d", &element);

    // Allocate memory for the new node
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = element;
    newnode->next = NULL;

    // If the list is empty, the new node becomes the head
    if (*head == NULL) {
        *head = newnode;
        printf("The linked list is empty. The element %d is inserted.\n", element);
        return;
    }

    // Traverse to the specified index - 1 position
    struct Node* temp = *head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If the index is valid, insert the new node
    if (temp != NULL) {
        newnode->next = temp->next;
        temp->next = newnode;
        printf("The element %d is inserted at the index %d.\n", element, index);
    }
    else {
        printf("Invalid index!\n");
        free(newnode);  // Free the allocated memory if insertion failed
    }
}

// Function to delete the first node in the list
void DeleteAtFirst(struct Node** head) {
    printf("Delete At First\n");

    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    // Temporarily store the current head
    struct Node* temp = *head;
    *head = (*head)->next;  // Update the head pointer to the next node
    free(temp);  // Free the memory of the removed node

    printf("The first element has been deleted.\n");
}

// Function to delete the last node in the list
void DeleteAtLast(struct Node** head) {
    printf("Delete At Last\n");

    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // If the list only contains one node, delete it
    if (temp->next == NULL) {
        free(temp);  // Free the memory of the last node
        *head = NULL;  // Set head to NULL since the list is now empty
        printf("The last element has been deleted.\n");
        return;
    }

    // Traverse to the second-last node
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);  // Free the memory of the last node
    temp->next = NULL; // Set the second-last node's next pointer to NULL

    printf("The last element has been deleted.\n");
}

// Function to delete a node at a specific index
void DeleteAtRandom(struct Node** head) {
    printf("Delete At Random\n");

    if (*head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    int index;
    printf("Enter the index of the element: ");
    scanf("%d", &index);

    struct Node* temp = *head;

    // Traverse to the node before the one to delete
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);  // Free the memory of the node to delete
        printf("The element at index %d has been deleted.\n", index);
    }
    else {
        printf("Invalid index!\n");
    }
}

// Function to find the location of an element in the list
void FindLoc(struct Node* head) {
    printf("Find Location\n");

    int element;
    printf("Enter the element: ");
    scanf("%d", &element);

    int i = 0;
    struct Node* temp = head;

    // Traverse the list and search for the element
    while (temp != NULL && temp->data != element) {
        temp = temp->next;
        i++;
    }

    if (temp != NULL) {
        printf("The element %d is at index: %d\n", element, i);
    }
    else {
        printf("Element not found in the list.\n");
    }
}

// Function to reverse the linked list
void Reverse(struct Node** head) {
    printf("Reversing the linked list...\n");

    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    // Traverse and reverse the list
    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev and current one step forward
        current = next;
    }

    *head = prev;  // Update the head to point to the new first node
    printf("The linked list has been reversed.\n");
}

// Function to display all the elements in the linked list
void DisplayElements(struct Node* head) {
    printf("\nDisplay Elements\n");

    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked list elements: \n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int main() {
    printf("\n..............Singly Linked List......... \n\n");

    printf("Adding Elements\n");
    int quantity;
    printf("Enter the number of elements to add: ");
    scanf("%d", &quantity);

    // Insert elements at the beginning
    for (int i = 0; i < quantity; i++) {
        InsertAtFirst(&head);
    }

    DisplayElements(head);

    // Uncomment the following functions as needed:
    // InsertAtLast(&head);
    // InsertAtRandom(&head);
    // DeleteAtFirst(&head);
    // DeleteAtLast(&head);
    // DeleteAtRandom(&head);
    // FindLoc(head);
    // Reverse(&head);
    // DisplayElements(head);

    return 0;
}
