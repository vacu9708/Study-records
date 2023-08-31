# IO bound
IO-bound refers to a condition where the system spends more time doing input/output operations than doing computation.<br>
In such cases, the CPU is often idle, waiting for data from disks, network, or user input.
# CPU bound
CPU-bound means the system spends most of its time doing computation.<br>
The CPU is actively crunching numbers and is not held up by IO operations.
# Optimization
Optimizing for each scenario requires different strategies.<br>
## I/O-Bound Optimization Strategies
- `Hardware upgrades:` Upgrade the hardware, such as using better SSDs or adding more network bandwidth.
- `Asynchronous I/O:` Use asynchronous I/O operations to avoid blocking the main thread. This allows the program to continue doing useful work while waiting for I/O operations to complete.
- `Caching:` Store frequently accessed data in memory to reduce the number of I/O operations.
- `Batching:` Group multiple I/O operations together to reduce the overhead of each I/O request.
- `Sharding:` Distribute data across multiple disks or servers to parallelize access and increase throughput.
- `Prefetching:` Preload data before it is actually needed
- `Buffering:` Use buffers to read or write large chunks of data at once, reducing the number of system calls.
- `Compression:` Compress data to reduce the amount of I/O. However, be cautious as this could make the task CPU-bound.
## CPU-Bound Optimization Strategies
- `Hardware upgrades:` Upgrading the CPU or adding more RAM can be the most straightforward way to improve performance.
- `Algorithmic optimization:` Use more efficient algorithms to reduce time complexity, including caching where the results of expensive function calls are stored and the cached result is returned when the same inputs occur again.
- `Parallel computing:` Divide tasks into smaller sub-tasks and process them concurrently using multiple cores or even multiple machines.
- `Offloading:` Offload certain tasks to specialized hardware like GPUs.
- `Reducing function calls:` Inline functions or reduce the number of function calls to minimize overhead.
- `Compiler optimization:` Use JIT compilers to convert interpreted code into machine code, which can be executed more quickly. Or use compiler optimization flags to generate more efficient machine code.
