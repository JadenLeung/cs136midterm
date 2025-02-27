#include <stdio.h>
#include <string.h>


// mod_seven(num): Reads a number, avoiding whitespace, and reduces 
//            it to a number < 10 by the following strategy:
//   1) Take the last digit and double it
//   2) Subtract it from the remaining digits
//   3) Repeat until number < 10
//  Note that num has no special meaning, it's just a parameter you can use to pass
//  numbers through recursive loops
//  You must use recursion, without making any new functions.
// Examples: (quotations represent standard input)
//      "1 2 3 4" -> 1234 -> 123 - (4 * 2) -> 115 -> 11 - (5 * 2) -> 1
//      " 777 " -> 63 -> 0
int mod_seven(int num) {
  return 0;
}

int main(void) {
  // Do not change code below
  printf("%d", mod_seven(0));
}
