#include <stdio.h>
#include "fibonacci.h"
// Not sure if this is what you want, but I'm not sure
//how to do it otherwise for test cases.
//only other thing I can think of is tests.MD


// simple test driver for  memoized fibo stuff
// just inits everything and runs through  test cases

// helper func to check if fib(index) matches what we expect
// returns 0 if it passes, 1 if it fails
static int test_single_fib(int index, int expected)
{
    int actual;

    actual = fibonacci_calc(index);

    if (actual != expected)
    {
        printf("Test FAILED for fib(%d): expected %d, got %d.\n",
               index, expected, actual);
        return 1;
    }

    printf("Test PASSED for fib(%d): got %d.\n", index, actual);
    return 0;
}

int main(void)
{
    int any_failures;
    int result;

    any_failures = 0;

    // set up memo array
    result = fibonacci_init();
    if (result != 0)
    {
        printf("Error: fibonacci_init() returned %d.\n", result);
        return 1;
    }

    // run through some basic fibo nums we know are right
    any_failures += test_single_fib(0, 0);
    any_failures += test_single_fib(1, 1);
    any_failures += test_single_fib(2, 1);
    any_failures += test_single_fib(3, 2);
    any_failures += test_single_fib(4, 3);
    any_failures += test_single_fib(5, 5);
    any_failures += test_single_fib(6, 8);
    any_failures += test_single_fib(7, 13);
    any_failures += test_single_fib(10, 55);

    // try some bad inputs to make sure we handle them correctly
    any_failures += test_single_fib(-1, -1);
    any_failures += test_single_fib(51, -1);

    if (any_failures == 0)
    {
        printf("\nAll Fibonacci tests PASSED!\n");
        return 0;
    }
    else
    {
        printf("\nSome tests FAILED. See above messages.\n");
        return 1;
    }
}
