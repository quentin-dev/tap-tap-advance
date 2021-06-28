#ifndef NOTE_H
#define NOTE_H

#include "bn_sprite_ptr.h"
#include "bn_optional.h"
#include "bn_sprite_actions.h"

#include "bn_sprite_items_red_note.h"

#include "note_colors.h"
#include "note_utils.h"
#include "constants.h"

namespace tta
{
    class note
    {
        public:

            note(tta::note_colors color) :
                _sprite(tta::note_utils::get_sprite_from_color(color, 0, _y)),
                _move_action(_sprite, 0, tta::constants::NOTE_Y_SPEED)

            {
                _sprite.set_scale(0.5);
                _y += 10;
            }

            bn::fixed_point update()
            {
                if (!_pressed)
                {
                    _move_action.update();
                }
                
                return _move_action.sprite().position();
            }

            void set_pressed()
            {
                _pressed = true;
                _sprite.set_visible(false);
            }

            bool is_pressed()
            {
                return _pressed;
            }

            
                    
        private:

            bn::sprite_ptr _sprite;
            bn::sprite_move_by_action _move_action;
            bool _pressed = false;

            static inline int _y = -30;


    };
}

#endif