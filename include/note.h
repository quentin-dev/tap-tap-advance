#ifndef NOTE_H
#define NOTE_H

#include "bn_sprite_ptr.h"
#include "bn_optional.h"

#include "bn_sprite_items_red_note.h"

#include "note_colors.h"

namespace tta
{
    class note
    {
        public:

            note(note_colors color)
            {

                switch(color)
                {
                    default: _sprite = bn::sprite_items::red_note.create_sprite(0, _y);
                }

                // sprite_ = bn::sprite_items::red_note.create_sprite(0, y_);
                _sprite.value().set_scale(0.5);
                // red_sprite.set_visible(false);

                _y += 10;
            }
                    
        private:

            bn::optional<bn::sprite_ptr> _sprite = bn::nullopt;

            static inline int _y = -30;


    };
}

#endif