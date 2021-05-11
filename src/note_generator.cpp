#include "bn_core.h"
#include "bn_log.h"
#include "bn_fixed.h"

#include "note_generator.h"
#include "constants.h"

namespace tta
{
    void note_generator::start()
    {
        timer_.restart();
    }

    void note_generator::update()
    {
        if (timer_.elapsed_ticks() >= (int) ticks_per_beat_)
        {
            current_beat_ += 1;
            BN_LOG("BEAT N° ", current_beat_);
            timer_.restart();
        }
    }
}