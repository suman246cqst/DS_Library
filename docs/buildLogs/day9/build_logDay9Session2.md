# Build Log – Session 2

**Module:** Web Crawler Architecture and System Design Study  
**Date:** 16-07-2026  
**Duration:** 2 Hours

## Goal

* Study the architecture and workflow of a modern Web Crawler.
* Understand how reusable data structures developed in the DS Library can be applied to a real-world system.
* Analyze the responsibilities of each crawler component before beginning implementation in a future project.
* Learn the design decisions, algorithms, and engineering trade-offs involved in building a scalable crawler.

---

## Problem Encountered

Before beginning the design of a Web Crawler, it was necessary to understand how a crawler operates internally and how multiple components collaborate to efficiently traverse the web. Unlike standalone data structures, a crawler is a complete software system that combines networking, parsing, storage, and traversal algorithms.

The primary challenge was understanding how pages are discovered, how duplicate URLs are avoided, how crawl depth is managed, and how different data structures influence the overall performance and scalability of the system. Since the goal is to build the crawler using the custom DS Library wherever possible, it was also important to identify where data structures such as queues, hash maps, and dynamic arrays naturally fit into the architecture.

---

## What I Studied

### Introduction to Web Crawlers

* Studied the purpose of a web crawler.
* Understood how search engines discover and collect web pages.
* Learned the complete crawling workflow from a seed URL to page storage.

### Crawler Workflow

Studied the end-to-end crawling pipeline consisting of:

* Seed URL initialization.
* Downloading web pages using HTTP requests.
* Parsing HTML documents.
* Extracting hyperlinks.
* Discovering new pages.
* Maintaining the crawling frontier.
* Storing downloaded pages for future processing.

### HTML Structure and Hyperlink Extraction

Studied the structure of HTML documents.

Learned about:

* HTML tags.
* Anchor (`<a>`) elements.
* Hyperlinks.
* Absolute and relative URLs.
* Fragment links.
* Invalid and duplicate links.

Understood how crawlers extract outgoing URLs from downloaded pages.

### Frontier and Crawl Queue

Studied the concept of the Frontier.

Learned how it stores URLs waiting to be crawled.

Understood:

* FIFO traversal.
* Queue-based processing.
* URL-depth pairing.
* Crawl scheduling.

### Seen URL Store

Studied why crawlers maintain a collection of already visited URLs.

Analyzed different implementation choices and concluded that a HashMap is the preferred data structure because of its near constant-time lookup performance.

Connected this concept directly to the custom generic `HashMap` developed in the DS Library.

### Crawl Depth

Studied how crawl depth is tracked throughout traversal.

Learned:

* Seed page depth.
* Child page depth calculation.
* Maximum crawl depth restrictions.
* Preventing infinite traversal.

### Page Storage

Studied how crawled pages and metadata can be stored for future indexing.

Reviewed the information typically associated with every downloaded page, including:

* URL.
* HTML content.
* Crawl depth.
* Timestamp.
* Outgoing links.

### Component-Based Architecture

Studied the responsibilities of the major crawler components:

* Crawler
* Frontier
* Seen URL Store
* HTML Parser
* Link Extractor
* Page Storage

Understood how each component communicates through clearly defined interfaces while remaining independently maintainable.

### Engineering Design Decisions

Reviewed several important implementation decisions, including:

* Choosing appropriate data structures.
* URL normalization.
* Duplicate detection.
* Failure handling.
* Crawl limits.
* Logging.
* Scalability considerations.
* Performance trade-offs.

---

## Outcome

* Developed a solid understanding of the complete architecture of a modern Web Crawler.
* Understood the responsibilities and interaction of all major crawler components.
* Identified where custom data structures from the DS Library can be applied within a real-world system.
* Learned how efficient duplicate detection, crawl scheduling, and page management directly influence crawler performance.
* Established a strong architectural foundation for designing and implementing a Web Crawler as a future project built upon the reusable DS Library.

---
