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
        _timer.restart();
    }

    void note_generator::update()
    {
        if (_timer.elapsed_ticks() >= (int) _ticks_per_beat)
        {
            _current_beat += 1;
            BN_LOG("BEAT N° ", _current_beat);
            
            if (_notes.size() != 0 && _current_beat == _notes.front())
            {
                // BN_LOG("SPAWNED NOTE @ ", current_beat_);
                _notes.pop_front();

                _lives.push_back(note(note_colors::RED));
            }
            
            _timer.restart();
        }
    }
}