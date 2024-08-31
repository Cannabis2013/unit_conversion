#include "distance_ui.h"
#ifdef USE_SIMPLE_FORMATTING

#include <stdio.h>
#include "distance.h"

void print_welcome_text(){
    printf("Distance conversions\n");
}

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
        input = (int) g;
        if(input >= 49 && input <= 52)
            return input - 48;
        else
            printf("Please select a number that is between 0 and 5\n");
    }
    input = (int) g;
    return input - 48;
}

float read_value(){
    float input = -1;
    scanf("%f",&input);
    return input;
}

int wait_for_status(){
    char input;
    while (scanf(" %c",&input)) {
        if(input == 'X' || input == 'x')
            return 0;
        else
            return 1;
    }
    return 1;
}

void print_distance_menu() {
    int status = 1;
    print_welcome_text();
    float result;
    char *descriptor;
    int from_unit = -1, to_unit = -1, value = -1;
    while (status) {
        printf("Select source unit:\n");
        print_unit_options();
        from_unit = read_unit();
        printf("Select destination unit:\n");
        print_unit_options();
        to_unit = read_unit();
        printf("Select value: ");
        value = read_value();
        result = convert_units(from_unit,to_unit,value);
        descriptor = unit_descriptor(to_unit,result);
        printf("Your result is: %f %s\n\n",result,descriptor);
        printf("Proceed? (*,Xx)");
        status = wait_for_status();
    }
}

#endif
