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
            printf("Chcesz dodac kolejny samochod? 1/0");
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
    //pozostalosc po zapisem wieloplikowym
    // time_t now = time(0);
    // tm localTime = *localtime(&now);
    // char dateAndTime[24];
    // char fileName[16] = "../saved/Saved_";
    // strftime(dateAndTime, sizeof(dateAndTime), "%Y-%m-%d_%H-%M-%S", &localTime);
    // strcat(dateAndTime, ".txt");
    // strcat(fileName, dateAndTime);
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
        fprintf(fptr,"\"%s\",\n%d,\n\"%s\",\n%d,\n", record[i].brand, record[i].prodYear, record[i].plateNumber, record[i].mileAge);

    }
    fclose(fptr);
    return 0;
}
/* do zapetlenia
void loadFromFile(car *record, int size) {
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
    char tempbrand[25] = "";
    char prodYearOfUsertemp[4] = "";
    char plateNumberOfUsertemp[7] = "";
    int mileAgeOftemp;
    int changeLetter = 0;
    while (fgets(buffer, sizeof(buffer), fptr)) {
        linia++;
        //printf("%d. %s", linia, buffer);
        switch(linia) {
            case 1:
                printf("%s test\n", buffer);
                while (buffer[changeLetter] != ',') {
                    //printf("Znak: %c\n", buffer[changeLetter]);
                    tempbrand[changeLetter] = buffer[changeLetter];
                    changeLetter++;
                }
                changeLetter = 0;
                break;
            case 2:
                while (buffer[changeLetter] != ',') {
                    //printf("Znak: %c\n", buffer[changeLetter]);
                    prodYearOfUsertemp[changeLetter] = buffer[changeLetter];
                    changeLetter++;
                }
                changeLetter = 0;
                break;
            case 3:
                printf("%s test3\n", buffer);
                break;
            case 4:
                printf("%s test4\n", buffer);
                break;
            default:
                //printf("Niedozwolona operacja\n");
                break;

        }
    }
    printf("%s sukces\n", tempbrand);
    printf("%s sukces\n", prodYearOfUsertemp);

    fclose(fptr);

}
*/

int main() {
    const int size = 20;
    //record[19] = {"Mazda", 2019, "KR 1234X", 78000};
    car record[size];
    for (int i = 0; i < size; ++i) {
         strcpy(record[i].brand, "");
         record[i].prodYear = 0;
         strcpy(record[i].plateNumber, "");
         record[i].mileAge = 0;
    }

    int mainMenu;
    do {
        printf("Rejestr samochodow\n");
        printf("1. Stworz rejestr\n");
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
                createRecord(record, size);
                break;
            case 2:
                printf("Wczytanie rejestru\n");
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