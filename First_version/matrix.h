#include "type_conversion.h"

#define ELEM a->data[row][column]
#define TYPEELEM a->typematrix[row][column]

typedef struct{
    int n;
    int m;
    void *** data;
    int ** typematrix;
}Matrix;

static int Is_Int(Complex * a);
static int From_Complex_to_Int(Complex * a);
void Size_Matrix(Matrix *a);
void Init_Matrix(Matrix *a);
void Fill_Matrix(Matrix *a);
void Print_Matrix(const Matrix *a);
void Free_Matrix(Matrix *a);

static int Is_Int(Complex * a){
    return (a->Im == 0);
}

static int From_Complex_to_Int(Complex * a){
    return (int)a->Re;
}

void Size_Matrix(Matrix *a){
    printf("Введите размер матрицы (n m): ");
    int er;
    er = scanf("%d %d", &a->n, &a->m);
    while(er != 2){
        er = scanf("%d %d", &a->n, &a->m);
        printf("Вы ввели что-то не то...");
    }
}

void Init_Matrix(Matrix *a) {
    a->data = (void ***)malloc(a->n * sizeof(void **));
    a->typematrix = (int **)malloc(a->n * sizeof(int *));
    for (int i = 0; i < a->n; i++) {
        a->data[i] = (void **)malloc(a->m * sizeof(void *));
        a->typematrix[i] = (int *)malloc(a->m * sizeof(int));
    }
}

void Fill_Matrix(Matrix *a){
    Init_Matrix(a);
    for(int i = 0; i < a->n; i++){
        for(int j = 0; j < a->m; j++){
            Enter_Element(a, i, j);
        }
    }
}

void Print_Matrix(const Matrix *a){
    for(int row = 0; row < a->n; row++){
        for(int column = 0; column < a->m; column++){
            Print_Element(TYPEELEM, ELEM);
        }
        printf("\n");
    }
}

void Free_Matrix(Matrix *a){
    for(int i = 0; i < a->n; i++){
        for(int j = 0; j < a->m; j++){
            free(a->data[i][j]);
        }
        free(a->data[i]);
        free(a->typematrix[i]);
    }
    free(a->data);
    free(a->typematrix);
}