#ifndef DISTANCE_H
#define DISTANCE_H

int supported_count();
char **supported_units();
float convert_units(int from_unit, int to_unit, int value);
char *unit_descriptor(int unit, int value);

#endif // DISTANCE_H
