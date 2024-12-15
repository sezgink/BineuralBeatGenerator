#include "saveOperations.h"

int SaveAudio(FILE* file, double* track_l,double* track_r,int length){
    printf("Audio writing started");
    int16_t* buffer = malloc(sizeof(int16_t)*length*2);
    for (size_t i = 0; i < length; i++)
    {
        size_t j = 2*i;
        buffer[j] = track_l[i]*AMPLITUDE;
        buffer[j+1] = track_r[i]*AMPLITUDE;
        fwrite(buffer+j,sizeof(int16_t),2,file);
    }

    free(buffer);
    
    printf("Audio writing completed");
    return 0;

}