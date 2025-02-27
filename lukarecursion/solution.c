#include <stdio.h>
#include <string.h>

int mod_seven(int num) {
  char temp = 0;
  if (scanf(" %c", &temp) == 1) {
    int result = mod_seven(num * 10 + (temp - '0'));
    if (result < 10) {
      return result;
    }
    int sol = (result / 10) - (result % 10 * 2);
    return sol;
  } else {
    return num;
  }
}

int main(void) {
  printf("%d", mod_seven(0));
}
