#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define AMPLITUDE 32760    // Max amplitude for 16-bit audio


int SaveAudio(FILE* file, double* track_l,double* track_r,int length);