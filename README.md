<div align="center">

<!-- Animated Banner -->
<img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=700&size=40&pause=1000&color=00D9FF&center=true&vCenter=true&width=600&height=80&lines=STL+C%2B%2B+Library;Modern+%7C+Fast+%7C+Powerful" alt="Typing SVG" />

<br/>

![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-blue?style=for-the-badge&logo=cplusplus&logoColor=white)
![STL](https://img.shields.io/badge/STL-Modules-green?style=for-the-badge&logo=cmake&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge)
![GitHub Stars](https://img.shields.io/github/stars/sahastraWin/STL-CPP?style=for-the-badge&logo=github)

<br/>

> 🚀 **A comprehensive, well-organized collection of C++ Standard Template Library (STL) modules** — built for competitive programmers, students, and developers who want clean, reusable, lightning-fast implementations.

<br/>

<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="700"/>

</div>

---

## 📌 Table of Contents

- [✨ Overview](#-overview)
- [📁 Module Structure](#-module-structure)
- [🧩 Modules In Detail](#-modules-in-detail)
- [⚡ Getting Started](#-getting-started)
- [💡 Usage Examples](#-usage-examples)
- [🛠️ Prerequisites](#️-prerequisites)
- [🤝 Contributing](#-contributing)
- [📜 License](#-license)

---

## ✨ Overview

<div align="center">
<img src="https://user-images.githubusercontent.com/74038190/229223263-cf2e4b07-2615-4f87-9c38-e37600f8381a.gif" width="400"/>
</div>

<br/>

**STL-CPP** is a curated, modular repository that houses hand-crafted implementations and utility wrappers around the **C++ Standard Template Library**. Whether you're preparing for competitive programming contests, studying data structures and algorithms, or building production tools — this library has you covered.

| 🌟 Feature | 📝 Description |
|---|---|
| 🧱 Modular Design | Each STL concept lives in its own folder |
| ⚡ High Performance | Optimized for speed and low memory footprint |
| 📚 Well Documented | Every module comes with examples and comments |
| 🔁 Reusable | Drop-in utility headers for any C++ project |
| 🎯 Competitive Ready | Structured for CP-style fast usage |

---

## 📁 Module Structure

<div align="center">
<img src="https://user-images.githubusercontent.com/74038190/212284087-bbe7e430-757e-4901-90bf-4cd2ce3e1852.gif" width="500"/>
</div>

```
STL-CPP/
│
├── 📂 Array and Vector/       → Static & dynamic array operations
├── 📂 Bit-Manipulation/       → Bitwise tricks and techniques
├── 📂 Compare/                → Custom comparators and ordering
├── 📂 Graph/                  → Graph traversal and algorithms
├── 📂 Maths/                  → Mathematical utilities
├── 📂 Matrix/                 → 2D matrix operations
├── 📂 Sorted Map/             → std::map usage and patterns
├── 📂 Sorted Set/             → std::set usage and patterns
├── 📂 Special/                → Miscellaneous STL utilities
├── 📂 String/                 → String manipulation & algorithms
├── 📂 Tokenizer/              → Parsing and tokenization tools
└── 📂 Tuple/                  → Tuple operations and tricks
```

---

## 🧩 Modules In Detail

<div align="center">
<img src="https://user-images.githubusercontent.com/74038190/212747107-5b654220-3bfc-4359-be12-7d9bc8eb1a82.gif" width="500"/>
</div>

<br/>

### 🗃️ Array and Vector
> Dynamic and static array manipulation using `std::vector`, `std::array`.
- Sorting, searching, prefix sums
- 2D vector patterns
- Custom initializations

---

### 🔢 Bit-Manipulation
> Low-level bit tricks for speed and efficiency.
- Set / Clear / Toggle bits
- Count set bits (`__builtin_popcount`)
- Power of 2 checks, XOR patterns

---

### ⚖️ Compare
> Custom comparison logic for STL containers.
- Lambda comparators
- Struct-based comparison
- Priority Queue custom ordering

---

### 🌐 Graph
> Graph representations and traversal algorithms.
- BFS / DFS
- Adjacency list & matrix
- Weighted graph utilities

---

### ➗ Maths
> STL-powered mathematical computations.
- GCD / LCM using `<numeric>`
- `std::accumulate`, `std::inner_product`
- Modular arithmetic helpers

---

### 🧮 Matrix
> 2D matrix utilities built on STL containers.
- Matrix multiplication
- Transpose
- Row/column operations

---

### 🗺️ Sorted Map
> `std::map` and `std::multimap` patterns.
- Frequency counting
- Range queries
- Ordered key-value store

---

### 🗂️ Sorted Set
> `std::set` and `std::multiset` patterns.
- Unique element storage
- Lower/upper bound queries
- Set operations (union, intersection)

---

### 🌀 Special
> Advanced and niche STL utilities.
- `std::optional`, `std::variant`
- `std::any`, `std::function`
- Policy-based structures

---

### 🔤 String
> `std::string` and `std::string_view` operations.
- Splitting, joining, trimming
- Pattern matching
- String conversion utilities

---

### 🔪 Tokenizer
> Input parsing made easy.
- Whitespace and delimiter tokenization
- `std::istringstream` patterns
- Fast I/O techniques

---

### 📦 Tuple
> `std::tuple`, `std::pair` tricks.
- Structured bindings
- Tuple unpacking
- Sorting by tuple elements

---

## ⚡ Getting Started

<div align="center">
<img src="https://user-images.githubusercontent.com/74038190/212748842-9fcbad5b-6173-4175-8a61-521f3dbb7514.gif" width="500"/>
</div>

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/sahastraWin/STL-CPP.git
cd STL-CPP
```

### 2️⃣ Navigate to a Module

```bash
cd "Array and Vector"
```

### 3️⃣ Compile and Run

```bash
g++ -std=c++17 -O2 -o output filename.cpp
./output
```

---

## 💡 Usage Examples

<div align="center">
<img src="https://user-images.githubusercontent.com/74038190/212747919-84fcfc74-5f37-42c5-9f11-db40b96b7d9a.gif" width="500"/>
</div>

### 🔹 Vector Operations
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 3, 1, 4, 2};
    sort(v.begin(), v.end());
    // Output: 1 2 3 4 5

    auto it = lower_bound(v.begin(), v.end(), 3);
    cout << *it; // 3
}
```

### 🔹 Sorted Map — Frequency Counter
```cpp
map<char, int> freq;
string s = "hello world";
for (char c : s) freq[c]++;
for (auto& [ch, cnt] : freq)
    cout << ch << ": " << cnt << "\n";
```

### 🔹 Bit Manipulation
```cpp
int n = 13;                           // 1101
cout << __builtin_popcount(n);        // 3 set bits
cout << (n & (n - 1));                // 12 → clear lowest set bit
cout << (n & -n);                     // 1 → lowest set bit
```

### 🔹 Custom Comparator with Priority Queue
```cpp
// Min-heap using lambda
auto cmp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
pq.push(5); pq.push(1); pq.push(3);
cout << pq.top(); // 1
```

---

## 🛠️ Prerequisites

| Tool | Minimum Version |
|------|----------------|
| 🖥️ g++ / clang++ | C++17 or higher |
| 🪟 Windows | MinGW / MSVC 2019+ |
| 🐧 Linux / macOS | GCC 9+ |
| 📝 Editor | VS Code / CLion / Vim |

---

## 🤝 Contributing

<div align="center">
<img src="https://user-images.githubusercontent.com/74038190/212741999-016fddbd-617a-4448-8042-0ecf907aea25.gif" width="400"/>
</div>

Contributions are **welcome and encouraged!** 🎉

```bash
# Fork → Clone → Create Branch → Commit → Push → PR
git checkout -b feature/new-module
git commit -m "✨ Add new STL module: ..."
git push origin feature/new-module
```

Please follow the existing folder structure and include:
- ✅ Clear, commented code
- ✅ At least one usage example
- ✅ A brief description at the top of the file

---

## 📜 License

```
MIT License — feel free to use, share, and modify with attribution.
```

---

<div align="center">

<img src="https://user-images.githubusercontent.com/74038190/212284158-e840e285-664b-44d7-b79b-e264b5e54825.gif" width="400"/>

<br/>

### 🌟 If this repository helped you, please give it a star! ⭐

**Made with ❤️ by [sahastraWin](https://github.com/sahastraWin)**

<br/>

![Visitors](https://visitor-badge.laobi.icu/badge?page_id=sahastraWin.STL-CPP)
![Last Commit](https://img.shields.io/github/last-commit/sahastraWin/STL-CPP?style=flat-square&color=blue)

</div>
