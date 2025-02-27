#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


// Given an integer n, count the total number of digit 1 appearing 
//     in all non-negative integers less than or equal to n.
int count_ones(int n) {
    return 0; 
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