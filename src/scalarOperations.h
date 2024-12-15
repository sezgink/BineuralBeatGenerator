#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define M_PI 3.14159265358979311599796346854 //PI in double precision

void scale_values(double* track,double multiplier,int from,int to);

void add_to_track(double* destination,double* source,int destination_from,int source_from,int length);