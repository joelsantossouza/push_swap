# Push_swap

*This project has been created as part of the 42 curriculum by joesanto*

## Description

Push_swap is a sorting algorithm project that challenges you to sort a stack of integers using the minimum number of operations possible. The project provides two stacks (stack a and stack b) and a limited set of operations to manipulate them.

**Goal:** Sort stack a in ascending order while leaving stack b empty, using the fewest moves possible.

This project develops understanding of:
- Algorithm complexity and optimization
- Data structure manipulation (stacks)
- Cost analysis and decision-making algorithms
- The Turk Algorithm sorting strategy

The program outputs a sequence of operations that, when executed, will sort the input data optimally.

## Instructions

### Compilation

Build the main program:
```bash
make
```

This generates the `push_swap` executable.

Build the checker (bonus):
```bash
make bonus
```

This generates the `checker` executable to verify sorting results.

### Execution

**Basic usage:**
```bash
./push_swap 9 2 1 4 5
```

**Alternative syntax:**
```bash
./push_swap "9 2 1 4 5"
```

**With checker:**
```bash
./push_swap 1 5 2 3 | ./checker 1 5 2 3
```

**Using environment variable (recommended):**
```bash
ARG="1 5 2 3"; ./push_swap $ARG | ./checker $ARG
```

### Input Constraints

The program accepts only:
- Integer values within valid range
- No duplicates
- No integer overflows

Invalid input will result in an error message.

## Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack a |
| `sb` | Swap the first 2 elements at the top of stack b |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push the top element from b to a |
| `pb` | Push the top element from a to b |
| `ra` | Rotate stack a upward (first becomes last) |
| `rb` | Rotate stack b upward (first becomes last) |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack a (last becomes first) |
| `rrb` | Reverse rotate stack b (last becomes first) |
| `rrr` | Execute `rra` and `rrb` simultaneously |

## Algorithm: Turk Algorithm

This implementation uses the **Turk Algorithm**, an efficient sorting strategy that minimizes operations through cost analysis.

### How It Works

Let's sort the sequence: `8 2 4 6 5 7`

#### Step 1: Initial State
```
 Stack a    Stack b
┌───────┐
│   8   │
├───────┤
│   2   │
├───────┤
│   4   │
├───────┤
│   6   │
├───────┤
│   5   │
├───────┤
│   7   │
└───────┘
```

#### Step 2: Initial Push (pb, pb)
Execute two blind pushes to initialize stack b:

```
Operations: pb, pb

 Stack a    Stack b
┌───────┐  ┌───────┐
│   4   │  │   2   │
├───────┤  ├───────┤
│   6   │  │   8   │
├───────┤  └───────┘
│   5   │
├───────┤
│   7   │
└───────┘
```

#### Step 3: Cost Calculation
Calculate the cost to insert each element from stack a into stack b (maintaining descending order in b):

```
Element 4: index 0 in a → insert below 8 → cost = 2 (rb + pb)
Element 6: index 1 in a → insert below 8 → cost = 3 (ra + rb + pb)
Element 5: index 2 in a → insert below 8 → cost = 4 (2×ra + rb + pb)
Element 7: index 3 in a → insert below 8 → cost = 3 (rra + rb + pb)

Best choice: 4
```

**Execute: rb, pb**
```
 Stack a    Stack b
┌───────┐  ┌───────┐
│   6   │  │   4   │
├───────┤  ├───────┤
│   5   │  │   8   │
├───────┤  ├───────┤
│   7   │  │   2   │
└───────┘  └───────┘
```

#### Step 4: Repeat "Step 3" Until 3 Elements Remain in Stack a

#### Step 5: Sort Remaining 3 Elements
We now have 3 elements in stack a. Sort them using simple operations:

**Execute: sa**
```
 Stack a    Stack b
┌───────┐  ┌───────┐
│   5   │  │   4   │
├───────┤  ├───────┤
│   6   │  │   8   │
├───────┤  ├───────┤
│   7   │  │   2   │
└───────┘  └───────┘
```

Stack a is now sorted

#### Step 6: Push Back to Stack A
Now push elements back from b to a, calculating cheapest insertion to maintain ascending order:

**Execute: pa**
```
 Stack a    Stack b
┌───────┐  ┌───────┐
│   4   │  │   8   │
├───────┤  ├───────┤
│   5   │  │   2   │
├───────┤  └───────┘
│   6   │
├───────┤
│   7   │
└───────┘
```

**Execute: pa**
```
 Stack a    Stack b
┌───────┐  ┌───────┐
│   8   │  │   2   │
├───────┤  └───────┘
│   4   │
├───────┤
│   5   │
├───────┤
│   6   │
├───────┤
│   7   │
└───────┘
```

**Execute: ra, pa**
```
 Stack a    Stack b
┌───────┐
│   2   │
├───────┤
│   4   │
├───────┤
│   5   │
├───────┤
│   6   │
├───────┤
│   7   │
├───────┤
│   8   │
└───────┘
```

#### Step 7: Final Result
Stack a is now sorted in ascending order, and stack b is empty. ✅

### Cost Optimization

The algorithm minimizes operations by:
- Always choosing the element with the lowest insertion cost
- Considering both forward and reverse rotations
- Hard-coding small sorts (3 elements)

## Checker Program

The bonus checker validates whether a sequence of operations correctly sorts the stack:

**Usage:**
```bash
echo -e "pb\npb\nsa\npa\npa" | ./checker 3 2 1
```

**Output:**
- `OK` - Stack a is sorted in ascending order and stack b is empty
- `KO` - Incorrect sorting or stack b is not empty
- `Error` - Invalid operations or input

## Resources

### Documentation & Tutorials
- [Push_swap Turk Algorithm Explained](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0) - Comprehensive guide to the Turk Algorithm implementation
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) - Fundamental concepts

### AI Usage
AI assistance was utilized for:
- **Documentation generation:** Creating and formatting this README.md
- **Algorithm explanation:** Clarifying complex Turk Algorithm concepts

No AI-generated code was directly used in the core implementation. All sorting logic and algorithm implementation were written manually.

*Sorting integers efficiently, one operation at a time.*
