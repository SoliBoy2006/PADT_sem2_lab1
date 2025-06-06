#include "complex.h"

static void Summa(void **a, void **b, int type_a, int type_b);
static Complex Summa2(void *a, void *b, int type_a, int type_b);
static void Multi(void *a, void *b, int type_a, int type_b);
static Complex Multi2(void *a, void *b, int type_a, int type_b);
void Malloc(void ***target, int type, int val1, int val2);
void Assignment(void ***target, int type, void * val);
static void Enter_Element(Matrix *a, int row, int column);
void Print_Element(int type, void * elem);

static void Summa(void **a, void **b, int type_a, int type_b){
    if (type_a && type_b){
        Sum_Com((Complex *)*a, (Complex *)*b);
    }
    else if (!type_a && type_b){
        Complex a_com;
        a_com.Re = *(int *)*a;
        a_com.Im = (int)0;
        Sum_Com(&a_com, (Complex *)*b);
    }
    else if (type_a && !type_b){
        Complex b_com;
        b_com.Re = *(int *)*b;
        b_com.Im = (int)0;
        Sum_Com((Complex *)*a, &b_com);
    }
    else if (!type_a && !type_b){
        *(int *) *a = *(int *)*a + *(int *)*b;
    }
    else {
        printf("smth went wrong");
    }
}

static Complex Summa2(void *a, void *b, int type_a, int type_b){
    if (type_a && type_b){
        return Sum_Com2((Complex *)a, (Complex *)b);
    }
    else if (!type_a && type_b){
        Complex a_com;
        a_com.Re = *(int *)a;
        a_com.Im = (int)0;
        return Sum_Com2(&a_com, (Complex *)b);
    }
    else if (type_a && !type_b){
        Complex b_com;
        b_com.Re = *(int *)b;
        b_com.Im = (int)0;
        return Sum_Com2((Complex *)a, &b_com);
    }
    else if (!type_a && !type_b){
        Complex c_com;
        c_com.Re = *(int*)a + *(int*)b;
        c_com.Im = 0;
        return c_com;
    }
    else {
        printf("smth went wrong");
    }
}

static void Multi(void *a, void *b, int type_a, int type_b){
    if (type_a && type_b){
        Product_Com((Complex *)a, (Complex *)b);
    }
    else if (!type_a && type_b){
        Complex a_com;
        a_com.Re = *(int *)a;
        a_com.Im = (int)0;
        Product_Com(&a_com, (Complex *)b);
    }
    else if (type_a && !type_b){
        Complex b_com;
        b_com.Re = *(int *)b;
        b_com.Im = (int)0;
        Product_Com((Complex *)a, &b_com);
    }
    else if (!type_a && !type_b){
        *(int *) a = (*(int *)a) * (*(int *)b);
    }
    else {
        printf("smth went wrong");
    }
}

static Complex Multi2(void *a, void *b, int type_a, int type_b){
    if (type_a && type_b){
        return Product_Com2((Complex *)a, (Complex *)b);
    }
    else if (!type_a && type_b){
        Complex a_com;
        a_com.Re = *(int *)a;
        a_com.Im = (int)0;
        return Product_Com2(&a_com, (Complex *)b);
    }
    else if (type_a && !type_b){
        Complex b_com;
        b_com.Re = *(int *)b;
        b_com.Im = (int)0;
        return Product_Com2((Complex *)a, &b_com);
    }
    else if (!type_a && !type_b){
        Complex c_com;
        c_com.Re = *(int*)a * *(int*)b;
        c_com.Im = 0;
        return c_com;
    }
    else {
        printf("smth went wrong");
    }
}

void Malloc(void ***target, int type, int val1, int val2) {
    switch(type) {
        case 0:
            *target = malloc(sizeof(int));
            *(int*)*target = val1;
            break;
            
        case 1:
            *target = malloc(sizeof(Complex));
            ((Complex*)*target)->Re = val1;
            ((Complex*)*target)->Im = val2;
            break;
            
        default:
            *target = NULL;
    }
}

void Assignment(void ***target, int type, void * val){
    switch(type) {
        case 0:
            *target = malloc(sizeof(int));
            *(int*)*target = *(int*)val;
            break;
            
        case 1:
            *target = malloc(sizeof(Complex));
            (Complex*)*target = *(Complex*)val;
            break;
            
        default:
            *target = NULL;
    }
}

static void Enter_Element(Matrix *a, int row, int column) {
    char tmp[50];
    int valid_input = 0;
    
    while (!valid_input) {
        printf("Введите %d-%d элемент: ", row+1, column+1);
        scanf("%49s", tmp);
        
        char *endptr;
        long int_val = strtol(tmp, &endptr, 10);
        if (*endptr == '\0') {
            a->typematrix[row][column] = 0;
            Malloc(&a->data[row][column], a->typematrix[row][column], int_val, 0);
            valid_input = 1;
            continue;
        }
        
        int re, im;
        char sign, i_char;
        int parsed = sscanf(tmp, "%d%c%di%c", &re, &sign, &im, &i_char);
        
        if (parsed == 3 || (parsed == 4 && i_char == 'i')) {
            if (sign == '-') {
                im = -im;
            }
            size_t len = strlen(tmp);
            if (tmp[len-1] == 'i') {
                a->typematrix[row][column] = 1;
                Malloc(&a->data[row][column], a->typematrix[row][column], re, im);
                valid_input = 1;
                continue;
            }
        }
        if (tmp[0] == '-') {
            if (sscanf(tmp, "-%d%c%di%c", &re, &sign, &im, &i_char) == 3 || 
                (sscanf(tmp, "-%d%c%di%c", &re, &sign, &im, &i_char) == 4 && i_char == 'i')) {
                
                re = -re;
                if (sign == '-') {
                    im = -im;
                }
                
                size_t len = strlen(tmp);
                if (tmp[len-1] == 'i') {
                    a->typematrix[row][column] = 1;
                    Malloc(&a->data[row][column], a->typematrix[row][column], re, im);
                    valid_input = 1;
                    continue;
                }
            }
        }
        printf("Прости, я понимаю только целые и комплексные числа вида a+bi.\n");
    }
}

void Print_Element(int type, void * elem){
    switch(type){
    case 0:
        printf("%d |", *(int *)elem);
        break;
    case 1:
        Print_Com(*(Complex *)elem);
        break;
    default:
        break;
    }
}