#include "distance.h"

#ifdef USE_METRIC_CALC
#define UK_MILE_M_UNIT 1600 // 1 mile ~= 1600 meters
#define UK_FOOT_M_UNIT 0.3048 // 1 foot ~= 0.3048 meters
#define UK_YARD_M_UNIT 0.9144 // 1 yard ~= 0.9144 meters

#define MILE_DESCRIPTOR 1
#define FOOT_DESCRIPTOR 2
#define YARD_DESCRIPTOR 3
#define METER_DESCRIPTOR 4

float to_meters(int from_unit, float value){
    switch (from_unit) {
    case 1:
        return value * UK_MILE_M_UNIT;
    case 2:
        return value * UK_FOOT_M_UNIT;
    case 3:
        return value * UK_YARD_M_UNIT;
    default:
        return value;
    }
}

float from_meters(int to_unit, float value){
    float result;
    switch (to_unit) {
    case 1:
        result = value / UK_MILE_M_UNIT;
        break;
    case 2:
        result = value / UK_FOOT_M_UNIT;
        break;
    case 3:
        result =value / UK_YARD_M_UNIT;
        break;
    default:
        result = value;
        break;
    }
    return result;
}

float convert_units(int from_unit, int to_unit, int value) {
    float meters = to_meters(from_unit,value);
    return from_meters(to_unit,meters);
}

char *unit_descriptor(int unit, int value) {
    char *descriptor;
    if(unit == MILE_DESCRIPTOR)
        descriptor = value > 0 ? "miles" : "mile";
    else if(unit == FOOT_DESCRIPTOR)
        descriptor = value > 0 ? "feet" : "foot";
    else if(unit == YARD_DESCRIPTOR)
        descriptor = value > 0 ? "yards" : "yard";
    else if(unit == METER_DESCRIPTOR)
        descriptor = value > 0 ? "meters" : "meter";
    else
        descriptor = "noses";
    return descriptor;
}
#endif
