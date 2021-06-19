#include "bn_core.h"
#include "bn_log.h"
#include "bn_fixed.h"
#include "bn_keypad.h"

#include "note_generator.h"
#include "note.h"
#include "note_colors.h"
#include "note_utils.h"
#include "constants.h"

namespace tta
{
    void note_generator::start()
    {
        _timer.restart();
        BN_LOG("[note_generator] Started");
    }

    void note_generator::update()
    {

        auto before_it = _lives.before_begin();
        auto it = _lives.begin();
        auto end = _lives.end();

        while(it != end)
        {

            if (it->is_pressed())
            {
                continue;
            }
            
            bn::fixed_point pos = it->update();
            BN_LOG("Y POS: ", pos.y());
            if (tta::note_utils::can_be_played(pos) && bn::keypad::a_pressed())
            {
                it->set_pressed();
                BN_LOG("NOTE WAS PRESSED");
                it = _lives.erase_after(before_it);
            }
            else
            {
                before_it = it;
                ++it;
            }
        }

        if (_timer.elapsed_ticks() >= (int) _ticks_per_beat)
        {
            _current_beat += 1;
            BN_LOG("[note_generator] Beat n°", _current_beat);
            
            if (_notes.size() != 0 && _current_beat == _notes.front())
            {
                BN_LOG("[note_generator] Spawned note @ beat n°", _current_beat);
                _notes.pop_front();

                _lives.emplace_front(note_colors::RED);
            }
            
            _timer.restart();
        }
    }
}