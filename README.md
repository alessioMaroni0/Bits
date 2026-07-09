# BITS Library

[![C Version](https://img.shields.io/badge/C-C11-blue.svg)](#)
[![Library Type](https://img.shields.io/badge/Type-Header--Only-green.svg)](#)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](#)
[![Author](https://img.shields.io/badge/Author-Ale-orange.svg)](https://github.com/alessioMaroni0)
[![Version](https://img.shields.io/badge/Version-1.6.1-blue.svg)](#)

A C library developed for educational purposes while studying Chapter 2 of *Computer Systems: A Programmer's Perspective* (CS:APP).

The project aims to provide a low-level understanding of how data types are represented, stored, and manipulated in memory, offering tools for bit-twiddling and accurate arithmetic overflow checking.

---

## Key Features

* **Header-Only:** The library requires no separate compilation or dynamic linking. It consists entirely of `.h` header files containing definitions and macros.
* **Zero Overhead:** It leverages the preprocessor to ensure maximum runtime efficiency, eliminating function call overhead.
* **Safety:** It provides advanced macros to proactively detect overflow in compliance with computer architecture specifications.

---

## Architectural Choices
For the sake of simplicity, the project relies exclusively on header files. 
Macros are defined in the simplest and most effective way possible, allowing them to be cleanly reused throughout the library itself.

---

## Project Structure

```text
Bits
├── lib/
│   ├── bits.h            # Main collector header
│   ├── limits/
│   │   └── limits.h      # Limit constants for fixed-precision integers
│   ├── math/
│   │   └── math.h        # Safety checks for arithmetic operations
│   └── utils/
│       └── utils.h       # Bit-by-bit manipulation macros
├── test/
│   └── main.c            # Test and verification file
├── Dockerfile            # Isolated testing environment on Alpine Linux
└── Makefile              # Test build automation
```

---

## What I Learned
Building this library made concrete several concepts from CS:APP Chapter 2:
- Why unsigned overflow wraps predictably while signed overflow is undefined behavior in C
- How two's complement enables the same hardware adder to work for both signed and unsigned integers
- Why arithmetic right shift and logical right shift produce different results on negative numbers
- How IEEE 754 floating point represents precision loss at the boundaries of integer ranges