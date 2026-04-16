<div align="center">

# push_swap

**Sort a stack of integers using two stacks and a minimal set of operations**

![Language](https://img.shields.io/badge/language-C-blue?style=flat-square)
![School](https://img.shields.io/badge/École-42-black?style=flat-square)
![Status](https://img.shields.io/badge/status-finished-success?style=flat-square)

<img src="https://go-skill-icons.vercel.app/api/icons?i=c,linux,git" />

</div>

---

## About

`push_swap` is a sorting algorithm project from the École 42 curriculum. The goal: sort a stack of integers using only two stacks (`a` and `b`) and a restricted set of operations, while producing the **fewest possible moves**.

The challenge isn't just sorting — it's sorting *efficiently*. The grade depends directly on the number of operations used.

---

## Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the top 2 elements of stack a |
| `sb` | Swap the top 2 elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of b onto a |
| `pb` | Push top of a onto b |
| `ra` | Rotate a upward (top → bottom) |
| `rb` | Rotate b upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate a (bottom → top) |
| `rrb` | Reverse rotate b |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Algorithm

The solution uses a **cost-based greedy algorithm** adapted from the Turk algorithm:

1. **Index normalization** — replace values with their rank (0 to n-1) to simplify comparisons
2. **Small cases** — hardcoded optimal solutions for 2 and 3 elements
3. **Medium cases** — specific logic for 5 elements via stack b
4. **Large cases (n > 5)** — for each element in `a`, compute the cost of pushing it to its correct position in `b` (accounting for both ra/rra and rb/rrb), then execute the cheapest move. Finalize by rotating `a` to its sorted state.

**Target performance:**
- 3 numbers → ≤ 3 operations
- 5 numbers → ≤ 12 operations
- 100 numbers → ≤ 700 operations
- 500 numbers → ≤ 5500 operations

---

## Usage

```bash
make
./push_swap <list of integers>
```

```bash
# Basic usage
./push_swap 3 1 2
pb
ra
pa

# Count operations
./push_swap 4 2 7 1 5 | wc -l
8
```

---

## Author

| Login | GitHub |
|-------|--------|
| ejonsery | [@EloanJ](https://github.com/EloanJ) |

---

<div align="center">
  <sub>École 42 Mulhouse — push_swap</sub>
</div>
