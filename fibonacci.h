#ifndef FIBONACCI_H
#define FIBONACCI_H

// define max fibonacci index we will handle
#define MAX_INDEX 1000 // the max fibo index we will handle 
#define MAX_DIGITS 350 // max digits needed for fib(1000)

// init memoization array
int fibonacci_init(void);

// calculate fibo num at index
const char* fibonacci_calc(int index);

#endif
