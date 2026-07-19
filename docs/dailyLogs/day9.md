# Daily Design Journal 

**Project:** DS Library & Redis Lite  
**Date:** 16-07-2026

---

# Section 1 — Specific Bug

No compiler or runtime bugs were encountered during today's work.

The focus of the day was on improving the project's reliability by integrating **Valgrind** into the development workflow and validating the memory safety of all completed modules. Every Google Test executable—including DynamicArray, LinkedList, HashMap, and Redis Lite—was executed under Valgrind. The analysis confirmed that the project contains **no memory leaks, invalid memory reads/writes, double-free errors, or use-after-free errors**.

The remainder of the day involved studying the architecture of a Web Crawler as preparation for a future project. Since this work was research-oriented, no implementation-related errors were generated.

---

# Section 2 — Failed Attempt

Initially, I relied solely on Google Test to validate the correctness of the DS Library. Although every test case passed successfully, I realized that passing functional tests does not guarantee correct memory management. A program can produce correct output while still containing memory leaks or invalid memory accesses.

To overcome this limitation, I integrated Valgrind into the project's workflow and executed every existing test suite under runtime memory analysis. This provided confidence that the manual memory management implemented throughout the project is both functionally correct and memory-safe.

While studying Web Crawlers, my initial thought was to begin implementation immediately. However, after reviewing the system requirements, I recognized that understanding the overall architecture and component interactions was essential before writing any code. I therefore postponed implementation and focused on studying the complete crawler workflow, design decisions, and system architecture.

---

# Section 3 — Memory Diagram

**Hand-drawn memory diagrams submitted separately.**

Today's diagrams include:

### Diagram 1 — HashMap Memory Layout

Illustrates:

- Bucket Array
- Linked List chains
- Hash Nodes
- Heap allocations
- Memory cleanup during destruction
- Complete deallocation verified using Valgrind

### Diagram 2 — Web Crawler Architecture

Illustrates:

- Seed URL
- Frontier (Queue)
- HTML Downloader
- HTML Parser
- Link Extractor
- Seen URL Store (HashMap)
- Page Storage
- Crawl loop and URL discovery process

---

# Section 4 — Code Reference

**Git Commit**

`c051161` — *Setup environment for memory validation using Valgrind*

**Files Referenced**

- `CMakeLists.txt`
- `testing/DynamicArrayTesting/`
- `testing/LinkedListTesting/`
- `testing/HashMapTesting/`
- `testing/RedisLiteTesting/`

These files were executed under Valgrind to validate memory correctness across the entire project.

Additional reference material studied:

- Web Crawler Design Notes
- Web Crawler Architecture Reference Document

---

# Section 5 — Learning Reflection

Today's work significantly changed my understanding of software quality and system design.

Before today, I considered a module complete once all Google Test cases passed. Integrating Valgrind demonstrated that functional correctness and memory correctness are two independent aspects of software quality. Since the DS Library relies entirely on manual memory management using `malloc`, placement new, and explicit destructor calls, memory analysis became an essential part of the development process rather than an optional verification step. Successfully validating DynamicArray, LinkedList, HashMap, and Redis Lite under Valgrind increased my confidence that the library is not only functionally correct but also robust in terms of resource management.

Studying Web Crawler architecture also changed my perspective on how individual data structures are used within larger software systems. Instead of viewing the custom HashMap, DynamicArray, and LinkedList as isolated implementations, I now understand how they collaborate to solve real-world problems. In particular, I recognized why a HashMap is the ideal choice for maintaining the Seen URL Store, where efficient duplicate detection directly impacts crawler performance. This helped me connect the reusable components of the DS Library with practical system design and reinforced the importance of selecting appropriate data structures based on application requirements rather than implementation convenience.