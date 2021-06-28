#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "bn_sprite_text_generator.h"
#include "bn_sprite_ptr.h"

namespace tta
{
    class scoreboard
    {
        public:

            scoreboard(bn::sprite_text_generator& text_generator);

            void set_visible(bool visible);
            void update(int score);

        private:

            bn::sprite_text_generator& _text_generator;
            bn::vector<bn::sprite_ptr, 12> _score_text_sprites;
            int _score = 0;
    };
}

#endif