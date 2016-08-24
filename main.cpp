#include "wav.h"

#include <iostream>

using namespace std;


void monoTest(wav::SampleRate sampleRate, const std::string &filePath)
{
    wav::Wav wav(wav::ChannelType::mono, sampleRate, sampleRate * 30);

    wav::generator::addSinSignal(wav, 10000.f, 1000.f);

    wav::writer::saveMonoPcmToWavFile(wav, filePath);
}


int main(int argc, char *argv[])
{
    monoTest(wav::sampleRate_8000, "mono_8000.wav");
    monoTest(wav::sampleRate_11025, "mono_11025.wav");
    monoTest(wav::sampleRate_22050, "mono_22050.wav");
    //monoTest(wav::sampleRate_44100, "mono_44100.wav"); // not playable?


    return 0;
}
