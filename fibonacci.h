#ifndef FIBONACCI_H
#define FIBONACCI_H

// define  max fibonacci index we will handle
#define MAX_INDEX 1000 /* The maximum Fibonacci index we will handle */

// init memoization array
int fibonacci_init(void);

// calculate fibo num at index
int fibonacci_calc(int index);

#endif
