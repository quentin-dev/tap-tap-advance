#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "bn_sprite_text_generator.h"
#include "bn_sprite_ptr.h"
#include "bn_optional.h"
#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"

#include "note_generator.h"
#include "scene.h"
#include "scene_types.h"

namespace tta
{
    class game_screen: public tta::scene
    {
        public:

            game_screen(bn::sprite_text_generator& text_generator);
            ~game_screen() = default;

            bn::optional<tta::scene_types> update() override final;

        private:

            bn::optional<bn::regular_bg_ptr> _bg;
            bn::vector<bn::sprite_ptr, 32> _text_sprites;
            tta::note_generator _note_generator;
            bool _started;

    };
}

#endif