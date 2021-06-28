#ifndef NOTE_GENERATOR_H
#define NOTE_GENERATOR_H

#include "bn_timer.h"
#include "bn_deque.h"
#include "bn_log.h"
#include "bn_vector.h"
#include "bn_forward_list.h"

#include "constants.h"
#include "note.h"

namespace tta
{

    class note_generator
    {
        public:

            note_generator(unsigned int bpm = 70)
            {
                _beats_per_minute = bpm;

                BN_LOG("[note_generator] BPM set to ", _beats_per_minute);

                _ticks_per_beat = constants::TICKS_PER_SECOND * (60. / _beats_per_minute);

                BN_LOG("[note_generator] Ticks / beat set to ", _ticks_per_beat);

                _notes.push_back(1);
                _notes.push_back(6);
            }

            ~note_generator() = default;

            void start();
            int update();

        private:

            unsigned int _beats_per_minute;
            unsigned int _ticks_per_beat;
            unsigned int _current_beat = 0;
            bn::timer _timer;

            bn::deque<unsigned int, 8> _notes;
            unsigned int _current_note = 0;

            bn::forward_list<tta::note, 16> _lives;
    };

}

#endif