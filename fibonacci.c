#include <stdio.h>
#include <string.h>
#include "fibonacci.h"

// this file handles the fibonacci calculation using memoization
// we store the previously calculated values in an array to avoid
// calculating them again when they're needed
// this approach is more efficient time wise, but uses more memory

// array to store calculated fibo nums
static char memo_array[MAX_INDEX + 1][MAX_DIGITS];

static void big_add(char *result, const char *num1, const char *num2) {
    int carry = 0;
    char temp[MAX_DIGITS];
    int temp_idx = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    
    for (int i = 0; i < MAX_DIGITS - 1; i++) {
        int d1 = (i < len1) ? num1[len1 - 1 - i] - '0' : 0;
        int d2 = (i < len2) ? num2[len2 - 1 - i] - '0' : 0;
        int sum = d1 + d2 + carry;
        temp[temp_idx++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    
    if (carry && temp_idx < MAX_DIGITS - 1) {
        temp[temp_idx++] = carry + '0';
    }
    
    // Reverse and copy to result
    int j = 0;
    for (int i = temp_idx - 1; i >= 0; i--) {
        result[j++] = temp[i];
    }
    result[j] = '\0';

    // remove leading zeros except leave one if it's all zeros
    {
        int start = 0;
        while (result[start] == '0' && result[start + 1] != '\0') {
            start++;
        }
        if (start > 0) {
            memmove(result, result + start, strlen(result + start) + 1);
        }
    }
}

// set memo array and init base cases
int fibonacci_init(void)
{
    int ix;

    for (ix = 0; ix <= MAX_INDEX; ix++)
    {
        memo_array[ix][0] = '\0';  // mark as not calculated yet
    }

    // set base cases - fib(0) = 0 and fib(1) = 1
    strcpy(memo_array[0], "0");
    strcpy(memo_array[1], "1");

    return 0;
}

// calc nth fibo num using memo array
// returns NULL if index is invalid
// otherwise returns the calculated fibo num
const char* fibonacci_calc(int index)
{
    if (index < 0 || index > MAX_INDEX)
    {
        printf("Error: index %d is out of range [0..%d].\n", index, MAX_INDEX);
        return NULL;  // bad index, return error
    }

    // check if already calculated this one
    if (memo_array[index][0] != '\0')
    {
        return memo_array[index];
    }

    // Get the previous two numbers
    const char* fib1 = fibonacci_calc(index - 1);
    const char* fib2 = fibonacci_calc(index - 2);
    
    if (!fib1 || !fib2) {
        return NULL;
    }

    // Calculate new value
    big_add(memo_array[index], fib1, fib2);
    return memo_array[index];
}
