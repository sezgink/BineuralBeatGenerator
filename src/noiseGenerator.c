#include "noiseGenerator.h"

void GenerateWhiteNoise(int sample_rate, float duration, double** wave_out) {
    int sample_count = (int) floor(duration * sample_rate);
    double* samples = malloc(sample_count*sizeof(double));
    for (int i = 0; i < sample_count; i++) {
        samples[i] = ((double) rand() / (double) RAND_MAX) * 2.0 - 1.0; // Random double in [-1, 1]
    }
    *wave_out = samples;
    return sample_count;
}

void GeneratePinkNoise(int sample_rate, float duration, double** wave_out) {
    int sample_count = (int) floor(duration * sample_rate);
    double* samples = malloc(sample_count*sizeof(double));


    double b0 = 0.0, b1 = 0.0, b2 = 0.0, b3 = 0.0, b4 = 0.0, b5 = 0.0, b6 = 0.0;
    
    for (int i = 0; i < sample_count; i++) {
        double white = ((double) rand() / (double) RAND_MAX) * 2.0 - 1.0; // Random double in [-1, 1]
        b0 = 0.99886 * b0 + white * 0.0555179;
        b1 = 0.99332 * b1 + white * 0.0750759;
        b2 = 0.96900 * b2 + white * 0.1538520;
        b3 = 0.86650 * b3 + white * 0.3104856;
        b4 = 0.55000 * b4 + white * 0.5329522;
        b5 = -0.7616 * b5 - white * 0.0168980;
        double pink = b0 + b1 + b2 + b3 + b4 + b5 + b6 + white * 0.5362;
        b6 = white * 0.115926;
        
        pink *= 0.11; // Scale to avoid overflow
        samples[i] = pink; // Store as double
    }

    *wave_out = samples;
}