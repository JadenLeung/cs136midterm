#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct player {
    char *name;
    int fg2;
    int fg3;
};

const int POSSESSIONS = 20;

struct player BRONNY = {"Bronny", 37, 21};

void one_v_one(struct player *a, struct player *b) {
    printf("%s vs %s\n", a->name, b->name);
    if (strcmp(a->name, b->name) > 0) {
        b->name[0] = 'J';
    } else {
        b->name += 2;
    }
    // SNAPSHOT A
    printf("%s vs %s\n", a->name, b->name);
    a->name++;
    char temp[7] = {0};
    strcpy(temp, a->name);
    *temp = 'S';
    temp[3] = '\0';
    printf("%s vs %s\n", temp, b->name);
    // SNAPSHOT B
    strcpy(b->name, temp);
    if (a->fg2 * 2 < b->fg3 * 3) {
        b->name[1] = 'u';
    } else {
        temp[1] = 'u';
    }
    // SNAPSHOT C
    printf("%s vs %s\n", temp, b->name);
}

int main(void) {
    char name[8] = "LeBron";
    char *storename = name;
    struct player LEBRON = {storename, 25, 40};
    one_v_one(&BRONNY, &LEBRON);
}