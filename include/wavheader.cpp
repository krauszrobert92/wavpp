#include "wavheader.h"



wav::WavFileHeader::WavFileHeader(wav::ChannelType channelType, int sampleLength, int sampleRate)
    : header(channelType, sampleLength, sampleRate)
{}

void wav::WavFileHeader::writeToStream(std::ofstream &stream)
{
    stream.write( (const char*)&header, sizeof(struct WavFileHeaderStruct) );

}

wav::WavFileHeader::WavFileHeaderStruct &wav::WavFileHeader::getHeader()
{
    return header;
}

wav::WavFileHeader::WavFileHeaderStruct::WavFileHeaderStruct(wav::ChannelType channelType, int sampleLength, int sampleRate)
    : chunkSize ( 36 + sampleLength * sizeof(short) )
    , numChannels ( channelType )
    , sampleRate ( sampleRate )
    , byteRate ( sampleRate * channelType * sizeof(short) )
    , blockAlign ( channelType * sizeof(short) )
    , bitPerSample ( 8 * sizeof(short) )
    , samplesLength ( sampleLength  * sizeof(short) )
{}

void wav::WavFileHeader::WavFileHeaderStruct::setSampleLength(uint32_t samplesLength)
{
    this->samplesLength = samplesLength  * sizeof(short);
    this->chunkSize = 36 + samplesLength * sizeof(short);
}
