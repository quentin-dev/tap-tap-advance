#include "bn_sprite_text_generator.h"
#include "bn_optional.h"
#include "bn_keypad.h"

#include "title_screen.h"
#include "scene_types.h"

namespace tta
{

    title_screen::title_screen(bn::sprite_text_generator& text_generator)
    {
        text_generator.generate(0, 0, "TAP TAP ADVANCE", _text_sprites);
        text_generator.generate(0, 32, "Press Start", _text_sprites);
    }

    bn::optional<tta::scene_types> title_screen::update()
    {
        bn::optional<tta::scene_types> result = bn::nullopt;

        if (bn::keypad::start_pressed())
        {
            result = tta::scene_types::GAME;
        }

        return result;
    }
}