#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define M_PI 3.14159265358979311599796346854 //PI in double precision

int GenerateSineWave(double frequency,int sample_rate,float duration,double** wave_out);
int GenerateCosWave(double frequency,int sample_rate,float duration,double** wave_out);