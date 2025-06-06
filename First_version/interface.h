#include "matrix_operation.h"

void Add_Matrix(Matrix list[], int *c);
void Delete_Matrix(Matrix list[], int *c);
void Exit(Matrix list[], int c);
void Print_All(Matrix list[], int c);
void Print(Matrix list[]);
void Multy_on(Matrix list[]);
void Sum(Matrix list[]);
Matrix Multy_mat(Matrix list[]);
Matrix Trans(Matrix list[]);

void Add_Matrix(Matrix list[], int *c){
    if (*c >= 10) {
        printf("Прости, я слишком глупа, больше 10 матриц не могу хранить\n");
        return;
    }
    Size_Matrix(&list[*c]);
    Fill_Matrix(&list[*c]);
    (*c)++;
}

void Delete_Matrix(Matrix list[], int *c){
    if (*c == 0) {
        printf("Мне нечего удалять\n");
        return;
    }
    
    int number;
    printf("Какую матрицу вы хотите удалить? (1-%d): ", *c);
    scanf("%d", &number);
    
    if (number < 0 || number >= *c) {
        printf("Прости, я не нахожу матрицу под таким номером, может ты ошибся?\n");
        return;
    }
    
    Free_Matrix(&list[number]);
    for(int i = number; i < *c-1; i++){
        list[i] = list[i+1];
    }
    (*c)--;
}

void Exit(Matrix list[], int c){
    for(int i = 0; i < c; i++){
        Free_Matrix(&list[i]);
    }
}

void Print_All(Matrix list[], int c){
    for(int i = 0; i < c; i++){
        printf("%d matrix\n", i+1);
        Print_Matrix(&list[i]);
    }
}

void Print(Matrix list[]){
    int number;
    printf("Какую бы матрицу вы бы хотели вывести? ");
    scanf("%d", &number);
    Print_Matrix(&list[number - 1]);
}

void Multy_on(Matrix list[]){
    int number;
    printf("Какую бы матрицу вы бы хотели умножить на число? ");
    scanf("%d", &number);
    Multi_Matrix(&list[number - 1]);
}

void Sum(Matrix list[]){
    int number1;
    int number2;
    printf("Какие бы матрицы вы бы хотели сложить? ");
    scanf("%d %d", &number1, &number2);
    Sum_Matrix(&list[number1 - 1], &list[number2 - 1]);
}

Matrix Multy_mat(Matrix list[]) {
    int number1, number2;
    printf("Какие матрицы вы хотите перемножить? ");
    scanf("%d %d", &number1, &number2);
    if (list[number1 - 1].m != list[number2 - 1].n) {
        printf("Я не могу сложить эти матрицы, у них размеры не сходятся\n");
    }
    return Matrix_Product(&list[number1 - 1], &list[number2 - 1]);
}

Matrix Trans(Matrix list[]){
    int number;
    printf("Какую бы матрицу вы  бы хотели  транспонировать? ");
    scanf("%d", &number);
    return  Matrix_Transposition(&list[number - 1]);
}