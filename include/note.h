#ifndef NOTE_H
#define NOTE_H

#include "bn_sprite_ptr.h"
#include "bn_optional.h"

#include "bn_sprite_items_red_note.h"

#include "note_colors.h"

namespace tta
{
    class Note
    {
        public:

            Note(note_colors color)
            {

                switch(color)
                {
                    default: sprite_ = bn::sprite_items::red_note.create_sprite(0, y_);
                }

                // sprite_ = bn::sprite_items::red_note.create_sprite(0, y_);
                sprite_.value().set_scale(0.5);
                // red_sprite.set_visible(false);

                y_ += 10;
            }
                    
        private:

            bn::optional<bn::sprite_ptr> sprite_ = bn::nullopt;

            static inline int y_ = -30;


    };
}

#endif