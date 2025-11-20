#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Search Tree (BST) node
struct Node {
    int data;           // The data of the node
    struct Node* right; // Pointer to the right child node
    struct Node* left;  // Pointer to the left child node
};

struct Node* Root = NULL; // Root pointer to the BST

// Function to insert a new element into the BST
void InsertElements(struct Node** Root) {
    int data;
    printf("Enter the element: ");
    scanf("%d", &data);

    // Create a new node and initialize it
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;

    // If the BST is empty, the new node becomes the root
    if (*Root == NULL) {
        printf("The BST is empty.\n");
        *Root = newnode;
        printf("The element %d is added to BST.\n", newnode->data);
        return;
    }

    struct Node* current = *Root;
    struct Node* parent = NULL;

    // Traverse the BST to find the correct position for the new node
    while (1) {
        parent = current;

        if (newnode->data > current->data) {
            current = current->right;
            if (current == NULL) {
                parent->right = newnode; // Insert the node at the right
                printf("The element %d is added to BST.\n", newnode->data);
                return;
            }
        }
        else if (newnode->data < current->data) {
            current = current->left;
            if (current == NULL) {
                parent->left = newnode; // Insert the node at the left
                printf("The element %d is added to BST.\n", newnode->data);
                return;
            }
        }
    }
}

// Function to find the minimum element in the BST (leftmost node)
struct Node* findMin(struct Node* Root) {
    while (Root && Root->left != NULL) {
        Root = Root->left;
    }
    return Root;
}

// Function to remove an element from the BST
struct Node* RemoveElements(struct Node** Root, int key) {
    if (*Root == NULL) {
        return NULL; // Key not found
    }

    if (key < (*Root)->data) {
        (*Root)->left = RemoveElements(&(*Root)->left, key); // Recur on the left subtree
    }
    else if (key > (*Root)->data) {
        (*Root)->right = RemoveElements(&(*Root)->right, key); // Recur on the right subtree
    }
    else {
        // Node to be deleted found

        // Case 1: Node with only one child or no child
        if ((*Root)->left == NULL) {
            struct Node* temp = (*Root)->right;
            free(*Root); // Free the memory of the node to be deleted
            return temp; // Return the right child (can be NULL or a valid node)
        }
        else if ((*Root)->right == NULL) {
            struct Node* temp = (*Root)->left;
            free(*Root); // Free the memory of the node to be deleted
            return temp; // Return the left child (can be NULL or a valid node)
        }

        // Case 2: Node with two children
        // Find the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin((*Root)->right);

        // Copy the inorder successor's data to this node
        (*Root)->data = temp->data;

        // Delete the inorder successor
        (*Root)->right = RemoveElements(&(*Root)->right, temp->data);
    }
    return *Root; // Return the (possibly updated) root
}

// Function to perform inorder traversal (left, root, right)
void DisplayInorder(struct Node* Root) {
    if (Root != NULL) {
        DisplayInorder(Root->left);  // Recur on the left subtree
        printf("%d ", Root->data);   // Print the data of the current node
        DisplayInorder(Root->right); // Recur on the right subtree
    }
}

// Function to perform preorder traversal (root, left, right)
void DisplayPreorder(struct Node* Root) {
    if (Root != NULL) {
        printf("%d ", Root->data);   // Print the data of the current node
        DisplayPreorder(Root->left); // Recur on the left subtree
        DisplayPreorder(Root->right); // Recur on the right subtree
    }
}

// Function to perform postorder traversal (left, right, root)
void DisplayPostorder(struct Node* Root) {
    if (Root != NULL) {
        DisplayPostorder(Root->left);  // Recur on the left subtree
        DisplayPostorder(Root->right); // Recur on the right subtree
        printf("%d ", Root->data);     // Print the data of the current node
    }
}

// Function to search for an element in the BST
void SearchElement(struct Node* Root) {
    printf("\n\nSearching Element\n");

    int element;
    printf("Enter the element to search: ");
    scanf("%d", &element);

    struct Node* temp = Root;

    while (temp != NULL) {
        if (temp->data == element) {
            printf("The element %d is present in the BST.\n", element);
            return;
        }

        if (element > temp->data) {
            temp = temp->right; // Move to the right subtree
        }
        else {
            temp = temp->left; // Move to the left subtree
        }
    }

    printf("The element %d is not present in BST.\n", element);
}

int main() {
    printf("\n.................BST................\n");

    // Insert elements into the BST
    printf("\nInsert Elements\n");
    for (int i = 0; i < 5; i++) {
        InsertElements(&Root); // Insert new elements
    }

    // Display the elements in different orders
    printf("\nDisplay Elements: Inorder\n");
    DisplayInorder(Root);

    printf("\nDisplay Elements: Preorder\n");
    DisplayPreorder(Root);

    printf("\nDisplay Elements: Postorder\n");
    DisplayPostorder(Root);

    // Search for an element in the BST
    SearchElement(Root);

    // Remove an element from the BST
    printf("\nRemove Element\n");

    printf("Enter the element: ");
    int element;
    scanf("%d", &element);
    Root = RemoveElements(&Root, element);  // Update the root after deletion

    // Display the elements again after removal
    printf("\nDisplay Elements: Inorder\n");
    DisplayInorder(Root);

    return 0;
}
