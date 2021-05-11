#ifndef NOTE_GENERATOR_H
#define NOTE_GENERATOR_H

#include "bn_timer.h"

#include "constants.h"

namespace tta
{

    class note_generator
    {
        public:

            note_generator(unsigned int bpm)
            {
                beats_per_minute_ = bpm;
                ticks_per_beat_ = constants::TICKS_PER_SECOND * (60. / beats_per_minute_);
            }

            ~note_generator() = default;

            void start();
            void update();

        private:

            unsigned int beats_per_minute_;
            unsigned int ticks_per_beat_;
            unsigned int current_beat_ = 0;
            bn::timer timer_;

    };

}

#endif