#include "wavheader.h"



WavFileHeader::WavFileHeader(wav::ChannelType channelType, int sampleLength, int sampleRate)
    : header(channelType, sampleLength, sampleRate)
{}

void WavFileHeader::writeToStream(std::ofstream &stream)
{
    stream.write( (const char*)&header, sizeof(WavFileHeaderStruct) );

}

WavFileHeader::WavFileHeaderStruct::WavFileHeaderStruct(wav::ChannelType channelType, int sampleLength, int sampleRate)
    : chunkSize ( 36 + sampleLength * sizeof(short) )
    , numChannels ( channelType )
    , sampleRate ( sampleRate )
    , byteRate ( sampleRate * channelType * sizeof(short) )
    , blockAlign ( channelType * sizeof(short) )
    , bitPerSample ( 8 * sizeof(short) )
    , sampleLength ( sampleLength  * sizeof(short) )
{}
