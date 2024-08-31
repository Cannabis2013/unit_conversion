#include <stdio.h>
#include "distance_ui.h"

void handle_choice(int input){
    if(input == 1)
        print_distance_menu();
    else if(input == 2)
        printf("Du valgte vægtenheder");
    else if(input == 3)
        printf("Du valgte pikstørrelser");
}

char read_input(){
    int accepted = 0;
    char input;
    scanf(" %c",&input);
    return input;
}

int format_input(char raw){
    int code = (int) raw;
    int numeric = code - 48;
    if(numeric >= 1 && numeric <= 3)
        return numeric;
    else
        return 4;
}

void printMenu()
{
    printf("Menu:\n");
    printf("\t1 - Konverter længdeenheder\n");
    printf("\t2 - Konverter vægtenheder\n");
    printf("\t3 - Konverter pikstørrelser\n");
    printf("\t* - Slut\n");
}

int main()
{
    int selection;
    char raw = -1;
    while (1) {
        printMenu();
        raw = read_input();
        selection = format_input(raw);
        if(selection == 4)
            break;
        handle_choice(selection);
    }
    return 0;
}
