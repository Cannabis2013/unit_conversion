#include "distance_ui.h"
#include <stdio.h>
#include "distance.h"

#define CSI_CLEAR_SCREEN "\033[H\033[J"

void print_intro_screen(){
    printf(CSI_CLEAR_SCREEN);
    printf("Længde omregner\n\n"
           "Indtast x eller X for at gå til hovedmenu\n"
           "Indtast q eller Q for at afslutte programmet\n\n"
           ""
           "");
}

void print_unit_options(){
    int count = supported_count();
    char **units = supported_units();
    for (int i = 0; i < count; ++i) {
        char *unit = units[i];
        printf("%s(%d) ",unit,i + 1);
    }
}

int read_unit(){
    char g = '4';
    int input;
    int supportedCount = supported_count();
    while (scanf(" %c",&g)) {
        input = (int) g - 48;
        if(g == 'x' || g == 'X')
            return 0;
        else if(g == 'q' || g == 'Q')
            return -1;
        else if(input >= 1 && input <= supportedCount)
            return input;
        else
            printf("Vælg et tal mellem 0 og %d!\n",supportedCount + 1);
    }
    input = (int) g;
    return input - 48;
}

int wait_for_input(){
    char input;
    while (scanf(" %c",&input)) {
        if(input == 'X' || input == 'x')
            return 0;
        else if(input == 'q' || input == 'Q')
            return -1;
        else
            return 1;
    }
    return 1;
}

int get_unit(char *msg){
    printf("%s",msg);
    print_unit_options();
    return read_unit();
}

float get_value(){
    printf("Indtast værdi: ");
    float input = -1;
    int result = scanf("%f",&input);
    return result ? input : 0;
}

void print_result(int from_unit, int to_unit,float value){
    float result = convert_units(from_unit,to_unit,value);
    char *descriptor = unit_descriptor(to_unit,result);
    printf("Dit resultat: %f %s\n\n",result,descriptor);
    printf("Fortsæt? (*,Xx)");
}

int distance_main() {
    int status = 1;
    print_intro_screen();
    int from_unit = -1, to_unit = -1, value = -1;
    while (status) {
        from_unit = get_unit("Hvilken enhed vil du konvertere fra?\n");
        if(from_unit <= 0)
            return from_unit;
        to_unit = get_unit("Hvilken enhed vil du konvertere til?\n");
        if(to_unit <= 0)
            return to_unit;
        value = get_value();
        if(value <= 0)
            return value;;
        print_result(from_unit,to_unit,value);
        status = wait_for_input();
        print_intro_screen();
    }
    return status;
}
