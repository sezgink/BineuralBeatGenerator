#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "waveGenerator.h"
#include "noiseGenerator.h"
#include "scalarOperations.h"
#include "saveOperations.h"

#define SAMPLE_RATE 44100 // CD-quality sample rate
#define NUM_CHANNELS 2    // Stereo audio
#define BITS_PER_SAMPLE 16 // 16-bit PCM
#define DURATION 5         // Duration of the sound in seconds
#define AMPLITUDE 32760    // Max amplitude for 16-bit audio
#define FREQ 440.0         // Frequency of the sound (A4 = 440 Hz)
#define M_PI 3.14159265358979311599796346854 //PI in double precision

// Structure for the WAV header
typedef struct WAVHeader {
    char riff[4];             // "RIFF"
    uint32_t chunkSize;       // 4 + (8 + subChunk1Size) + (8 + subChunk2Size)
    char wave[4];             // "WAVE"
    char fmt[4];              // "fmt "
    uint32_t subChunk1Size;   // 16 for PCM
    uint16_t audioFormat;     // PCM = 1
    uint16_t numChannels;     // Mono = 1, Stereo = 2
    uint32_t sampleRate;      // 44100, 48000, etc.
    uint32_t byteRate;        // sampleRate * numChannels * bitsPerSample / 8
    uint16_t blockAlign;      // numChannels * bitsPerSample / 8
    uint16_t bitsPerSample;   // 8, 16, 24, 32 bits per sample
    char data[4];             // "data"
    uint32_t subChunk2Size;   // numSamples * numChannels * bitsPerSample / 8
} WAVHeader;

// Function to write a WAV header
void write_wav_header(FILE *file, int numSamples) {
    WAVHeader header;

    // Write "RIFF" chunk descriptor
    header.riff[0] = 'R';
    header.riff[1] = 'I';
    header.riff[2] = 'F';
    header.riff[3] = 'F';

    header.chunkSize = 36 + numSamples * NUM_CHANNELS * (BITS_PER_SAMPLE / 8);
    header.wave[0] = 'W';
    header.wave[1] = 'A';
    header.wave[2] = 'V';
    header.wave[3] = 'E';

    // Write "fmt " sub-chunk
    header.fmt[0] = 'f';
    header.fmt[1] = 'm';
    header.fmt[2] = 't';
    header.fmt[3] = ' ';
    header.subChunk1Size = 16;  // PCM format subchunk size
    header.audioFormat = 1;     // PCM format (not compressed)
    header.numChannels = NUM_CHANNELS;
    header.sampleRate = SAMPLE_RATE;
    header.byteRate = SAMPLE_RATE * NUM_CHANNELS * (BITS_PER_SAMPLE / 8);
    header.blockAlign = NUM_CHANNELS * (BITS_PER_SAMPLE / 8);
    header.bitsPerSample = BITS_PER_SAMPLE;

    // Write "data" sub-chunk
    header.data[0] = 'd';
    header.data[1] = 'a';
    header.data[2] = 't';
    header.data[3] = 'a';
    header.subChunk2Size = numSamples * NUM_CHANNELS * (BITS_PER_SAMPLE / 8);

    fwrite(&header, sizeof(WAVHeader), 1, file);
}

//Arguments function[generate,help] duration(minutes) frequency1 frequency2 noiseType[0 None,1 White,2 Pink] 
int main(int argc, char *argv[]) {
    if(argc<2){
        printf("Arguments not defined, use 'help' argument to see patterns");
        printf("Arguments \"function[generate,help] duration(in minutes) frequency1 frequency2 noiseType[0 None,1 White,2 Pink] \"");
        return -1;
    }

    if(argc<5){
        printf("Use 2 frequency to get bineural beat.");
    }

    double freq_l = atof (argv[3]);
    double freq_r = atof (argv[4]);
    float duration = atof(argv[2])*60;

    double* track_l = NULL;
    double* track_r = NULL;
    int track_length = 0;
    int track_length_l = GenerateSineWave(freq_l,SAMPLE_RATE,duration,&track_l);
    int track_length_r = GenerateSineWave(freq_r,SAMPLE_RATE,duration,&track_r);
    track_length += track_length_l;

    FILE *file = fopen("output2.wav", "wb");
    if (!file) {
        fprintf(stderr, "Failed to create output.wav file\n");
        return 1;
    }

    // int numSamples = SAMPLE_RATE * DURATION;
    int numSamples = track_length;
    printf("Num samples %d per track",numSamples);

    // Write the WAV file header
    write_wav_header(file, numSamples);
    SaveAudio(file,track_l,track_r,track_length);

    fclose(file);
    printf("WAV file created successfully: output.wav\n");
    return 0;
}
