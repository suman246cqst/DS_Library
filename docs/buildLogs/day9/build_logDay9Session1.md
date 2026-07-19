# Build Log – Session 1

**Module:** Valgrind Integration and Project-wide Memory Validation  
**Date:** 16-07-2026  
**Duration:** 2 Hours

## Goal

* Set up Valgrind within the Ubuntu WSL development environment.
* Integrate memory analysis into the existing CMake and Google Test workflow.
* Verify the memory correctness of every completed module in the DS Library project.
* Ensure that the project is free from memory leaks and invalid memory operations before continuing future development.

---

## Problem Encountered

The DS Library is implemented entirely using manual memory management rather than relying on STL containers. Dynamic memory is explicitly managed using `malloc`, placement new, manual destructor invocation, and custom resource management logic. Although every Google Test case was already passing successfully, functional correctness alone could not guarantee memory safety.

Undetected issues such as memory leaks, invalid reads or writes, double frees, or use-after-free errors could still exist without affecting test results. Since the objective of this project is to build a reliable and reusable data structure library, it became necessary to validate every implemented component using an industry-standard memory analysis tool.

The project did not previously include a memory debugging workflow, so the first task was integrating Valgrind into the existing Ubuntu WSL development environment and ensuring it worked seamlessly with the project's Google Test executables.

---

## What I Tried

### Environment Setup

* Installed Valgrind on Ubuntu WSL.
* Verified successful installation and configuration.
* Learned the basic Valgrind workflow for CMake-based projects.
* Executed Google Test binaries through Valgrind instead of running them directly.
* Studied commonly used options for detailed memory analysis and leak detection.

### DynamicArray Memory Validation

Executed the complete DynamicArray test suite under Valgrind.

Verified:

* Proper allocation and deallocation of dynamic memory.
* Correct object construction and destruction.
* No memory leaks.
* No invalid memory access.
* No double free or use-after-free errors.

### LinkedList Memory Validation

Executed every LinkedList unit test through Valgrind.

Verified:

* Correct allocation of nodes.
* Safe pointer manipulation.
* Proper cleanup after deletion.
* Leak-free destruction of the linked list.
* Correct handling of dynamically allocated resources.

### HashMap Memory Validation

Executed the complete HashMap test suite under Valgrind.

Verified:

* Correct allocation of bucket storage.
* Proper cleanup of chained linked lists.
* Safe memory handling during insertion, deletion, and lookup.
* Correct destruction after rehashing.
* Leak-free copy construction and copy assignment.
* Proper cleanup after calling `clear()`.

### Redis Lite Memory Validation

Executed the Redis Lite application through Valgrind.

Verified:

* Proper initialization of the internal `HashMap`.
* Correct destruction of all allocated resources when the application exits.
* No memory leaks introduced by command execution.
* Successful cleanup of the application layer built on top of the DS Library.

---

## Outcome

* Successfully integrated Valgrind into the DS Library development workflow.
* Established memory validation as a standard quality assurance step before completing future modules.
* Confirmed that DynamicArray, LinkedList, HashMap, and Redis Lite execute without memory leaks or invalid memory operations.
* Increased confidence in the correctness of the project's manual memory management implementation.
* Strengthened the overall reliability and maintainability of the DS Library through comprehensive runtime memory verification.

---

**Git Commit:** `c051161` — Setup environment for memory validation using Valgrind.