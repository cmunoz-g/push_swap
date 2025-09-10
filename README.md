# 🥞 push\_swap

Sort integers using two stacks and a restricted instruction set. Outputs the minimal sequence of moves your program finds to sort `a` in ascending order.

## Build and run

```bash
# Clone
 git clone https://github.com/cmunoz-g/push_swap.git
 cd push_swap

# Build
make

# Run
./push_swap 2 1 3 6 5 8
```

Prints one instruction per line; no output for already-sorted input. On error, prints `Error` to `stderr`.

## Usage

* Input: a list of space-separated integers (duplicates and non-integers are invalid).
* Goal: sort stack **a** (ascending), leave stack **b** empty.
* Output: sequence of operations among `sa sb ss pa pb ra rb rr rra rrb rrr`.

Example:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

## Features

* Move generation based on the **Turk** strategy (see [Ayogun's write-up](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)).
* Cost model marks a single **cheapest** node to push/align at each step.
* Simultaneous rotations `rr/rrr` when both targets sit on the same half.
* Small-sort path for 3 elements; general path for larger inputs.
* Stable error handling and no global state.

## Implementation details

* **push\_swap** — trim `a` to 3 via `pb`, `sort_small(a)`, then iteratively `set_node_values` and `move_nodes` until `b` is empty; finish by rotating `a` so the smallest is on top.
* **move\_nodes** — choose `cheap=get_cheapest(b)`; if `cheap` and `cheap->target` share half, rotate both via `rr/rrr`; refresh positions, align with `end_rotation` on each stack; `pa`.
* **end\_rotation** — rotate `a` or `b` with `ra/rra` or `rb/rrb` until the target is at the top, based on `above_median`.
* **get\_cheapest** — scan stack for the node flagged `cheapest==true`.
* **set\_node\_values** — compute `index`, `above_median`, `target` in opposite stack, and the combined rotation cost; mark `cheapest`.
* **sort\_small** — 3‑element sorter using minimal `sa/ra/rra` steps.

## Project structure

* `src/` — parsing & validation, stack ops (`sa/sb/ss/pa/pb/ra/rb/rr/rra/rrb/rrr`), cost model, and main algorithm.
* `include/` — headers (`t_push_swap`, prototypes, error macros).
* `libft/` — local helpers if used.
* `Makefile` — builds the `push_swap` binary.
