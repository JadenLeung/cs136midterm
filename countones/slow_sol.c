#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

// Given an integer n, ones will count the number of digit 1 appearing in n
int ones(int n) {
    if (n == 0) {
        return 0;
    }
    if (n % 10 == 1) {
        return 1 + ones(n / 10);
    }
    return ones(n / 10); 
}

// Given an integer n, count the total number of digit 1 appearing 
//     in all non-negative integers less than or equal to n.
int count_ones(int n) {
    if (n == 0) {
        return 0; 
    }
    return ones(n) + count_ones(n - 1); 
}

int main(void) {
    assert(count_ones(0) == 0);
    assert(count_ones(1) == 1);
    assert(count_ones(10) == 2); 
    assert(count_ones(11) == 3); 
    assert(count_ones(19) == 12);
    assert(count_ones(20) == 12);
    assert(count_ones(99) == 20);
    assert(count_ones(100) == 21);
    assert(count_ones(101) == 23); 
    assert(count_ones(111) == 36);
    assert(count_ones(856) == 276);  
    assert(count_ones(1111) == 448); 
    //assert(count_ones(495827365) == 497521277); 
}