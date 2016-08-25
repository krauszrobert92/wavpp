#include "wav.h"

#include <iostream>

using namespace std;


void monoTest(wav::SampleRate sampleRate, const std::string &filePath)
{
    wav::Wav wav(wav::ChannelType::mono, sampleRate, sampleRate * 30);

    wav::generator::addSinSignal(wav, 10000.f, 1000.f);

    wav::writer::writeToFile(wav, filePath);
}

void stereoTest(wav::SampleRate sampleRate, const std::string &filePath)
{
    wav::Wav wav(wav::ChannelType::stereo, sampleRate, sampleRate * 30);

    wav::generator::addSinSignal(wav, 10000.f, 1000.f);

    wav::writer::writeToFile(wav, filePath);
}


int main(int , char *[])
{
    monoTest(wav::sampleRate_8000, "mono_8000.wav");
    monoTest(wav::sampleRate_11025, "mono_11025.wav");
    monoTest(wav::sampleRate_22050, "mono_22050.wav");
    monoTest(wav::sampleRate_44100, "mono_44100.wav");
    monoTest(wav::sampleRate_48000, "mono_48000.wav");

    stereoTest(wav::sampleRate_8000, "stereo_8000.wav");
    stereoTest(wav::sampleRate_11025, "stereo_11025.wav");
    stereoTest(wav::sampleRate_22050, "stereo_22050.wav");
    stereoTest(wav::sampleRate_44100, "stereo_44100.wav");
    stereoTest(wav::sampleRate_48000, "stereo_48000.wav");

    return 0;
}
