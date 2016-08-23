#ifndef WAV_H
#define WAV_H

namespace wav {

enum ChannelType : short {
    mono = 1,
    stereo = 2
};

}

#include "wavwriter.h"
#include "wavgenerator.h"

#endif // WAV_H
