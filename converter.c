#include "menu_ui.h"
#include <stdio.h>
#include "distance_ui.h"

int processInput(int input){
    switch (input) {
    case 1:
        print_distance_menu();
        break;
    case 2:
        printf("Du valgte vægtenheder");
        break;
    case 3:
        printf("Du valgte pikstørrelser");
        break;
    case 4:
        return 0;
    default:
        break;
    }
    return 1;
}

int main()
{
    int status = 1;
    int input = -1;
    processInput(input);
    while (status > 0) {
        input = printMenu();
        status = processInput(input);
    }
    return 0;
}
