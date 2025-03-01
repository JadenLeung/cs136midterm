#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


// Given an integer n, count the total number of digit 1 appearing 
//     in all non-negative integers less than or equal to n.
// Use recursion for this question 
// Easy implementation, pass all asserts except the last one
// Hard implementation, pass all asserts including the last one 
//      (you will need an efficient solution)
// Requires: n is non-negative 
// Examples:    count_ones(4) => 1
//              count_ones(12) = 5
int count_ones(int n) {
    return 0; 
}


int main(void) {
    assert(count_ones(0) == 0);
    assert(count_ones(1) == 1);
    assert(count_ones(10) == 2); 
    assert(count_ones(11) == 4); 
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