# wavpp c++
C++ source code for write wav files. Save streamed pcm samples.

Example code:

```
#include "wavgenerator.h"
#include "wavwriter.h"
#include "wavstream.h"

#include <string>

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

void monoStreamTest(wav::SampleRate sampleRate, const std::string &filePath)
{
    std::vector<short> samples (sampleRate * 30);

    wav::generator::addSinSignal(wav::ChannelType::mono, samples, sampleRate, 10000.f, 1000.f);

    wav::WavStream stream(filePath, sampleRate, wav::ChannelType::mono);

    const uint32_t CHUNK_SIZE = 160;

    for ( uint32_t c = 0; c < samples.size(); c += CHUNK_SIZE )
    {
        stream.write(&samples[c], CHUNK_SIZE);
    }

    stream.close();
}

void stereoStreamTest(wav::SampleRate sampleRate, const std::string &filePath)
{
    std::vector<short> leftSamples (sampleRate * 30);
    std::vector<short> rightSamples (sampleRate * 30);

    wav::generator::addSinSignal(wav::ChannelType::mono, leftSamples, sampleRate, 10000.f, 1000.f);
    wav::generator::addSinSignal(wav::ChannelType::mono, rightSamples, sampleRate, 10000.f, 1000.f);

    wav::WavStream stream(filePath, sampleRate, wav::ChannelType::stereo);

    const uint32_t CHUNK_SIZE = 160;

    for ( uint32_t c = 0; c < leftSamples.size(); c += CHUNK_SIZE )
    {
        stream.write(&leftSamples[c], &rightSamples[c], CHUNK_SIZE);
    }

    stream.close();
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


    monoStreamTest(wav::sampleRate_8000, "mono_stream_8000.wav");
    monoStreamTest(wav::sampleRate_48000, "mono_stream_48000.wav");

    
    stereoStreamTest(wav::sampleRate_8000, "stereo_stream_8000.wav");

    return 0;
}
```
