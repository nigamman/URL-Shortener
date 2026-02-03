# URL Shortener Backend System (C++)

## Overview

This project implements a backend **URL shortening service in C++** that converts long URLs into short, unique identifiers and supports fast redirection back to the original URLs.

The system is designed for **constant-time encode and decode operations**, simulating the core logic used in real-world URL shorteners like Bitly.

---

## Problem Statement

Design a backend system that generates **short, unique URLs** for given long URLs and efficiently resolves them back to the original URLs.

The system should:
- Ensure uniqueness
- Handle expiration of URLs (TTL)
- Support fast lookup operations

---

## Features

- Encode long URLs into short **Base62-encoded identifiers**
- Decode short URLs back to original URLs in **O(1) time**
- Collision-safe unique ID generation
- Optional **TTL (Time-To-Live)** support for URL expiration
- Automatic cleanup of expired URLs during access

---

## System Design & Approach

The system uses an **incremental unique ID generator** combined with **Base62 encoding** to produce compact, URL-safe short codes.

This approach is:
- Simple
- Collision-free
- Highly efficient for in-memory systems

---

## Core Data Structures

| Component                              | Purpose                         |
|---------------------------------------|---------------------------------|
| `unordered_map<long long, string>`    | Map ID → original URL           |
| `unordered_map<string, long long>`    | Map short URL → ID              |
| `unordered_map<long long, time_t>`    | Track expiration timestamps     |

### Why this design?

- Constant-time encode and decode
- Minimal memory overhead
- Clean and scalable backend logic

---

## Core Operations

### `encode(longUrl, ttl)`

- Generates a unique numeric ID
- Converts ID to a Base62 short URL
- Stores bidirectional mappings
- Optionally assigns an expiration time

### `decode(shortUrl)`

- Resolves short URL to original URL
- Validates expiration
- Returns error if URL is missing or expired

---

## Time & Space Complexity

- **Encode:** `O(1)`
- **Decode:** `O(1)`
- **Space:** `O(N)` where `N` is the number of stored URLs

---

## Example Usage

```cpp
string shortUrl = encode("https://example.com", 5);
decode(shortUrl); // returns original URL
```
## Limitations & Future Improvements
- In-memory only (no persistent storage)
- Not thread-safe
- No distributed support
  
---

## Learning Outcomes
- Understanding backend ID generation strategies
- Practical use of hashing and encoding techniques
- Designing constant-time backend systems
- Evaluating scalability and system trade-offs

---
