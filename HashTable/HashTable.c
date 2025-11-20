#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* buckets[16]; // Array of pointers to nodes

// Function to insert an element into the hash table
void InsertElement() {
    int element;
    printf("Enter the element: ");
    scanf("%d", &element);

    int index = (element % 16 + 16) % 16; // Handle negative indices

    // Check if the element already exists in the hash table at the computed index
    struct Node* temp = buckets[index];
    while (temp) {
        if (temp->data == element) {
            printf("The element is already present in the hash table.\n");
            return;
        }
        temp = temp->next;
    }

    // Create a new node and add it to the linked list in the correct bucket
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = element;
    newnode->next = buckets[index];
    buckets[index] = newnode;

    printf("Data added: %d\n", element);
}

// Function to remove an element from the hash table
void RemoveElement() {
    int element;
    printf("Enter the element to remove: ");
    scanf("%d", &element);

    int index = (element % 16 + 16) % 16; // Handle negative indices
    struct Node* temp = buckets[index];
    struct Node* prev = NULL;

    while (temp) {
        if (temp->data == element) {
            // Found the element, remove it from the list
            if (prev) {
                prev->next = temp->next;
            }
            else {
                buckets[index] = temp->next;
            }
            free(temp);
            printf("The element %d is removed from the hash table.\n", element);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("The element %d is not present in the hash table.\n", element);
}

// Function to search for an element in the hash table
void SearchElement() {
    int element;
    printf("Enter the element to search: ");
    scanf("%d", &element);

    int index = (element % 16 + 16) % 16; // Handle negative indices
    struct Node* temp = buckets[index];
    int pos = 0;

    while (temp) {
        if (temp->data == element) {
            printf("The element %d is present in the hash table.\n", element);
            printf("Bucket No.: %d\nIndex No.: %d\n", index, pos);
            return;
        }
        pos++;
        temp = temp->next;
    }

    printf("The element %d is not present in the hash table.\n", element);
}

// Function to display the entire hash table
void Display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < 16; i++) {
        printf("Bucket %d: ", i);
        struct Node* temp = buckets[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize all buckets to NULL
    for (int i = 0; i < 16; i++) {
        buckets[i] = NULL;
    }

    int quantity;
    printf("How many elements do you want to add? ");
    scanf("%d", &quantity);

    // Insert elements into the hash table
    for (int i = 0; i < quantity; i++) {
        InsertElement();
    }

    // Display the hash table
    Display();

    // Remove an element from the hash table
    RemoveElement();
    Display();

    // Search for an element in the hash table
    SearchElement();

    return 0;
}
