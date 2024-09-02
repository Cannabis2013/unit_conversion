#include <stdio.h>
#include "distance_ui.h"

#define CSI_CLEAR_SCREEN "\033[H;\033[2J"

void handle_choice(int input){
    if(input == 1)
        distance_main();
    else if(input == 2)
        printf("Du valgte vægtenheder\n");
    else if(input == 3)
        printf("Du valgte Næsestørrelser\n");
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
    else if(raw == 'X' || raw == 'x')
        return 4;
    else
        return -1;
}

void printMenu()
{
    printf(CSI_CLEAR_SCREEN);
    printf("Menu:\033[0m\n");
    printf("\t1 \t- Konverter længdeenheder\n");
    printf("\t2 \t- Konverter vægtenheder\n");
    printf("\t3 \t- Konverter pikstørrelser\n");
    printf("\tx \t- Slut\n");
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
        else if(selection != -1)
            handle_choice(selection);
    }
    return 0;
}
