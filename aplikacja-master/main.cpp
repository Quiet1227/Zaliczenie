#include <iostream>
void createTable(int *array){
    int userValue;
    for(int i=0;i<10;i++){
        printf("Podaj wartosc nr %d\n", i+1);
        scanf("%d", &userValue);
        array[i]= userValue;
    }
    for(int i=0;i<10;i++){
        printf("%d. %d \n", i, array[i]);
    }
}
void printArray(int *array){
    printf("Tablica z liczbami\n");
    for(int i=0;i<10;i++){
        printf("%d. %d \n", i, array[i]);
        printf("%p + %d = %d \n\n", array, i, *(array+i));
    }
}
void minimumValue(int *array) {
    int minimum = 0;
    for (int i=0;i<10;i++){
        if(*(array+i) < minimum){
            minimum = *(array+i);
        }
    }
    printf("Minimum to %d \n", minimum);
}
void maxValue(int *array) {
    int max = 0;
    for (int i=0;i<10;i++){
        if(*(array+i) > max){
            max = *(array+i);
        }
    }
    printf("Maksimum to %d \n", max);
}
void average(int *array) {
    int sum;
    int av;
    for(int i=0;i<10;i++){
        sum += *(array+i);
    }
    av = sum/10;
    printf("%d",av);
}
void median(int *array) {
    int tempArray[10];
    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = 0; j < 10 - i - 1; ++j) {
            if (*(array+j) > *(array+(j+1))) {
                int temp = *(array+j);
                *(tempArray+j) = *(array+(j+1));
                *(tempArray+(j+1)) = temp;
            }
        }
    }
    //for(int i=0;i<10;i++){
    //    printf("%d. %d \n", i, *(array+i));
    //}
    int med = ((*(array+4))+(*(array+5)))/2;
    printf("%d", med);
}
int saveToFile(int *array) {
    FILE * fptr;
    fptr = NULL;
    fptr = fopen("../table.txt", "w");
    if(fptr == 0){
        printf("Blad z plikiem zapisu");
        return 1;
    }else{
        printf("Zapisano");
    }
    for(int i=0;i<10;i++){
        fprintf(fptr, "%d \n", array[i]);
    }
    fclose(fptr);
    return 0;
}


int main() {
    int array[10];
    for(int i=0;i<10;i++){
        array[i]= rand() % 100;
    }
    printf("\n");
    int menuOption;

    do {
        printf("\n");
        printf("Menu \n");
        printf("1. Podaj dane do tablicy\n");
        printf("2. Wyswietl tablice\n");
        printf("3. Oblicz liczbe minimum\n");
        printf("4. Oblicz liczbe maximum\n");
        printf("5. Oblicz srednia\n");
        printf("6. Oblicz mediane\n");
        printf("7. Zapisz tablice\n");
        printf("0. Wyjdz z programu\n");
        scanf("%d",&menuOption);
        switch (menuOption) {
            case 0:
                printf("Wyjscie z programu\n");
                break;
            case 1:
                printf("Tworzenie tablicy\n");
                createTable(array);
                break;
            case 2:
                //printf("Pokazanie tablicy\n");
                printArray(array);
                break;
            case 3:
                //printf("Minimalna\n");
                minimumValue(array);
                break;
            case 4:
                //printf("Maksimum\n");
                maxValue(array);
                break;
            case 5:
                //printf("Srednia\n");
                average(array);
                break;
            case 6:
                //printf("Mediana\n");
                //median(numbers);
                median(array);
                break;
            case 7:
                saveToFile(array);
                break;
            case 8:
                FILE * fptr;
                fptr = NULL;
                fptr = fopen("../table.txt", "r");
                if(fptr == 0){
                    printf("Blad z plikiem zapisu");
                    return 1;
                }
                char fileLine[10];
                fgets(fileLine, 10, fptr);
                printf("%s", fileLine);
                fclose(fptr);
                break;
            default:
                printf("cos nie tak\n");
                break;
        }
    }while (menuOption!=0);
}