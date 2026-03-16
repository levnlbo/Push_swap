*This project has been created as part of the 42 curriculum by lnalband, aravetis.*

# push_swap

## Description

push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (A and B) and a limited set of operations, while using the fewest operations possible.

The program receives a list of integers as arguments and prints the sequence of operations that sorts them in ascending order with the smallest number on top.

The project implements four distinct sorting strategies and automatically selects the best one based on how disordered the input is.

## Instructions

### Compilation

```bash
git clone <your_repo_url>
cd push_swap
make
```

### Usage

```bash
./push_swap 3 1 4 1 5 9 2 6
```

This prints the list of operations to stdout, one per line.

### Strategy flags (optional)

```bash
./push_swap --simple   5 4 3 2 1   # O(n²) selection sort
./push_swap --medium   5 4 3 2 1   # O(n√n) chunk sort
./push_swap --complex  5 4 3 2 1   # O(n log n) greedy cost
./push_swap --adaptive 5 4 3 2 1   # auto-select based on disorder (default)
```

If no strategy flag is given, `--adaptive` is used automatically.

### Benchmark mode

```bash
./push_swap --bench --complex 5 4 3 2 1
```

Prints the operation stream to stdout as normal. Prints stats to stderr:

```
[bench] disorder:  85.00%
[bench] strategy:  Complex / O(n log n)
[bench] total_ops: 614
[bench] sa: 0  sb: 0  ss: 0  pa: 99  pb: 97
[bench] ra: 201  rb: 89  rr: 47  rra: 63  rrb: 18  rrr: 0
```

### Verify correctness with checker

```bash
ARG="3 1 4 1 5 9 2 6"
./push_swap $ARG | ./checker_linux $ARG
# OK
```

### Count operations

```bash
./push_swap --complex $(shuf -i 0-9999 -n 100) | wc -l
```

### Error cases

```bash
./push_swap 1 abc 3      # Error (not a number)
./push_swap 1 2 2        # Error (duplicate)
./push_swap 1 2147483648 # Error (overflow)
./push_swap              # (silent, no output)
```

### Makefile rules

```bash
make        # build push_swap
make clean  # remove object files
make fclean # remove object files and binary
make re     # fclean + build
```

## Allowed operations

| Operation | Description |
|---|---|
| `sa` | Swap top 2 elements of stack A |
| `sb` | Swap top 2 elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of B to top of A |
| `pb` | Push top of A to top of B |
| `ra` | Rotate A — top element goes to bottom |
| `rb` | Rotate B — top element goes to bottom |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A — bottom element goes to top |
| `rrb` | Reverse rotate B — bottom element goes to top |
| `rrr` | `rra` and `rrb` simultaneously |

## Algorithm Explanations

### Disorder metric

Before any sorting begins, the program measures how unsorted the input is. It looks at every possible pair of elements. Each time a larger number appears before a smaller one, that counts as a mistake. The disorder is the ratio of mistakes to total pairs, giving a value between 0.0 (perfectly sorted) and 1.0 (fully reversed).

For example with `[3, 1, 4, 2]`:
- Pairs: (3,1)✗ (3,4)✓ (3,2)✗ (1,4)✓ (1,2)✓ (4,2)✗
- disorder = 3/6 = 0.50 = 50%

This metric is computed once before any moves and drives the adaptive strategy selection.

### Simple — O(n²) — Selection Sort

Repeatedly finds the minimum element in A, rotates it to the top using the shortest path (forward or backward), and pushes it to B. After all elements are in B, pushes everything back to A. The smallest element was pushed first, so it arrives back last and ends up at the bottom — A is sorted with the minimum on top.

Each of the n elements requires up to n/2 rotations to reach the top, giving O(n²) total operations. Average: ~1460 operations for 100 numbers.

### Medium — O(n√n) — Chunk Sort

Divides indices 1..n into chunks of size √n. For each chunk, scans A rotating until all elements of that chunk are pushed to B. Within each chunk, elements in the upper half of the chunk get an extra `rb` to send them toward the bottom of B — this pre-sorts within the chunk. After all chunks are in B, repeatedly finds the maximum in B, rotates it to the top, and pushes it back to A. This rebuilds A in sorted order.

There are √n chunks and each requires scanning all n elements of A, giving O(n√n) total operations. Average: ~3160 operations for 100 numbers.

### Complex — O(n log n) — Greedy Cost (Turkish Algorithm)

Pushes all but 3 elements to B, sorts the remaining 3 in A with an optimal 3-element sort, then repeatedly inserts the cheapest element from B back into its correct position in A.

For each element in B, the cost of insertion is calculated as: rotations needed to bring the target position in A to the top + rotations needed to bring the B element to the top. The element with the minimum total cost is inserted next.

The key optimization is simultaneous rotations: when both A and B need to rotate in the same direction, `rr` or `rrr` is used, counting as 1 operation instead of 2. This is what gives the algorithm its performance advantage.

Average: ~600 operations for 100 numbers, ~5480 for 500 numbers — excellent grade performance.

### Adaptive — disorder-based selection

Measures the disorder of the input and selects the most appropriate algorithm:

- disorder < 0.2 → Simple O(n²): the stack is nearly sorted, simple sort is fast enough and has low overhead
- disorder < 0.5 → Medium O(n√n): moderate disorder, chunk sort handles this range efficiently
- disorder ≥ 0.5 → Complex O(n log n): highly disordered, the greedy algorithm is needed for best performance

Sizes ≤ 2 and ≤ 5 are handled by dedicated optimal small-set sorters regardless of disorder.

## Performance

| Input size | Excellent | Good | Pass |
|---|---|---|---|
| 100 numbers | < 700 ops | < 1500 ops | < 2000 ops |
| 500 numbers | < 5500 ops | < 8000 ops | < 12000 ops |

Results with `--complex`:
- 100 numbers: ~600 ops average (excellent)
- 500 numbers: ~5480 ops average (excellent)

## Resources

### References

- [Push swap — a performant sorting algorithm guide](https://medium.com/nerd-for-the-world/push-swap-tutorial-fa746e6aba1e)
- [Visualizer for push_swap operations](https://github.com/o-reo/push_swap_visualizer)
- [Big-O notation explained](https://www.bigocheatsheet.com/)
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)

### AI usage

This project was developed with the assistance of Claude (Anthropic) for the following tasks:

- Generating the initial project structure and file layout
- Implementing and debugging the four sorting algorithms
- Fixing norminette compliance issues (function length, argument count, forbidden includes, ternary operators, multi-instruction lines)
- Writing manual implementations of `ft_strcmp`, `ft_isqrt` to replace forbidden standard library functions
- Explaining algorithmic concepts and complexity analysis
- Writing this README

All code was reviewed, tested, and understood by both team members. The algorithms, data structures, and design decisions were discussed and validated together. Both learners are able to explain and defend every part of the implementation.

## Authors

- **lnalband** — 42 School
- **aravetis** — 42 School