# Smart Shopping System — 4 Core Algorithms

A C++ course project developed by students of
the Department of Computer Science & Engineering,
Metropolitan University, Sylhet.

## Project Overview

Smart Shopping System is a C++ based project
that uses four classical algorithms to support
shopping decisions under a fixed budget.

The system explores product combinations,
selects products to maximize profit, allows
fractional selection, and calculates the minimum
number of coins or notes required for exact change.

## Core Algorithms

### 1. Total Product Combinations

- Contributor: Prappo
- File: prappo.h
- Technique: Dynamic Programming
- Usage: Unbounded
- Purpose: Counts all possible product
  combinations that reach the target budget.

### 2. 0/1 Knapsack

- Contributor: Arup
- File: arup.h
- Technique: Dynamic Programming
- Usage: Each item can be selected once.
- Purpose: Maximizes total profit within
  the given capacity.

### 3. Fractional Knapsack

- Contributor: Olid
- File: olid.h
- Technique: Greedy Algorithm
- Purpose: Selects items according to
  their Profit/Weight ratio.
- Supports partial item selection.

### 4. Minimum Coin Change

- Contributor: Rashmi
- File: rashmi.h
- Technique: Dynamic Programming
- Usage: Unbounded coin selection.
- Purpose: Finds the minimum number of
  coins or notes required for exact change.

## Project Structure

```text
Smart-Shopping-System/
|
|-- main.cpp
|-- prappo.h
|-- arup.h
|-- olid.h
|-- rashmi.h
|-- README.md
```

## Technologies Used

- C++
- Dynamic Programming
- Greedy Algorithm
- Git
- GitHub

## How to Run

### Requirements

- C++ compiler
- C++17 support
- Visual Studio Code or any C++ IDE

### Compile

```bash
g++ -std=c++17 main.cpp -o shopping
```

### Run

Windows:

```bash
.\shopping.exe
```

Linux:

```bash
./shopping
```

## Team Members

| Member | Responsibility |
|---|---|
| Prappo | Total Product Combinations |
| Arup | 0/1 Knapsack |
| Olid | Fractional Knapsack |
| Rashmi | Minimum Coin Change |

## Academic Information

Course Project

Department of Computer Science & Engineering

Metropolitan University, Sylhet
