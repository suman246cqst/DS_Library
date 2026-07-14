# Daily Design Journal – Day 7

## Module – DynamicArray & LinkedList Unit Testing Framework using Google Test

**Date:** 14-07-2026

---

## Section 1 — Specific Bug

### Challenges During Development of the Unit Testing Framework

After completing the implementation of the `DynamicArray`, my next objective was to verify every public member function before using it as a dependency for higher-level data structures such as the `LinkedList` and `HashMap`. Manual testing using a simple driver program was no longer sufficient because it covered only a limited number of execution paths and made regression testing difficult whenever implementation changes were introduced. Therefore, I decided to develop a comprehensive unit testing framework using the Google Test library.

Before the testing framework could be developed, I encountered persistent issues with my Windows development environment. Although multiple C++ compilers were installed successfully, Visual Studio Code frequently failed to detect or execute the correct compiler due to conflicting MinGW installations, cached configuration files, and inconsistent environment settings. These problems repeatedly interrupted compilation and significantly slowed the testing process.

To eliminate these configuration issues, I migrated the entire project to the Ubuntu environment provided by Windows Subsystem for Linux (WSL). After configuring GCC, G++, CMake, Make, Git, and Google Test within Ubuntu, the build process became considerably more stable and predictable.

Another challenge involved organizing the growing collection of unit tests. Initially, I considered placing every test case inside a single source file. However, as the number of functions and testing scenarios increased, the file became difficult to maintain. To improve readability and modularity, I reorganized the project by creating separate Google Test source files for every public member function of both the `DynamicArray` and `LinkedList`.

While extending the testing framework to the `LinkedList`, additional challenges arose because the implementation manages memory manually using `malloc()`, placement `new`, explicit destructor invocation, and `free()`. The Rule of Three implementation therefore required extensive validation to ensure that constructors, destructors, copy operations, and dynamic memory management behaved correctly under different execution scenarios.

---

## Section 2 — Failed Attempt

Initially, I attempted to continue development using the existing Windows compiler configuration. Despite reinstalling compilers and modifying Visual Studio Code settings, compiler detection remained inconsistent due to conflicting installations and cached configurations. After multiple unsuccessful attempts, I migrated the project to Ubuntu through Windows Subsystem for Linux (WSL), where a clean Linux-based toolchain eliminated these configuration problems.

The first version of the Google Test framework placed multiple test cases inside a single source file. As additional member functions were tested, maintaining the test suite became increasingly difficult. To improve maintainability, I reorganized the framework into separate source files dedicated to individual member functions.

During DynamicArray testing, several compilation failures occurred because of missing standard library headers and incorrect source file references inside `CMakeLists.txt`. These issues prevented successful project generation until the build configuration was corrected. Some unit tests also failed due to incorrect assumptions rather than implementation defects. For example, the original `isFull()` test did not consider the automatic capacity expansion performed by `push_back()`. After reviewing the implementation, the test cases were redesigned to match the intended resizing strategy.

While configuring the LinkedList testing framework, duplicate executable targets and incorrect `target_link_libraries()` definitions inside `CMakeLists.txt` prevented successful project configuration. These build issues were resolved by reorganizing the executable definitions and verifying that every test source file was correctly included in the build system.

Another unsuccessful testing approach involved validating the destructor by comparing the total number of destructor invocations directly with the number of nodes stored inside the list. Investigation revealed that temporary objects created during insertion operations also invoke their destructors after being copied into newly allocated nodes. Consequently, the destructor count was larger than expected. The testing strategy was redesigned by recording a baseline destructor count after insertion and measuring only the additional destructor invocations generated when the linked list itself was destroyed.

During template testing, helper classes were initially defined inconsistently across different test files, resulting in compilation failures when testing user-defined objects. Standardizing the helper object implementation across the entire testing framework resolved these inconsistencies.

---

## Section 3 — Memory Diagram

**Hand-drawn memory diagrams submitted separately.**

The diagrams include:

* DynamicArray memory layout illustrating contiguous storage, automatic capacity expansion, insertion, deletion, and element shifting.
* LinkedList node structure showing pointer connections between successive nodes.
* Execution flow of `push_front()`, `push_back()`, `insertAtIndex()`, `deleteAtIndex()`, `pop_front()`, `pop_back()`, and `remove()`.
* Rule of Three memory diagrams illustrating deep copy behaviour during copy construction and copy assignment.
* Destructor execution sequence showing explicit object destruction followed by node deallocation.
* Google Test execution workflow demonstrating independent validation of every public member function through dedicated test modules.

