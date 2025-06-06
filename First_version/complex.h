#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int Re;
    int Im;
}Complex;

static void Sum_Com(Complex *a, Complex *b);
static Complex Sum_Com2(const Complex *a, const Complex *b);
static void Product_Com(Complex *a, Complex *b);
static Complex Product_Com2(const Complex *a, const Complex *b);
static void Print_Com(Complex a);

static void Sum_Com(Complex *a, Complex *b){
    a->Re = a->Re + b->Re;
    a->Im = a->Im + b->Im;
}

static Complex Sum_Com2(const Complex *a, const Complex *b){
    Complex c;
    c.Re = a->Re + b->Re;
    c.Im = a->Im + b->Im;
    return c;
}

static void Product_Com(Complex *a, Complex *b){
    Complex *tmp = (Complex *)malloc(sizeof(Complex));
    memcpy(tmp, a, sizeof(Complex));
    a->Re  = tmp->Re * b->Re - tmp->Im * b->Im;
    a->Im = tmp->Re * b->Im + tmp->Im * b->Re;
    free(tmp);
}

static Complex Product_Com2(const Complex *a, const Complex *b){
    Complex c;
    c.Re = a->Re * b->Re - a->Im * b->Im;
    c.Im = a->Re * b->Im + a->Im * b->Re;
    return c;
}

static void Print_Com(Complex a){
    if(a.Im >= 0){
        printf("(%d+%di) |", a.Re, a.Im);
    }
    else {
        printf("(%d-%di) |", a.Re, -a.Im);
    }
}