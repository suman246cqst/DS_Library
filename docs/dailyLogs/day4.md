# Daily Design Journal – Day 4
## Module - Dynamic Array & Linked List Implementation
**Date:** 09-07-2026

---

## Section 1 — Specific Bug

### Runtime Issue

While implementing the LinkedList, I discovered that directly copying node pointers would lead to incorrect ownership of dynamically allocated memory. If two LinkedList objects shared the same nodes, destroying one object would free memory still referenced by the other, eventually causing invalid memory access and double-free errors during destruction.

This was not a compiler error but a design flaw identified during implementation while reasoning about object lifetime and the Rule of Three.

---

## Section 2 — Failed Attempt

Initially, I focused only on creating the LinkedList structure and implementing member functions without considering how copying should behave. I realized that simply copying the `head` pointer would create a shallow copy where multiple LinkedList objects would reference the same chain of nodes.

This approach failed because:

* Both objects would own the same dynamically allocated memory.
* Destroying one object would invalidate the other object's pointers.
* The copy assignment operator would overwrite existing data without properly releasing previously allocated memory.

To solve this, I redesigned the implementation around **deep copying**.

Instead of copying node addresses, I traversed the source list and reused the already implemented `push_back()` function to construct entirely new nodes for both the copy constructor and the copy assignment operator. Before copying during assignment, the existing list is first destroyed to avoid memory leaks, and self-assignment protection is performed.

---

## Section 3 — Memory Diagram

**Hand-drawn memory diagrams submitted separately.**

The diagrams include:

* LinkedList node layout showing individual heap-allocated nodes connected through `next` pointers.
* Deep-copy process illustrating how a new LinkedList allocates completely new nodes instead of sharing existing node addresses.
* Destructor traversal showing each node being destroyed and deallocated sequentially until the list becomes empty.

---

## Section 4 — Code Reference

### Git Commits

**Commit:** `2dbc7a1`

* Started LinkedList implementation with header file and Rule of Three.
* Refined DynamicArray implementation.
* Updated LinkedList design proposal.

**Files Modified**

* `include/dynamicArray.h`
* `src/dynamicArray.cpp`
* `include/linkedList.h`
* `src/linkedList.cpp`
* `docs/designProposal/linkedListDesignProposal.md`

---

**Commit:** `0d599f1`

* Implemented `push_front()`
* Implemented `push_back()`
* Implemented `pop_front()`
* Implemented `pop_back()`

**Files Modified**

* `include/linkedList.h`
* `src/linkedList.cpp`

---

**Commit:** `d635228`

* Implemented `insertAtIndex()`
* Implemented `deleteAtIndex()`
* Implemented `search()`
* Implemented `get()`
* Implemented `getSize()`
* Implemented `traverse()`

**Files Modified**

* `include/linkedList.h`
* `src/linkedList.cpp`

**Relevant Functions**

* `LinkedList()` (Default Constructor)
* `~LinkedList()`
* `LinkedList(const LinkedList&)`
* `operator=()`
* `push_front()`
* `push_back()`
* `pop_front()`
* `pop_back()`
* `insertAtIndex()`
* `deleteAtIndex()`
* `search()`
* `get()`
* `getSize()`
* `traverse()`

---

## Section 5 — Learning Reflection

Today significantly changed my understanding of implementing data structures with manual memory management. Before writing the LinkedList, I viewed the Rule of Three mainly as a C++ language feature. While implementing it myself, I realized it is fundamentally about **resource ownership** rather than syntax.

I also learned that designing operations to reuse existing functions results in cleaner and more maintainable code. For example, `insertAtIndex()` delegates boundary cases to `push_front()` and `push_back()`, while `deleteAtIndex()` reuses `pop_front()` and `pop_back()`. This reduced duplicate logic and ensured that fixes to boundary operations automatically benefited indexed operations.

Another important realization was the difference between contiguous and non-contiguous memory layouts. Implementing both DynamicArray and LinkedList on the same day highlighted why arrays provide constant-time indexed access through direct address calculation, whereas linked lists require pointer traversal to reach a particular position. This strengthened my understanding of how memory layout directly influences algorithmic complexity and API design, rather than treating time complexities as values to memorize.
