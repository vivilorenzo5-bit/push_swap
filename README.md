*Built as part of the 42 curriculum by roda-fon && vlourenc.*

# push_swap — Stack Sorting Algorithm 🔀

`roda-fon` && `vlourenc` collaborated equally on all aspects of this project, from design to implementation.

## Overview

push_swap is a sorting algorithm that operates on two stacks (A and B) using a restricted instruction set. The main goal is to sort integers with the fewest possible moves, powered by an **Adaptive Engine** that measures the disorder of the input and automatically picks the most suitable mathematical strategy.

### Goals

- **Algorithmic efficiency** — minimize the total number of operations (`sa`, `pb`, `ra`, etc.).
- **Complexity-aware selection** — switch between $O(n^2)$, $O(n\sqrt{n})$, and $O(n \log n)$ approaches depending on the data.
- **Data normalization** — coordinate compression (indexing) to handle any integer range efficiently.

---
##  Instructions

### # Compilation
The project uses a `Makefile` to generate the `push_swap` executable.

| Command | Action |
| :--- | :--- |
| `make` | Compiles the program. |
| `make clean` | Removes object files (.o). |
| `make fclean` | Removes objects and the executable. |
| `make re` | Recompiles everything from scratch. |

### 🚀 Execution & Flags
Run the program by passing a list of integers:

## Build & Usage


### Basic usage

```bash
./push_swap 5 2 8 1
```

### Benchmark mode

To print internal metrics (disorder score, chosen strategy, total ops) to `stderr`:

```bash
./push_swap --bench --adaptive $(shuf -i 0-1000 -n 500)
```

### Available flags

| Flag | Description |
| :--- | :--- |
| `--simple` | Forces $O(n^2)$ — Selection Sort. |
| `--medium` | Forces $O(n\sqrt{n})$ — Chunk Sort. |
| `--complex` | Forces $O(n \log n)$ — Radix Sort. |
| `--adaptive` | **(Default)** Auto-selects based on disorder score. |
| `--bench` | Outputs runtime metrics to `stderr`. |

---

## Sorting Strategies

Before sorting, the engine computes a **Disorder Index** ($D = \text{inversions} / \text{total pairs}$) and routes to one of three strategies.

### Simple Sort — $O(n^2)$

**Triggered when:** $D < 0.2$

On nearly sorted input, partitioning or bitwise processing adds unnecessary overhead. Instead, a **Selection Sort** variant with shortest-path rotations targets only the out-of-place elements, keeping the move count minimal.

---

### Medium Sort (Chunks) — $O(n\sqrt{n})$

**Triggered when:** $0.2 \leq D < 0.5$

Splits the data into $\sqrt{n}$ value ranges and pushes them to stack B in ordered blocks. A **bimodal return** strategy places smaller chunk elements at the bottom of B, keeping the stack structured and reducing the cost of pulling max values back to A.

---

### Complex Sort (Radix) — $O(n \log n)$

**Triggered when:** $D \geq 0.5$

For highly random input, **LSD Radix Sort** provides a stable and predictable upper bound. Processing normalized indices bit by bit sidesteps the worst-case behavior that comparison-based algorithms face on heavily scrambled data.

---

##  Resources

- **Coordinate compression** — Maps arbitrary integers to the range $[0, N-1]$, simplifying Radix and Chunk logic.
- **Inversion counting** — Mathematical basis for measuring sequence disorder and selecting the right complexity regime.
- **42 Norminette** — All code conforms to the mandatory 42 school style standard.

### AI Usage

AI was used as a technical mentor for:

- **Mathematical logic** — Working through the disorder formula to ensure the selection thresholds correctly reflect the complexity regimes required by the subject.
- **Documentation** — Help with structuring and formatting this README to meet Chapter VII requirements.