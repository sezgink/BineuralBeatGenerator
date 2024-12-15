#include "scalarOperations.h"

void scale_values(double* track,double multiplier,int from,int to){
    int i;
    for ( i = from; i <= to; i++)
    {
        track[i] *= multiplier;
    }
}

void add_to_track(double* destination,double* source,int destination_from,int source_from,int length){
    int i;
    for ( i = 0; i < length; i++)
    {
        destination[destination_from+i] += source[source_from+i];
    }
}
