#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

// Computes base^e
// Requires:  e is positive 
//            base is non-negative 
int power(int base, int e) {
  assert(e > 0); 
  assert(base >= 0); 
  if (e == 1) {
    return base; 
  }
  return base * power(base, e - 1);
}


// Computes the number of digit 1s appearing in all non-negative integers 
//      less than a string of 9s with some number of digits 
// Requires: digits is positive 
// Examples:  count(1) => 1
//            count(2) => 20
// count(2) <=> count_ones(99)
// Given as count_ones(99) = |{91, 81, 71, 61, 51, 41, 31, 21, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 1}|
int count(int digits) {
  assert(digits > 0 )
  if (digits == 1) {
    return 1;
  }

  // Find the size of count(digits - 1)
  int total = count(digits - 1); 

  // Suppose we want to count the ones for 999
  // If we have the number of ones for 99, then there are 10 times that many in 999
  // Since we have 9XX, 8XX, 7XX, ..., 0XX, and we must add the number of times 1 occurs in each of these strings
  // Additionally we have the case for 1XX, where we want to add 1 for all possibilities for XX since a 1 precedes it
  // This is calculated by 10^(digits - 1)
  return (10 * total + power(10, digits - 1));

  
}

//  To use mutual recursion we declare count_ones
int count_ones(int n); 


// Recursive helper for count_ones
// first_digit is the first digit of n
// other_digits are the other remaining digits of n after removing the first_digit 
// digits is the number of digits in n
// Ex. if we pass count_ones 856, we would call count2 with (8, 56, 3)
int count2(int first_digit, int other_digits, int digits) {

  int temp = other_digits % (power(10, digits - 1)); 

  int tot2 = count(digits - 1);
  int left = 0;
  
  if (first_digit == 1) {
    left = temp + 1;
  } else {
    left = power(10, digits - 1);
  }
 
  return (count_ones(temp) + first_digit * tot2 + left);
  
}




// Given an integer n, count the total number of digit 1 appearing 
//     in all non-negative integers less than or equal to n.
// Requires: n is non-negative 
// Examples:    count_ones(4) => 1
//              count_ones(12) = 6
int count_ones(int number) {
  
  if (number == 0) {
    return 0; 
  }
 
  int first_digit = number;
  int digits = 0; 
  
  // Finds the first digit of n as well as the number of digits in n
  while (first_digit >= 10) {
    first_digit /= 10; 
    digits++; 
  }
  // This case only happens when n < 10, in which case there can only be one 1 digit
  if (digits == 0) {
    return 1; 
  }
  // The above while loop stops 1 early for counting the number of digits 
  digits++; 


  // This calculates n with its last digit removed
  // 856 -> 56
  int other_digits = number % (power(10, digits - 1)); 
  

  return count2(first_digit, other_digits, digits);
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
    assert(count_ones(495827365) == 497521277); 
}



// Example of count_ones(56)
//    call count2(5, 6, 2)
//    we compute the number of 1s in X by using count(1) => 1
//    Recursively call count_ones(6)
//        call count2(6, 0, 1)
//        digits is 1 so return 1
//    left would be 10 since the first digit is 5 and we have 2 digits, 
//    We return the total 1 + 5 * 1 + 10 = 16



// Note that you can solve this question with 1 recursive function, but it will require some smart math