# Collection-Frameworks-C

A comprehensive implementation of commonly used data structures and collection frameworks in C, built from scratch to understand internal working, memory management, and performance characteristics.

## 🎯 Overview

This repository provides educational implementations of fundamental data structures in C. Each implementation is designed to help developers understand how these structures work at the memory level, making it ideal for interview preparation, academic projects, and algorithm learning.

## ✨ Features

- **Pure C Implementation** - No external dependencies, direct memory management
- **Well-Documented Code** - Clear comments and explanations throughout
- **Interview Ready** - Optimized implementations for technical interviews
- **Educational Focus** - Learn the internals of common data structures
- **Performance Focused** - Understand time and space complexity in practice

## 📚 Data Structures Implemented

- **Linked Lists**
  - Singly Linked List
  - Doubly Linked List
  - Circular Linked List

- **Stack**
  - Array-based Stack
  - Linked List-based Stack

- **Queue**
  - Array-based Queue
  - Linked List-based Queue
  - Circular Queue

- **Trees**
  - Binary Search Tree
  - Tree Traversal (In-order, Pre-order, Post-order)

- **Hash Tables**
  - Hash Map with Collision Handling

- **Dynamic Arrays**
  - Vector Implementation

## 🚀 Getting Started

### Prerequisites
- GCC compiler (or any C compiler)
- Basic knowledge of C and pointers

### Clone the Repository
```bash
git clone https://github.com/ShardulJagdhane26/Collection-Frameworks-C.git
cd Collection-Frameworks-C
```

### Compile and Run
```bash
# Compile a specific data structure
gcc linkedlist.c -o linkedlist

# Run the program
./linkedlist
```

## 💡 Example Usage

### Linked List
```c
Node* head = NULL;
insertAtEnd(&head, 10);
insertAtEnd(&head, 20);
insertAtEnd(&head, 30);
displayList(head);  // Output: 10 -> 20 -> 30
deleteNode(&head, 20);
displayList(head);  // Output: 10 -> 30
```

### Stack
```c
Stack* stack = createStack(5);
push(stack, 100);
push(stack, 200);
push(stack, 300);
printf("%d\n", pop(stack));  // Output: 300
```

### Queue
```c
Queue* queue = createQueue(5);
enqueue(queue, 10);
enqueue(queue, 20);
enqueue(queue, 30);
printf("%d\n", dequeue(queue));  // Output: 10
```

## 📖 Project Structure

```
Collection-Frameworks-C/
├── linkedlist.c
├── stack.c
├── queue.c
├── bst.c
├── hashtable.c
├── vector.c
└── README.md
```

## 🤝 Contributing

Contributions are welcome! To contribute:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 🎓 Learning Resources

- Understand memory allocation and deallocation in C
- Learn pointer manipulation and dynamic memory management
- Study time and space complexity with real implementations
- Prepare for technical interviews and coding challenges

## 💬 Support

If you have questions or suggestions, feel free to open an issue or start a discussion in the repository.
