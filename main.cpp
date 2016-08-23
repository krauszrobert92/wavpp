#include "wav.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    const int SampleRate = 8000;
    const int SampleLength = SampleRate * 30; // 30 sec

    short sample[SampleLength];

    wav::generator::addSinSignal(wav::ChannelType::mono, sample, SampleLength, SampleRate, 1000.f, 100.f);

    wav::writer::saveMonoPcmToWavFile(sample, SampleLength, SampleRate, "test.wav");

    return 0;
}
