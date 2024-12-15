#include "waveGenerator.h"

int GenerateSineWave(double frequency,int sample_rate,float duration,double** wave_out){
    int sample_count = (int) floor(duration*sample_rate);
    double* samples = malloc(sample_count*sizeof(double));
    double angular_freq = frequency * M_PI * 2;
    for (int i = 0; i < sample_count; i++)
    {
        double t = (double)i / sample_rate;
        // samples[i] = (int16_t) sin(t * angular_freq);
        samples[i] = sin(t * angular_freq);
        
    }

    *wave_out = samples;
    
    return sample_count; 
}

int GenerateCosWave(double frequency,int sample_rate,float duration,double** wave_out){
    int sample_count = (int) floor(duration*sample_rate);
    double* samples = malloc(sample_count*sizeof(double));
    double angular_freq = frequency * M_PI * 2;
    for (int i = 0; i < sample_count; i++)
    {
        double t = (double)i / sample_rate;
        // samples[i] = (int16_t) cos(t * angular_freq);
        samples[i] = cos(t * angular_freq);
    }
    *wave_out = samples;

    return sample_count;
     
}