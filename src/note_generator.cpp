#include "bn_core.h"
#include "bn_log.h"
#include "bn_fixed.h"

#include "note_generator.h"
#include "note.h"
#include "note_colors.h"
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
            
            if (notes_.size() != 0 && current_beat_ == notes_.front())
            {
                // BN_LOG("SPAWNED NOTE @ ", current_beat_);
                notes_.pop_front();

                lives_.push_back(Note(note_colors::RED));
            }
            
            timer_.restart();
        }
    }
}