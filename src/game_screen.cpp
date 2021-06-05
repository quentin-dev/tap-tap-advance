#include "bn_sprite_text_generator.h"
#include "bn_optional.h"

#include "game_screen.h"
#include "scene_types.h"

namespace tta
{
    game_screen::game_screen(bn::sprite_text_generator& text_generator)
    {
        text_generator.generate(0, 0, "GAME SCREEN", _text_sprites);
    }

    bn::optional<tta::scene_types> game_screen::update()
    {
        bn::optional<tta::scene_types> result = bn::nullopt;

        return result;
    }
}