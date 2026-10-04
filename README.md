# DSA Assignment: Stack and Circular Queue Using Arrays

This repository contains C++ implementations of a stack and a circular queue using arrays. Neither implementation uses a built-in stack or queue library.

## Files

- `stack.cpp` — fixed-capacity array stack with `PUSH`, `POP`, `PEEK`, and `DISPLAY` operations, including overflow and underflow handling.
- `circular_queue.cpp` — array-based circular queue with `ENQUEUE`, `DEQUEUE`, `FRONT`, and `DISPLAY` operations.

## Stack operation complexity

| Operation | Time | Auxiliary space |
|---|---:|---:|
| `PUSH(x)` | O(1) | O(1) |
| `POP()` | O(1) | O(1) |
| `PEEK()` | O(1) | O(1) |
| `DISPLAY()` | O(n) | O(1) |

The stack array reserves O(CAPACITY) total space. When a push is attempted at capacity, the program reports Stack Overflow and leaves the stack unchanged. Popping an empty stack reports Stack Underflow. A fixed-size array cannot grow; a larger array or resizable storage is needed for additional capacity.

## Circular queue comparison and complexity

1. **Memory utilization:** A circular queue wraps the rear index to the beginning and reuses positions freed by dequeues.
2. **Time:** `ENQUEUE` and `DEQUEUE` both run in O(1) time because they update indices and the element count without shifting elements.
3. **Space:** The array uses O(CAPACITY) space, with O(1) auxiliary space for indices and count.
4. **Linear queue limitation:** In a simple linear array queue, the rear may reach the last position even though dequeues have freed slots at the beginning. This false overflow wastes available space. A circular queue reuses those slots.

The queue tracks its item count to distinguish an empty queue (`count == 0`) from a full queue (`count == CAPACITY`).

## Compile and run

Compile each file separately because each contains its own `main()` function:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic stack.cpp -o stack
./stack

g++ -std=c++17 -Wall -Wextra -pedantic circular_queue.cpp -o circular_queue
./circular_queue
```

On Windows with MinGW, run the resulting executables as `stack.exe` and `circular_queue.exe`.
