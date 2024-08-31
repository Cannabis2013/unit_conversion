#include "distance_ui.h"
#ifdef USE_SIMPLE_FORMATTING

#include <stdio.h>
#include "distance.h"

void print_unit_options(){
    printf("Miles(1) ");
    printf("Foot(2) ");
    printf("Yard(3) ");
    printf("Meters(4) ");
}

int read_unit(){
    char g = '4';
    int input;
    while (scanf(" %c",&g)) {
        input = (int) g - 48;
        if(input >= 1 && input <= 4)
            return input;
        else
            printf("Vælg et tal mellem 0 og 5!\n");
    }
    input = (int) g;
    return input - 48;
}

float read_value(){
    float input = -1;
    scanf("%f",&input);
    return input;
}

int wait_for_input(){
    char input;
    while (scanf(" %c",&input)) {
        if(input == 'X' || input == 'x')
            return 0;
        else
            return 1;
    }
    return 1;
}

int get_unit(char *msg){
    printf("Hvilken enhed vil du konvertere fra?\n");
    print_unit_options();
    return read_unit();
}

void print_distance_menu() {
    int status = 1;
    printf("Længde omregner\n");
    float result;
    char *descriptor;
    int from_unit = -1, to_unit = -1, value = -1;
    while (status) {
        from_unit = get_unit("Hvilken enhed vil du konvertere fra?\n");
        to_unit = get_unit("Hvilken enhed vil du konvertere til?\n");
        printf("Indtast værdi: ");
        value = read_value();
        result = convert_units(from_unit,to_unit,value);
        descriptor = unit_descriptor(to_unit,result);
        printf("Dit resultat: %f %s\n\n",result,descriptor);
        printf("Fortsæt? (*,Xx)");
        status = wait_for_input();
    }
}

#endif