---

## Section 4 — Code Reference

### Git Commits

**Commit:** `81f012d`

* Configured the Ubuntu (WSL) development environment.
* Established the Google Test build workflow.
* Implemented a comprehensive Google Test framework for the `DynamicArray` module.

**Commit:** `9c29fd0`

* Implemented the complete Google Test framework for the `LinkedList` module, including constructors, Rule of Three validation, insertion, deletion, searching, traversal, and utility functions.

### Implemented Features

#### Development Environment

* Migrated the project from Windows to Ubuntu using Windows Subsystem for Linux (WSL).
* Configured GCC, G++, CMake, Make, Git, and Google Test.
* Established a stable Linux-based build workflow.
* Integrated Google Test into the existing CMake project.

#### DynamicArray Testing

* Developed dedicated test files for every public member function.
* Verified constructor behaviour.
* Tested `push_back()` under normal conditions and automatic resizing.
* Tested `insertAtIndex()` for beginning, middle, end, and invalid positions.
* Verified `pop_back()` and underflow handling.
* Tested `deleteAtIndex()` under multiple scenarios.
* Validated `get()` and both overloads of `operator[]`.
* Verified deep copy semantics using the copy constructor and copy assignment operator.
* Tested `getSize()`, `getCapacity()`, `isEmpty()`, and `isFull()`.
* Verified `print()` using Google Test output capture.
* Validated template compatibility using primitive types, `std::string`, and custom user-defined objects.

#### LinkedList Testing

* Created a dedicated Google Test executable for the LinkedList module.
* Developed constructor and destructor test cases.
* Verified Rule of Three implementation.
* Tested `push_front()`, `push_back()`, `insertAtIndex()`, `pop_front()`, `pop_back()`, `deleteAtIndex()`, `remove()`, `search()`, `get()`, `traverse()`, `getSize()`, and `getHead()`.
* Verified exception handling for invalid operations.
* Implemented automated output verification for `traverse()`.
* Confirmed template compatibility using integers, strings, and custom objects.

### Files Modified

* `CMakeLists.txt`
* `testing/DynamicArrayTesting/*`
* `testing/LinkedListTesting/*`
* `docs/buildLogs/build_logDay7Session1.md`
* `docs/buildLogs/build_logDay7Session2.md`
* `docs/buildLogs/build_logDay7Session3.md`

### Relevant Functions

#### DynamicArray

* `DynamicArray()`
* `~DynamicArray()`
* `push_back()`
* `pop_back()`
* `insertAtIndex()`
* `deleteAtIndex()`
* `get()`
* `operator[]`
* `getSize()`
* `getCapacity()`
* `isEmpty()`
* `isFull()`
* `print()`
* Copy Constructor
* Copy Assignment Operator

#### LinkedList

* `LinkedList()`
* `~LinkedList()`
* `LinkedList(const LinkedList&)`
* `operator=()`
* `push_front()`
* `push_back()`
* `insertAtIndex()`
* `pop_front()`
* `pop_back()`
* `deleteAtIndex()`
* `remove()`
* `search()`
* `get()`
* `traverse()`
* `getSize()`
* `getHead()`

---

## Section 5 — Learning Reflection

Today's work significantly improved my understanding of software verification, automated testing, and C++ memory management. Rather than relying on manual testing through a driver program, I developed comprehensive Google Test suites that systematically validated every public member function of both the `DynamicArray` and `LinkedList` implementations under normal, boundary, and exceptional conditions. This experience demonstrated the importance of regression testing in maintaining software correctness as a project grows.

Migrating the project from Windows to Ubuntu using WSL also highlighted the value of a stable development environment. By configuring a consistent Linux-based toolchain with GCC, CMake, and Google Test, I eliminated compiler configuration issues and established a reliable workflow for future development.

Developing the LinkedList test suite further strengthened my understanding of C++ object lifetime, deep copy semantics, placement `new`, explicit destructor invocation, and manual memory management. The destructor testing process, in particular, emphasized the difference between temporary object destruction and destruction of dynamically allocated objects stored within the container.

Finally, organizing the testing framework into separate source files for each public member function improved the modularity and maintainability of the project. By the end of the day, comprehensive Google Test suites had been successfully developed for both the `DynamicArray` and `LinkedList` modules, providing a reliable foundation for implementing and validating more advanced data structures such as the `HashMap` within the DS Library project.
