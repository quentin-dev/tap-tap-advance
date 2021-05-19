#ifndef NOTE_GENERATOR_H
#define NOTE_GENERATOR_H

#include "bn_timer.h"
#include "bn_deque.h"
#include "bn_vector.h"

#include "constants.h"
#include "note.h"

namespace tta
{

    class note_generator
    {
        public:

            note_generator(unsigned int bpm)
            {
                beats_per_minute_ = bpm;
                ticks_per_beat_ = constants::TICKS_PER_SECOND * (60. / beats_per_minute_);

                notes_.push_back(1);
                notes_.push_back(2);
                notes_.push_back(3);
                notes_.push_back(4);
            }

            ~note_generator() = default;

            void start();
            void update();

        private:

            unsigned int beats_per_minute_;
            unsigned int ticks_per_beat_;
            unsigned int current_beat_ = 0;
            bn::timer timer_;

            bn::deque<unsigned int, 4> notes_;
            unsigned int current_note_ = 0;

            bn::vector<tta::Note, 16> lives_;

    };

}

#endif