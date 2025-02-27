#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


int slow(int n) {
    if (n == 0) {
        return 0;
    }
    if (n % 10 == 1) {
        return 1 + slow(n/10);
    }
    return slow(n/10); 
}

// Given an integer n, count the total number of digit 1 appearing 
//     in all non-negative integers less than or equal to n.
int count_ones(int n) {
    if (n == 0) {
        return 0; 
    }
    return slow(n) + count_ones(n-1); 
}

int main(void) {
  assert(count_ones(20) == 12);
}