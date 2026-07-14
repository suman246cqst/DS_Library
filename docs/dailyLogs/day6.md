# Daily Design Journal – Day 6

## Module – HashMap Completion & Generic Hash Function Design

**Date:** 13-07-2026

---

## Section 1 — Specific Bug

### Design Challenges During HashMap Completion

While completing the remaining functionality of the `HashMap`, I encountered two major design challenges.

The first challenge involved implementing operations such as `exists()`, `get()`, and `remove()`. Since each of these functions depend on computing the hash value and locating the appropriate bucket, I needed to ensure that every operation followed a consistent execution flow. Another important design decision was determining how the `insert()` function should behave when the same key is inserted multiple times. Allowing duplicate keys would violate the expected behavior of a hash table, so I redesigned the insertion logic to update the existing value instead of creating another node.

The second challenge appeared while extending the hashing mechanism to support user-defined key types. Although the existing `HashFunction` implementation successfully handled primitive data types and `std::string`, it was not immediately clear how arbitrary classes should be hashed. This required investigating different generic hashing strategies while ensuring that hashing remained consistent with key comparison throughout the `HashMap`.

---

## Section 2 — Failed Attempt

Initially, I focused on implementing the remaining `HashMap` operations independently without considering how they could reuse common functionality. This resulted in duplicated traversal logic across multiple methods, making the implementation more difficult to maintain.

To improve the design, I standardized the workflow so that every operation first computes the hash value, determines the appropriate bucket index, and then traverses the linked list stored in that bucket. The `insert()` function was redesigned to first check whether a key already exists. If the key is present, the stored value is updated through `get()` instead of inserting a duplicate node. This approach reduced duplicate logic while maintaining the expected semantics of a hash map.

While extending the hashing mechanism, I initially explored generating hash values directly from an object's memory address. However, I realized that two objects containing identical data would still produce different addresses, making this strategy unsuitable for a hash table.

I then experimented with reading an object's raw bytes using `reinterpret_cast` and computing a polynomial-style hash over those bytes. Although this approach works for simple types, further investigation revealed that user-defined classes may contain padding bytes or pointer members that do not accurately represent the logical state of the object. Consequently, this strategy could generate inconsistent hash values.

To ensure correctness, I redesigned the implementation to require user-defined key types to support equality comparison through `operator==`. I also considered allowing classes to provide their own `hashCode()` implementation while retaining generic hashing only as a fallback mechanism.

---

## Section 3 — Memory Diagram

**Hand-drawn memory diagrams submitted separately.**

The diagrams include:

- HashMap bucket array showing how bucket indices map to individual linked lists through separate chaining.
- Execution flow of `insert()`, `exists()`, `get()`, and `remove()`, illustrating how each operation computes the hash value, selects a bucket, and traverses the corresponding linked list.
- Generic hashing workflow showing the distinction between built-in type hashing and user-defined type hashing, along with compile-time validation for supported key types.

---

## Section 4 — Code Reference

### Git Commit

**Commit:** `ace72f2`

### Implemented Features

- Completed the remaining `HashMap` member functions.
- Implemented `exists()` for key lookup.
- Implemented `get()` with exception handling for missing keys.
- Implemented `remove()` using linked list deletion.
- Updated `insert()` to replace existing values instead of allowing duplicate keys.
- Implemented `printBuckets()` for debugging and bucket visualization.
- Modified `DynamicArray` and `LinkedList` interfaces where necessary to improve integration with `HashMap`.
- Extended the `HashFunction` module to support primitive data types, `std::string`, and generic user-defined key types.
- Explored compile-time validation using `static_assert` to enforce equality comparison requirements.
- Designed a strategy supporting customizable `hashCode()` implementations for user-defined classes.

### Files Modified

- `include/hashMap.h`
- `src/hashMap.cpp`
- `include/HashFunction.h`
- `src/HashFunction.cpp`
- `include/dynamicArray.h`
- `src/dynamicArray.cpp`
- `include/linkedList.h`
- `src/linkedList.cpp`

### Relevant Functions

- `insert()`
- `exists()`
- `get()`
- `remove()`
- `printBuckets()`
- `HashFunction::generateHash()`

---

## Section 5 — Learning Reflection

Today's work deepened my understanding of how multiple data structures collaborate to implement an efficient hash table. Rather than viewing `HashMap` operations as isolated functions, I learned that they all share a common workflow consisting of hash computation, bucket selection, and linked list traversal. Designing reusable execution paths significantly reduced code duplication and improved maintainability.

Another important realization was that generic programming extends beyond writing template code. Supporting user-defined key types requires establishing clear contracts between hashing and equality comparison. I learned that a valid hash function must represent an object's logical state rather than its physical memory layout, and that consistent behavior between `generateHash()` and `operator==` is essential for the correctness of any hash-based data structure.

Finally, integrating the `HashMap` with the previously implemented `DynamicArray` and `LinkedList` reinforced the importance of modular software design. Small interface refinements in reusable components enabled cleaner integration while preserving code reusability, making the overall implementation more extensible for future enhancements such as customizable hashing strategies and advanced associative containers.