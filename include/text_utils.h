#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

#include "bn_sprite_ptr.h"
#include "bn_vector.h"

namespace tta
{
    class text_utils
    {
        public:

            text_utils() = default;

            static void set_sprite_vector_visibility(bool visible, bn::ivector<bn::sprite_ptr>& sprites)
            {
                for (bn::sprite_ptr& sprite: sprites)
                {
                    sprite.set_visible(visible);
                }
            }
    };
}

#endif