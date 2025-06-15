#include <stdio.h>
#include <cstdlib>
#include <cstring>
void sum(int numberOne, int numberTwo){
    int result = numberOne + numberTwo;
    printf("Wynik to %d", result);
}
void sub(int numberOne, int numberTwo){
    int result = numberOne - numberTwo;
    printf("Wynik to %d", result);
}
int main(int argc, char const *argv[]) {
    int i;
    printf("Podano %d argumentow:\n", argc);
    for (i = 0; i < argc; i++) {
        printf("Argunent #%d\t-\t%s\n", i, argv[i]);
    }

    if(!strcmp("add",argv[2])){
        //printf("yes");
        int numberOne = atoi(argv[1]);
        int numberTwo = atoi(argv[3]);
        sum(numberOne, numberTwo);
    }else{
        //printf("no");
        printf("Nie przewidziana operacja");
    }
    
    return 0;
}