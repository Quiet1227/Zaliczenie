#include <iostream>

void printVariables(const int *ptr1, const int *ptr2){
    printf("\t*ptr1 = %d\n", *ptr1);
    printf("\t*ptr2 = %d\n", *ptr2);
}

void swap(int *ptrA, int *ptrB){
    printf("\t*ptrA = %d\n", *ptrA);
    printf("\t*ptrB = %d\n", *ptrB);
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    printf("\t*ptrA = %d\n", *ptrA);
    printf("\t*ptrB = %d\n", *ptrB);
}
int sum(int a, int b){
    int temp = a + b;
    return temp;
}

int sum(const int *prtA, const int *ptrB){
    int temp = *prtA + *ptrB;
    return temp;
}

void sum(const int *prtA, const int *ptrB, int *ptrResult){
    *ptrResult = *prtA + *ptrB;
}

void substraction(const int *prtA, const int *ptrB, int *ptrResult){
    *ptrResult = *prtA - *ptrB;
}

void multiply(const int *prtA, const int *ptrB, int *ptrResult){
    *ptrResult = *prtA * *ptrB;
}

void divide(const int *prtA, const int *ptrB, int *ptrResult){
    *ptrResult = *prtA / *ptrB;
}


int main() {
    int a = 0;
    int b = 0;
    char operation;
    printf("Podaj liczbe a\n");
    scanf("%d",&a);
    printf("Podaj liczbe b\n");
    scanf("%d",&b);
    printf("Podaj operacje +, -, /, *");
    scanf(&operation);
    int result = 0;
    if(operation == '+'){
        sum(&a, &b, &result);
    }else{
        printf("Cos nie tak");
    }
    //sum(&a, &b, &result);
    //substraction(&a, &b, &result);
    printf("%d + %d = %d\n", a, b, result);
    return 0;
}

/*
 *
void printVariables(int a, int b){
    printf("\ta = %d\n", a);
    printf("\tb = %d\n", b);
    printf("\t&a = %p\n", &a);
    printf("\t&b = %p\n", &b);
}
int main() {
    int a = 2;
    int b = 5;
    int *ptr = NULL;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);

    printf("ptr = %p\n", ptr);
    printf("&ptr = %p\n", &ptr);

    a = 10;
    printf("a = %d\n", a);
    printf("&a = %p\n", &a);

    ptr = &a;
    *ptr = 50;
    printf("a = %d\n", a);
    printf("&a = %p\n", &a);
    printf("ptr = %p\n", ptr);
    return 0;
}
int main() {
    int a = 2;
    int b = 5;
    int *ptr = NULL;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);

    printVariables(a, b);
    return 0;
}

int main() {
    int a = 2;
    int b = 5;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    //int temp = a;
    //a = b;
    //b = temp;
    swap(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printVariables(&a, &b);
    return 0;
}

 *
 */