#include "distance_ui.h"
#ifdef USE_SIMPLE_FORMATTING

#include <stdio.h>
#include "distance.h"

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
        if(input >= 1 && input <= supportedCount)
            return input;
        else
            printf("Vælg et tal mellem 0 og %d!\n",supportedCount + 1);
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
    printf("%s",msg);
    print_unit_options();
    return read_unit();
}

float get_value(){
    printf("Indtast værdi: ");
    return read_value();
}

void print_result(int from_unit, int to_unit,float value){
    float result = convert_units(from_unit,to_unit,value);
    char *descriptor = unit_descriptor(to_unit,result);
    printf("Dit resultat: %f %s\n\n",result,descriptor);
    printf("Fortsæt? (*,Xx)");
}

void print_distance_menu() {
    int status = 1;
    printf("Længde omregner\n");
    int from_unit = -1, to_unit = -1, value = -1;
    while (status) {
        from_unit = get_unit("Hvilken enhed vil du konvertere fra?\n");
        to_unit = get_unit("Hvilken enhed vil du konvertere til?\n");
        value = get_value();
        print_result(from_unit,to_unit,value);
        status = wait_for_input();
    }
}

#endif
