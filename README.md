# Criminal Management System

## Overview

The **Criminal Management System** is an application developed in **C++** as a **Data Structures project**. The project demonstrates the practical implementation of multiple data structures and algorithms through a simple record management system. It allows users to manage criminal records, identify high-risk criminals, analyze relationships between criminals, and perform searching, sorting, and statistical operations using different data structures.

## Objectives

* Apply Data Structures concepts in a practical application.
* Develop a menu-driven criminal record management system.
* Implement searching and sorting algorithms.
* Demonstrate graph traversal techniques using BFS and DFS.
* Analyze the efficiency of different data structures and algorithms.

## System Features

* Add new criminal records.
* Delete existing criminal records.
* Display all criminal records.
* Search criminals by ID.
* Sort records by remaining sentence.
* Sort records by crime count.
* View the highest-risk (Most Wanted) criminal.
* Create relationships between criminals (network connections).
* Explore criminal networks using BFS and DFS.
* Generate crime statistics and performance analysis.

## Data Structures Used

### Linked List

Used as the primary data structure to store criminal records dynamically. It allows records to be inserted and deleted efficiently without requiring contiguous memory.

### Array

Used as temporary storage for searching and sorting operations. Records from the linked list are copied into an array before applying sorting algorithms.

### Priority Queue

Maintains criminal records according to their risk level, allowing the system to quickly identify and display the most wanted criminal.

### Graph (Adjacency Matrix)

Represents relationships between criminals. It enables the system to perform BFS and DFS traversals to analyze criminal networks.

## Algorithms Implemented

* **Linear Search:** Searches for a criminal using their unique ID.
* **Bubble Sort:** Sorts criminal records based on the remaining prison sentence.
* **Selection Sort:** Sorts records according to the number of crimes committed.
* **Breadth-First Search (BFS):** Explores the criminal network level by level.
* **Depth-First Search (DFS):** Traverses the network by exploring one path completely before backtracking.

## Working of the System

When the application starts, sample criminal records are loaded into the system. Users interact with a menu-driven interface to perform different operations such as adding, deleting, searching, sorting, and displaying records. Criminal relationships are managed using a graph, while the priority queue maintains the highest-risk criminal. The system also generates basic crime statistics and displays the time complexity of implemented operations.

## Technologies Used

* **Programming Language:** C++
* **Development Environment:** Visual Studio Code
* **Libraries:** `iostream`, `cstring`

## Time Complexity Analysis

| Operation                | Complexity |
| ------------------------ | ---------- |
| Add Criminal             | O(1)       |
| Delete Criminal          | O(n)       |
| Search by ID             | O(n)       |
| Bubble Sort              | O(n²)      |
| Selection Sort           | O(n²)      |
| Priority Queue Insertion | O(n)       |
| BFS                      | O(V + E)   |
| DFS                      | O(V + E)   |

## Learning Outcomes

This project strengthened my understanding of Linked Lists, Arrays, Priority Queues, Graphs, Searching, Sorting, and Graph Traversal algorithms. It also improved my problem-solving skills and demonstrated how multiple data structures can work together to build an efficient application.

## Future Improvements

* Store records using file handling or a database.
* Add update functionality for existing records.
* Implement user authentication.
* Develop a graphical user interface (GUI).
* Add advanced search and reporting features.

## Conclusion

The Criminal Management System successfully demonstrates the practical implementation of fundamental Data Structures and algorithms in C++. By combining multiple data structures within a single application, the project provides an efficient solution for managing criminal records while reinforcing the core concepts learned in the Data Structures course.
