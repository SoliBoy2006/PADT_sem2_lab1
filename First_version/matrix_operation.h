#include "matrix.h"

void Sum_Matrix(Matrix *a, Matrix *b);
void Multi_Matrix(Matrix *a);
Matrix Matrix_Product(const Matrix* a, const Matrix* b);
Matrix Matrix_Transposition(const Matrix *a);

void Sum_Matrix(Matrix *a, Matrix *b){
    if(a->n == b->n && a->m == b->m){
        for(int i = 0; i < a->n; i++){
            for(int j = 0; j < a->m; j++){
                a->typematrix[i][j] = (a->typematrix[i][j] || b->typematrix[i][j]);
                Summa(&a->data[i][j], &b->data[i][j], a->typematrix [i][j], b->typematrix[i][j]);
            }
        }
    }
    else {
        printf("Я не могу сложить эти матрицы, у них размеры не сходятся.\n");
    }
}

void Multi_Matrix(Matrix *a){
    int number;
    printf("На сколько вы хотите умножить матрицу: ");
    scanf("%d", &number);
    for(int i = 0; i < a->n; i++){
        for(int j = 0; j < a->m; j++){
            Multi(a->data[i][j], &number, a->typematrix[i][j], 0);
        }
    }
}

Matrix Matrix_Product(const Matrix* a, const Matrix* b) {
    Matrix c;
    c.n = a->n;
    c.m = b->m;
    Init_Matrix(&c);
    for (int row = 0; row < c.n; row++) {
        for (int column = 0; column < c.m; column++) {
            Complex sum;
            sum.Re = 0;
            sum.Im = 0;
            for (int s = 0; s < a->m; s++) {
                Complex product = Multi2(a->data[row][s], b->data[s][column], a->typematrix[row][s], b->typematrix[s][column]);
                sum = Summa2(&product, &sum, 1, 1);
            }
            if (Is_Int(&sum)) {
                c.typematrix[row][column] = 0;
                Assignment(&c.data[row][column], c.typematrix[row][column], &sum.Re);
            } else {
                c.typematrix[row][column] = 1;
                Assignment(&c.data[row][column], c.typematrix[row][column], &sum);
                
            }
        }
    }
    return c;
}

Matrix Matrix_Transposition(const Matrix *a) {
    Matrix c;
    c.n = a->m;
    c.m = a->n;
    Init_Matrix(&c);
    
    for (int row = 0; row < c.n; row++) {
        for (int column = 0; column < c.m; column++) {
            c.typematrix[row][column] = a->typematrix[column][row];
            Assignment(&c.data[row][column], c.typematrix[row][column], a->data[column][row]);
        }
    }
    return c;
}