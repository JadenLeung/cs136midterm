#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct matrix{
    int values[100];
    int height;
    int width;
};

// matrix_mult(m1, m2, matrix_product) is a function that takes in 2 matrices 
// and if possible, will perform matrix multiplication on them. the values of  
// the multiplication will be stored in matrix_product's values, and the height
// and width of matrix product will be stored in matrix_product's fields 
// respectively. returns true if the matrix multiplication is successful.
//
// Requires:
//   all pointers are not null
// Effects:
//   May modify matrix_product

bool matrix_mult(const struct matrix * m1, const struct matrix * m2, struct matrix * matrix_product) {

    // matrix multiplication condition
    if (m1->width != m2->height){
        return false;
    } 

    // MxN * NxO results in an MxO matrix 
    matrix_product->height = m1->height;
    matrix_product->width = m2->width;

    for (int i = 0; i < m2->width; i++){
        for (int j = 0; j < m1->height; j++){
            int sum = 0;
            for (int k = 0; k < m1->width; k++){
                sum += (m1->values[(j * m1->width) + k] 
                        * m2->values[((m2->width * k) + i)]);
            }
            matrix_product->values[(matrix_product->width * j) + i] = sum;
        }
    }

    return true;
}

// print_matrix(m) prints out a matrix.
// effects: 
void print_matrix(struct matrix m){
    for (int i = 0; i < m.height; i++){
        printf("[ ");
        for (int j = 0; j < m.width; j++){
            printf("%2d ", m.values[(m.width * i) + j] );
        }
        printf(" ]\n");
    }
}

// main function that allows for some testing!
int main(void) {
    struct matrix m1 = {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3};
    struct matrix m2 = {{1, 2, 3, 4, 5, 6}, 3, 2};
    struct matrix product = {{0}, 0, 0};
    if (matrix_mult(&m1, &m2, &product)){
        print_matrix(product);
    }
}