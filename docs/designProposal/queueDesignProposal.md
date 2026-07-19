# Queue Design Proposal

## Overview

The **Queue** is a reusable linear data structure that follows the **First-In-First-Out (FIFO)** principle, where the first element inserted is the first element removed. In the web crawler, the Queue serves as the underlying data structure for the **Frontier** component, ensuring that URLs are processed in the same order they are discovered. This traversal strategy naturally performs **Breadth-First Search (BFS)**, which is well suited for web crawling because it explores pages level by level.

Instead of implementing the Queue from scratch, it is built on top of the **LinkedList** developed in Project 01. The LinkedList has been enhanced with both **head** and **tail** pointers. The **tail** pointer allows insertion at the end of the list in constant time, while the **head** pointer enables constant-time removal from the front. Consequently, both enqueue and dequeue operations execute in **O(1)** time.

The Queue is designed as a reusable component independent of the crawler. Any application requiring FIFO processing can use this implementation without modification.

---

# Section 1 – Public API

## Proposed API

```cpp
template<typename T>
class Queue{
private:
    LinkedList<T> list;
public:

    void enqueue(const T& value);

    T dequeue();

    T& peek();

    int size() const;

};
```

### API Justification

The Queue exposes only the operations required to maintain FIFO ordering.

| Method | Description |
|---------|-------------|
| `enqueue()` | Inserts a new element at the rear of the queue. |
| `dequeue()` | Removes and returns the element at the front of the queue. |
| `peek()` | Returns the front element without removing it. |
| `size()` | Returns the current number of elements stored in the queue. |

No random access operations are provided because a queue processes elements strictly in FIFO order. Restricting the public interface prevents misuse and preserves the queue abstraction.

---

# Section 2 – Internal Representation

The Queue is implemented by reusing the **LinkedList** developed in Project 01.

```
Queue<T>
      │
      ▼
LinkedList<T>
      │
      ▼
+---------+     +---------+     +---------+
| Node    | --> | Node    | --> | Node    |
+---------+     +---------+     +---------+
```

The LinkedList maintains both **head** and **tail** pointers.

```
Head                               Tail
 │                                   │
 ▼                                   ▼

+---------+     +---------+     +---------+
| Node    | --> | Node    | --> | Node    |
+---------+     +---------+     +---------+
```

Each node stores one object of type `T`.

```
Node<T>

-------------------------

T data

Node* next

-------------------------
```

### Queue Operations

The Queue reuses existing LinkedList operations.

| Queue Operation | LinkedList Operation |
|-----------------|---------------------|
| enqueue() | push_back() |
| dequeue() | pop_front() |
| peek() | front() |
| size() | getSize() |

This design avoids code duplication by leveraging an already tested and reusable data structure.

### Memory Diagram

**Hand-drawn memory diagram will be included in the final submission.**

---

# Section 3 – Failure Handling

### Empty Queue

Attempting to remove or access an element from an empty queue is considered an invalid operation.

- `dequeue()` throws a `std::underflow_error` exception if the queue is empty.
- `peek()` throws a `std::underflow_error` exception if the queue is empty.

Throwing exceptions prevents undefined behavior and allows the calling component to handle the error appropriately.

### Memory Allocation Failure

The Queue does not explicitly handle memory allocation failures. Since it is implemented using a `LinkedList`, all node allocations are delegated to the underlying LinkedList implementation. If memory allocation fails while inserting a new node, the standard C++ memory allocation mechanism throws a `std::bad_alloc` exception, which propagates to the calling component unless explicitly handled.

### Invalid Data

The Queue is implemented as a generic template (`Queue<T>`) and accepts any valid object of type `T`. It does not validate the stored data because data validation is application-specific and should be performed by the component using the Queue.

### Queue Overflow

The Queue is dynamically allocated using a LinkedList and therefore has no fixed capacity. It can continue growing until the system runs out of available memory.

---

# Section 4 – Complexity Analysis

Since the LinkedList maintains both head and tail pointers, queue operations execute in constant time.

| Operation | Best | Average | Worst |
|-----------|------|----------|--------|
| enqueue() | O(1) | O(1) | O(1) |
| dequeue() | O(1) | O(1) | O(1) |
| peek() | O(1) | O(1) | O(1) |
| size() | O(1) | O(1) | O(1) |

### Justification

- `enqueue()` inserts a new node at the tail.
- `dequeue()` removes the head node.
- `peek()` directly accesses the head node.
- `size()` returns the maintained node count.

None of these operations require traversal of the linked list.

---

# Section 5 – Future Compatibility

The Queue has been designed as a generic reusable data structure and is not tightly coupled to the web crawler.

Current usage:

```
Crawler
    │
    ▼
Frontier
    │
    ▼
Queue<URLDepth>
```
