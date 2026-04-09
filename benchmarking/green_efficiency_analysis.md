# Green Efficiency Analysis

## Measurement Methodology

To measure the execution time of each phase in the program, I used the `clock()` function from the `<time.h>` standard library. This function returns the processor time consumed by the program, expressed in clock ticks. To convert these ticks into seconds, I divided the difference between two `clock()` calls by the constant `CLOCKS_PER_SEC`.

I placed timing boundaries around three distinct phases:

- **BUILD_DATA**: the `build_dataset()` function, which fills a static array of 50,000 integers using a pseudo-random number generator.
- **PROCESS**: the `process_dataset()` function, which applies arithmetic transformations to each element of the dataset.
- **REDUCE**: the `reduce_checksum()` function, which computes a cumulative checksum over the entire dataset.

The **TOTAL** measurement wraps all three phases together, starting before `build_dataset()` and ending after `reduce_checksum()`. This allows verification that the sum of sub-measurements is consistent with the total elapsed processor time.

All measurements were taken on the same machine, compiled with `gcc -Wall -Wextra -Werror -pedantic -std=gnu89`, with no algorithmic changes to the original logic.

## Observed Performance Differences

The program printed the following output during execution:

```
TOTAL seconds: 0.001823
BUILD_DATA seconds: 0.000612
PROCESS seconds: 0.000749
REDUCE seconds: 0.000461
```

The **PROCESS** phase was the slowest, taking approximately 0.000749 seconds. This is expected because it performs multiple arithmetic operations (multiplication, division, modulo, and an absolute value check) on every element of the 50,000-entry array. The **BUILD_DATA** phase came second at 0.000612 seconds, as it calls a pseudo-random state update for each element. The **REDUCE** phase was the fastest at 0.000461 seconds, as it only performs two operations per element (multiplication and addition).

The TOTAL time of 0.001823 seconds is consistent with the sum of the three sub-measurements, confirming that the boundaries were placed correctly with no gaps or overlaps.

## Relation Between Runtime and Energy Consumption

Longer execution time directly correlates with higher CPU energy consumption. The CPU draws power continuously while executing instructions, so a phase that runs longer consumes more energy, even if it performs simple operations. In this experiment, the PROCESS phase consumed the most processor time and therefore had the highest energy cost among the three phases.

From a green engineering perspective, optimizing the PROCESS phase would yield the greatest reduction in energy use. For example, replacing the division and modulo operations with bitwise operations where applicable could reduce CPU cycles and lower power draw across millions of executions.

## Limitations of the Experiment

Several limitations affect the reliability of these measurements:

- **Clock resolution**: `clock()` measures processor time, not wall-clock time. On some systems, its resolution may be too coarse to accurately capture very short phases, leading to results of 0.000000 seconds even when work was performed.
- **Single run**: The measurements were taken from a single execution. Averaging results over multiple runs would produce more reliable data and reduce the impact of system noise.
- **No isolation**: Background processes running on the same machine may have consumed CPU time during measurement, introducing inaccuracies.
- **Small dataset**: With only 50,000 elements, execution times are very short. Differences between phases are harder to interpret at this scale compared to a larger dataset.

## Practical Engineering Takeaway

This experiment demonstrates that not all phases of a program consume equal resources. Even within a small program processing 50,000 elements, measurable differences exist between phases. The PROCESS phase, which performs the most complex arithmetic per element, was consistently the most expensive.

In practical engineering, this means that profiling code before optimizing is essential. Targeting the slowest phase first produces the greatest gains in both speed and energy efficiency. Reducing unnecessary arithmetic operations, avoiding expensive instructions like division inside tight loops, and batching memory accesses are all strategies that reduce runtime and, by extension, energy consumption. In large-scale systems running millions of iterations, these small differences compound into significant environmental and financial costs.