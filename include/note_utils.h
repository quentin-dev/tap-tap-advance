#ifndef NOTE_UTILS_H
#define NOTE_UTILS_H

#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"

#include "bn_sprite_items_red_note.h"

#include "note_colors.h"

namespace tta
{
    class note_utils
    {

        public:

            note_utils() = default;

            static bn::sprite_ptr get_sprite_from_color(tta::note_colors color, bn::fixed x, bn::fixed y)
            {
                switch(color)
                {
                    default:
                        return bn::sprite_items::red_note.create_sprite(x, y);
                }
            }

            static bool can_be_played(bn::fixed_point position)
            {
                return position.y() >= 90;
            }

        private:

    };
}

#endif