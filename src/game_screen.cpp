#include "bn_sprite_text_generator.h"
#include "bn_keypad.h"
#include "bn_optional.h"
#include "bn_log.h"

#include "game_screen.h"
#include "scene_types.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_play_bg.h"

namespace tta
{
    game_screen::game_screen(bn::sprite_text_generator& text_generator)
    {
        _started = false;
        text_generator.generate(0, 0, "Press Start", _text_sprites);

        _bg = bn::regular_bg_items::play_bg.create_bg(0, 0);
        _bg.value().set_visible(true);
    }

    bn::optional<tta::scene_types> game_screen::update()
    {
        bn::optional<tta::scene_types> result = bn::nullopt;

        if (!_started && bn::keypad::start_pressed())
        {
            _note_generator.start();
            _started = true;
        }

        if (_started)
        {
            _note_generator.update();
        }

        return result;
    }
}