# Daily Design Journal 

**Project:** Building a Data Structures Library and Redis Lite  
**Student Name:** Suman Mondal  
**Date:** 08 July 2026

---

# Section 1 — Specific Bug

Today's work consisted of two major tasks:

1. Preparing the **HashMap Design Proposal**.
2. Implementing the **DynamicArray** template.

The design proposal itself did not produce compiler errors because it was purely a design activity. However, while implementing the DynamicArray, I encountered several implementation problems related to dynamic memory management.

Some of the major issues I faced were:

### Problem 1 — Copy Constructor

Initially, the copied object was sharing the same memory as the original object because my implementation was effectively performing a shallow copy. This created the possibility of double deletion when both objects were destroyed.

### Problem 2 — Copy Assignment Operator

While implementing the assignment operator, I was unsure about the correct order of operations.

Questions that arose included:

- Should the existing memory be deleted first?
- What happens during self-assignment?
- How should new memory be allocated safely before copying elements?

This required multiple revisions before arriving at a correct implementation.

### Problem 3 — Object Lifetime During Shifting

The most confusing part of today's implementation was handling object lifetime inside `push_back()` and `pop_back()`.

While shifting elements after insertion or deletion, I struggled to determine:

- Which object should be destroyed?
- Whether assignment automatically destroys the previous object.
- Whether an explicit destructor call is required.
- How to avoid leaving invalid objects inside the array.

These issues resulted in several iterations before the implementation became stable.

---

# Section 2 — Failed Attempt

The day began with the preparation of the HashMap Design Proposal.

Although I already understood the basic working of a HashMap, I realized that documenting a data structure is much more difficult than simply implementing it. Every design decision required technical justification rather than assumptions.

For example, I initially documented only the selected implementation. Later, I realized that a proper design proposal should also explain:

- Alternative approaches considered.
- Why they were rejected.
- Why the final design was selected.

As a result, I revised almost every design section to include comparisons and technical reasoning.

---

After completing the design proposal, I started implementing the **DynamicArray**.

Initially, I believed the implementation would be straightforward because the overall logic was simple. However, I quickly encountered problems related to memory management.

My first implementation focused only on making the code work without carefully considering object ownership.

As I continued testing and reviewing the code, I realized several important mistakes:

- Memory ownership was not properly maintained.
- Copy operations were unsafe.
- The destructor was incomplete.
- Copying objects could lead to shared memory.
- Element shifting during insertion and deletion was not handling object lifetime correctly.

Whenever I became uncertain about how C++ manages dynamically allocated objects, I paused implementation and revisited the concepts of:

- Dynamic memory management.
- Deep copy versus shallow copy.
- Rule of Three.
- Destructor behavior.
- Object lifetime.

After improving my understanding, I returned to the implementation and gradually corrected each issue.

This iterative process of implementing, identifying mistakes, studying the underlying concepts, and refining the code consumed most of the development session but resulted in a much more reliable implementation.

---

# Section 3 — Memory Diagram

Today's work required preparing multiple memory diagrams to understand how objects are created and destroyed internally.

The diagrams prepared include:

### Diagram 1 — HashMap Memory Layout

Illustrates:

- HashMap object on the stack.
- Dynamic bucket array on the heap.
- LinkedList allocation.
- Node allocation.
- Relationship between buckets and linked lists.

---

### Diagram 2 — DynamicArray Resizing

Illustrates:

- Existing array.
- Allocation of larger memory.
- Copying existing elements.
- Releasing old memory.
- Updating the internal pointer.

---

### Diagram 3 — Element Shifting

Illustrates:

- Removing an element.
- Left shifting remaining objects.
- Updating logical size.
- Determining which object becomes invalid after shifting.

**Status:** Hand-drawn diagrams have been prepared and attached separately.

---

# Section 4 — Code Reference

**Commit Hash**

```
<commit_hash>
```

### Documentation

**File**

```
HashMapDesignProposal.md
```

Major sections completed:

- Public API
- Internal Representation
- Complexity Analysis
- Design Decisions
- Memory Layout
- Rule of Three
- Hash Function Design

---

### Source Code

**File**

```
DynamicArray.h
```

Major implementation completed:

- Constructor
- Destructor
- Copy Constructor
- Copy Assignment Operator
- push_back()
- pop_back()
- Dynamic resizing
- Memory cleanup
- Element shifting

**Relevant Line Numbers**

```
Constructor              : __________
Destructor               : __________
Copy Constructor         : __________
Assignment Operator      : __________
push_back()              : __________
pop_back()               : __________
Resize Logic             : __________
```

---

# Section 5 — Learning Reflection

Today fundamentally changed the way I think about software development.

While working on the HashMap Design Proposal, I realized that designing a data structure is much more than writing algorithms. Every implementation choice must be supported by technical reasoning. Decisions such as choosing an initial capacity of **16**, using a **load factor threshold of 0.7**, storing pointers instead of linked list objects, and selecting **Separate Chaining** were not arbitrary—they required evaluating alternatives and understanding their impact on performance, memory usage, scalability, and maintainability. This made me appreciate the importance of design documentation before implementation.

The DynamicArray implementation reinforced another important lesson: writing correct C++ code requires a deep understanding of memory management. I initially underestimated the complexity of implementing the Rule of Three. While writing the copy constructor, copy assignment operator, and resizing logic, I repeatedly encountered situations where I was unsure about object ownership, deep copying, destructor invocation, and element shifting.

Instead of continuing with incorrect assumptions, I revisited C++ memory management concepts, clarified how object lifetime is handled, and then refined my implementation. This iterative cycle of **implement → identify mistakes → study → correct → test** helped me understand not only how to make the code work but also why a particular implementation is correct.

By the end of the day, I had completed both the HashMap Design Proposal and a functional DynamicArray implementation. More importantly, I developed a much stronger understanding of designing reusable data structures and managing dynamically allocated memory safely in C++, lessons that will directly influence the implementation of the remaining components of the project.