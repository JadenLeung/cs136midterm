#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct player {
    char *name;
    int points;
    int fg2;
    int fg3;
};

int compareval = 0;

const struct player BRONNY = {"Bronny", 18, 37, 21};


int one_v_one(struct player *a, struct player *b) {
    printf("%s vs %s", a->name, b->name);
}

int main(void) {
    char name[7] = "LeBron";
    char *storename = name;
    struct player LEBRON = {name, 25, 25, 40};
    one_v_one(&LEBRON, &BRONNY);
}