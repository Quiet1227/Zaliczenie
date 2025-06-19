#include <iostream>
#include <string.h>
#include <string>
using namespace std;

struct car {
    char brand[25];
    int prodYear;
    char plateNumber[25];
    int mileAge;
};
void createRecord(car *record, int size) {
    char brandOfUser[50];
    int prodYearOfUser;
    char plateNumberOfUser[7];
    int mileAgeOfUser;
    int con = 1;
    int i = 0;
    do {
        printf("Podaj nastepujace dane:\n");
        printf("Marka:");
        scanf("%s", &brandOfUser);
        printf("Rok:");
        scanf("%d", &prodYearOfUser);
        printf("Rejestracja:");
        scanf("%s", &plateNumberOfUser);
        printf("Przebieg:");
        scanf("%d", &mileAgeOfUser);
        if (i<size-1) {
            printf("Chcesz dodac kolejny samochod? TAK (1) / NIE (0)");
            scanf("%d", &con);
        }


        strcpy (record[i].brand, brandOfUser);
        record[i].prodYear = prodYearOfUser;
        strcpy (record[i].plateNumber, plateNumberOfUser);
        record[i].mileAge = mileAgeOfUser;
        i++;
    } while (i < size && con != 0);
}
void displayRecord(car *record, int size) {
    for (int i = 0; i < size; ++i) {
        if (record[i].brand[0] == '\0') {
            break;
        }
        printf("%d. %s, %d, %s, %d \n", i + 1, record[i].brand, record[i].prodYear, record[i].plateNumber, record[i].mileAge);
    }
}
int saveToFile(car *record, int size) {
    FILE * fptr;
    fptr = NULL;
    fptr = fopen("../saved/saved.txt", "w");
    if(fptr == 0){
        printf("Blad z plikiem zapisu");
        return 1;
    }else{
        printf("Zapisano do ../saved/saved.txt\n");
    }
    for(int i=0;i<size;i++){
        //fprintf(fptr,"\"%s\",\n%d,\n\"%s\",\n%d,\n", record[i].brand, record[i].prodYear, record[i].plateNumber, record[i].mileAge);
        fprintf(fptr,"%s,\n%d,\n%s,\n%d;\n", record[i].brand, record[i].prodYear, record[i].plateNumber, record[i].mileAge);
    }
    fclose(fptr);
    return 0;
}

int loadFromFile(car *record, int size) {
    FILE * fptr;
    fptr = NULL;
    fptr = fopen("../saved/saved.txt", "r");
    if(fptr == 0){
        printf("Blad z plikiem zapisu");
        return 1;
    }else{
        printf("Wczytano ostatni zapisany rejestr\n");
    }
    char buffer[256];
    int linia = 0;
    int selectedData = 1;
    int pasteDataToIndex = 0;
    char tempbrand[25] = "";
    char prodYearOfUsertemp[25] = "";
    char plateNumberOfUsertemp[25] = "";
    char mileAgetemp[25] = "";
    int changeLetter = 0;
    while (fgets(buffer, sizeof(buffer), fptr)) {
        linia++;
        //printf("%d. %s \n", linia, buffer);

        switch(selectedData) {
            case 1:
                //printf("%s", buffer);
                while (buffer[changeLetter] != ',') {
                    //printf("Znak: %c\n", buffer[changeLetter]);
                    tempbrand[changeLetter] = buffer[changeLetter];
                    changeLetter++;
                }
                changeLetter = 0;
                //printf("%d \n", selectedData);
                selectedData ++;
                break;
            case 2:
                //printf("%s", buffer);
                while (buffer[changeLetter] != ',') {
                    //printf("Znak: %c\n", buffer[changeLetter]);
                    prodYearOfUsertemp[changeLetter] = buffer[changeLetter];
                    changeLetter++;
                }
                changeLetter = 0;
                //printf("%d \n", selectedData);
                selectedData ++;
                break;
            case 3:
                //printf("%s", buffer);
                while (buffer[changeLetter] != ',') {
                    //printf("Znak: %c\n", buffer[changeLetter]);
                    plateNumberOfUsertemp[changeLetter] = buffer[changeLetter];
                    changeLetter++;
                }
                changeLetter = 0;
                //printf("%d \n", selectedData);
                selectedData ++;
                break;
            case 4:
                //printf("%s", buffer);
                while (buffer[changeLetter] != ';') {
                    //printf("Znak: %c\n", buffer[changeLetter]);
                    mileAgetemp[changeLetter] = buffer[changeLetter];
                    changeLetter++;
                }
                changeLetter = 0;
                //printf("%d \n", selectedData);
                selectedData ++;
                break;
            default:
                //printf("Niedozwolona operacja\n");
                printf("%d \n", selectedData);
                break;
        }
        if (selectedData > 4) {
            strcpy(record[pasteDataToIndex].brand, tempbrand);
            record[pasteDataToIndex].prodYear = atoi(prodYearOfUsertemp);
            strcpy(record[pasteDataToIndex].plateNumber, plateNumberOfUsertemp);
            record[pasteDataToIndex].mileAge = atoi(mileAgetemp);
            memset(tempbrand, 0, sizeof(tempbrand));
            memset(prodYearOfUsertemp, 0, sizeof(prodYearOfUsertemp));
            memset(plateNumberOfUsertemp, 0, sizeof(plateNumberOfUsertemp));
            memset(mileAgetemp, 0, sizeof(mileAgetemp));
            selectedData = 1;
            pasteDataToIndex++;
        }
    }
    //printf("%s, %s, %s, %s;\n", tempbrand, prodYearOfUsertemp, plateNumberOfUsertemp, mileAgetemp);


    fclose(fptr);
    return 0;
}
void createBlankRecord(car *record, int size) {
    for (int i = 0; i < size; ++i) {
        strcpy(record[i].brand, "");
        record[i].prodYear = 0;
        strcpy(record[i].plateNumber, "");
        record[i].mileAge = 0;
    }
}


int main() {
    const int size = 20;
    car record[size];
    createBlankRecord(record, size);

    int mainMenu;
    do {
        printf("Rejestr samochodow\n");
        printf("1. Stworz/Nadpisz rejestr\n");
        printf("2. Wczytaj rejestr\n");
        printf("3. Zapisz rejestr\n");
        printf("4. Wyswietl rejestr\n");
        printf("0. Wyjscie z programu\n");
        scanf("%d", &mainMenu);
        switch (mainMenu) {
            case 0:
                printf("Wyjscie z programu\n");
                break;
            case 1:
                printf("Tworzenie rejestru\n");
                int decision;
                if (strlen(record[0].brand) > 0) {
                    printf("Czy chcesz wyczyscic rejestr? Jesli nie to nadpiszesz obecny rejestr. TAK (1) / NIE (0)");
                    scanf("%d", &decision);
                    if (decision == 1) {
                        createBlankRecord(record, size);
                        createRecord(record, size);
                    }else {
                        createRecord(record, size);
                    }
                } else {
                    createRecord(record, size);
                }
                //createRecord(record, size);
                break;
            case 2:
                printf("Wczytanie rejestru\n");
                loadFromFile(record, size);
                break;
            case 3:
                printf("Zapisywanie rejestru\n");
                saveToFile(record, size);
                break;
            case 4:
                printf("Wyswietlenie rejestru\n");
                displayRecord(record, size);
                break;
            default:
                printf("Niedozwolona operacja\n");
                break;
        }
    }while (mainMenu != 0);

    return 0;
}
