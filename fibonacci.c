#include <stdio.h>
#include <limits.h>
#include "fibonacci.h"

// this file handles the fibonacci calculation using memoization
// we store the previously calculated values in an array to avoid
// calculating them again when they're needed
// this approach is more efficient time wise, but uses more memory

// array to store  calculated fibo nums
static int memo_array[MAX_INDEX + 1];

// set memo array and init  base cases
int fibonacci_init(void)
{
    int ix;

    for (ix = 0; ix <= MAX_INDEX; ix++)
    {
        memo_array[ix] = -1;  // mark as not calculated yet
    }

    // set base cases - fib(0) = 0 and fib(1) = 1
    memo_array[0] = 0;
    memo_array[1] = 1;

    return 0;
}

// calc nth fibo num using memo array
// returns -1 if index is invalid
// otherwise returns the calculated fibo num
int fibonacci_calc(int index)
{
    if (index < 0 || index > MAX_INDEX)
    {
        printf("Error: index %d is out of range [0..%d].\n", index, MAX_INDEX);
        return -1;  // Bad index, return error
    }

    // check if already calculated this one
    if (memo_array[index] != -1)
    {
        return memo_array[index];
    }

    // Get the previous two numbers
    int fib1 = fibonacci_calc(index - 1);
    int fib2 = fibonacci_calc(index - 2);
    
    // Check for overflow or if either previous calculation failed
    if (fib1 == -1 || fib2 == -1 || 
        (fib1 > 0 && fib2 > INT_MAX - fib1))  // This checks for overflow
    {
        printf("Error: fibonacci(%d) would overflow.\n", index);
        return -1;
    }

    // haven't calculated it yet, do it now
    memo_array[index] = fib1 + fib2;
    return memo_array[index];
}
