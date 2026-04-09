# 📊 Sorting Algorithms — Implementation & Benchmark

**Author:** Malek Bouaziz
**Course:** Algorithms & Data Structures · Praktikum 2.1
**Language:** C++17

Seven classic sorting algorithms implemented and **empirically benchmarked** across
input sizes from 1,000 to 1,000,000 elements. Runtime data is exported to `.txt`
files and visualized in MATLAB.

---

## 📋 Overview

Each algorithm is measured using `std::chrono::steady_clock`, repeated 10 times
per input size and averaged to reduce noise. Results expose the practical differences
between O(n²), O(n log n), and linear-time algorithms.

---

## 🗂️ Files

| File | Role |
|------|------|
| `sorting.h` | All algorithm declarations (namespace `sorting`) |
| `sorting.cpp` | Full implementations of all 7 algorithms |
| `main.cpp` | Catch2 test runner + benchmark loop |
| `unit_tests.cpp` | Correctness tests for each algorithm |
| `zeitmessung.mlx` | MATLAB Live Script for visualization |
| `*.txt` | Benchmark output files (one per algorithm) |

---

## ⚙️ Algorithms

| Algorithm | Complexity (avg) | In-place | Stable |
|-----------|-----------------|----------|--------|
| InsertionSort | O(n²) | ✅ | ✅ |
| QuickSort | O(n log n) | ✅ | ❌ |
| MergeSort | O(n log n) | ❌ | ✅ |
| HeapSort | O(n log n) | ✅ | ❌ |
| ShellSort (2^n gaps) | O(n^1.5) | ✅ | ❌ |
| CountingSort | O(n + k) | ❌ | ✅ |
| RadixSort | O(nk) | ❌ | ✅ |

---

## 🚀 Build & Run
```bash
g++ -std=c++17 -o sorting main.cpp sorting.cpp unit_tests.cpp
./sorting
```

The program runs **unit tests first**, then prompts to launch the benchmark.
Results are written to `.txt` files automatically.

**Benchmark parameters:**

| Parameter | Value |
|-----------|-------|
| Input range | 1,000 → 1,000,000 |
| Step size | 10,000 |
| Runs per size | 10 (averaged) |
| Output format | `n   avg_time_ns` (scientific notation) |

---

## 🧠 Concepts

- Divide & conquer: QuickSort, MergeSort
- Heap-based sorting: HeapSort
- Non-comparison sorts: CountingSort, RadixSort
- Empirical complexity analysis with `std::chrono`
- Catch2 unit testing
- MATLAB data visualization
