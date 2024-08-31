#include <stdio.h>

int i = 0;

void printEntry(char *c){
    printf("\t%d - %s\n",i++,c);
}

int readInput(){
    int accepted = 0;
    int input = -1;
    while(scanf("%d",&input)){
        if(input >= 1 && input <= 4)
            break;
        else
            printf("Wrong input\n");
    }
    return input;
}

int printMenu()
{
    i = 1;
    printf("Menu:\n");
    printEntry("Konverter længdeenheder");
    printEntry("Konverter vægtenheder");
    printEntry("Konverter pikstørrelser");
    printEntry("Slut");
    int input = readInput();
    return input;
}
