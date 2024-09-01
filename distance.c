#include "distance.h"
#include <stdlib.h>

#ifdef USE_METRIC_CALC

#define SUPPORTED_COUNT 6

#define UK_MILE_M_UNIT 1600 // 1 mile ~= 1600 meters
#define UK_FOOT_M_UNIT 0.3048 // 1 foot ~= 0.3048 meters
#define UK_YARD_M_UNIT 0.9144 // 1 yard ~= 0.9144 meters
#define DK_ALEN_M_UNIT 0.6277 // 1 alen ~= 0.6277 meter
#define DK_TOM_M_UNIT 0.0254 // 1 tomme ~= 0.0254 meter

#define MILE_DESCRIPTOR 1
#define FOOT_DESCRIPTOR 2
#define YARD_DESCRIPTOR 3
#define METER_DESCRIPTOR 4
#define ALEN_DESCRIPTOR 5
#define TOM_DESCRIPTOR 6

float to_meters(int from_unit, float value){
    if(from_unit == 1)
        return value * UK_MILE_M_UNIT;
    else if(from_unit == 2)
        return value * UK_FOOT_M_UNIT;
    else if(from_unit == 3)
        return value * UK_YARD_M_UNIT;
    else if(from_unit == 4)
        return value;
    else if(from_unit == 5)
        return value * DK_ALEN_M_UNIT;
    else if(from_unit == 6)
        return value * DK_TOM_M_UNIT;
    else
        return value;
}

float from_meters(int to_unit, float value){
    float result;
    if(to_unit == 1)
        return value / UK_MILE_M_UNIT;
    else if(to_unit == 2)
        return value / UK_FOOT_M_UNIT;
    else if(to_unit == 3)
        return value / UK_YARD_M_UNIT;
    else if(to_unit == 4)
        return value;
    else if(to_unit == 5)
        return value / DK_ALEN_M_UNIT;
    else if(to_unit == 6)
        return value / DK_TOM_M_UNIT;
    else
        return value;
}

float convert_units(int from_unit, int to_unit, int value) {
    float meters = to_meters(from_unit,value);
    return from_meters(to_unit,meters);
}

char *unit_descriptor(int unit, int value) {
    if(unit == MILE_DESCRIPTOR)
        return "mil";
    else if(unit == FOOT_DESCRIPTOR)
        return "fod";
    else if(unit == YARD_DESCRIPTOR)
        return "yard";
    else if(unit == METER_DESCRIPTOR)
        return "meter";
    else if(unit == ALEN_DESCRIPTOR)
        return "alen";
    else if(unit == TOM_DESCRIPTOR)
        return value > 0 ? "tommer" : "tomme";
    else
        return "næser";
}

char **supported_units() {
    char **units = (char **) malloc(SUPPORTED_COUNT*sizeof(char*));
    units[0] = "Mil";
    units[1] = "Fod";
    units[2] = "Yard";
    units[3] = "Meter";
    units[4] = "Alen";
    units[5] = "Tomme";
    return units;
}

int supported_count() {
    return SUPPORTED_COUNT;
}
#endif
