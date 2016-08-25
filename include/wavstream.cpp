#include "wavstream.h"

#include "wavgenerator.h"

wav::WavStream::WavStream(const std::string &filepath, wav::SampleRate sampleRate, wav::ChannelType channelType)
    : filepath ( filepath )
    , sampleRate ( sampleRate )
    , channelType ( channelType )
    , header ( channelType, 0, sampleRate )
    , ostream ( filepath, std::ios::binary )
    , writedSamplesCount ( 0 )
{
    if ( ostream.is_open() )
    {
        header.writeToStream(ostream);
    }
}

wav::WavStream::~WavStream()
{
    close();
}

bool wav::WavStream::isOpen()
{
    return ostream.is_open();
}

void wav::WavStream::write(const short *samples, uint32_t samplesLength)
{
    ostream.write((const char*)samples, samplesLength * sizeof (short) );

    writedSamplesCount += samplesLength;
}

void wav::WavStream::write(const short *leftSamples, const short *rightSamples, uint32_t samplesLength)
{
    std::vector<short> data = wav::generator::mixChannels(leftSamples, rightSamples, samplesLength);

    write(data.data(), data.size());
}

void wav::WavStream::close()
{
    if ( ostream.is_open() )
    {
        ostream.seekp(0, std::ios::beg);

        header.getHeader().setSampleLength( writedSamplesCount );
        header.writeToStream( ostream );

        ostream.close();
    }
}
