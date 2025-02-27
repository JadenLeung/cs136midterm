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


int power(int base, int e) {
  if (e == 1) {
    return base; 
  }
  return base * power(base, e - 1);
}

int count(int digits) {
  if (digits == 0) {
    return 0; 
  }
  if (digits == 1) {
    return 1;
  }
  int total = count(digits - 1); 
  return (9 * total + power(10, digits - 1) + count(digits - 1));
  
}

int count_ones(int n); 

int count2(int first_digit, int other_digits, int digits) {
  if (digits == 0) {
    return 0; 
  }

  if (digits == 1) {
    return 1;
  }

  int temp = other_digits % (power(10, digits - 1)); 


  int tot2 = count(digits - 1);
  int left = 0;
  
  if (first_digit == 1) {
    left = temp + 1;
  } else if (first_digit == 0) {
    left = 0; 
  } else {
    left = power(10, digits - 1);
  }
 
 
  return (count_ones(temp) + first_digit * tot2 + left);
  
}


// Given an integer n, count the total number of digit 1 appearing 
//     in all non-negative integers less than or equal to n.
int count_ones(int number) {
  
  if (number == 0) {
    return 0; 
  }
 
  int first_digit = number;
  int digits = 0; 
  
  while (first_digit >= 10) {
    first_digit /= 10; 
    digits++; 
  }
  
  if (digits == 0) {
    return 1; 
  }

  digits++; 
  int other_digits = number % (power(10, digits - 1)); 
  
  return count2(first_digit, other_digits, digits);
}



int main(void) {
  assert(count_ones(20) == 12);
}

