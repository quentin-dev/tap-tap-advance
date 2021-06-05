#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_memory.h"
#include "bn_timer.h"
#include "bn_log.h"
#include "bn_optional.h"
#include "bn_assert.h"
#include "bn_vector.h"

#include "gj_big_sprite_font.h"
#include "note_generator.h"
#include "scene.h"
#include "title_screen.h"
#include "game_screen.h"

#include "bn_sprite_items_red_note.h"
#include "bn_music_items.h"

int main()
{
    bn::core::init();

    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    bn::sprite_text_generator text_generator(gj::big_sprite_font);
    text_generator.set_bg_priority(1);
    text_generator.set_center_alignment();

    bn::vector<bn::sprite_ptr, 32> text_sprites;

    // bn::sprite_ptr red_sprite = bn::sprite_items::red_note.create_sprite(0, 0);
    // red_sprite.set_scale(0.5);
    // red_sprite.set_visible(false);

    // text_generator.generate(0, 0, "Hello, World!", text_sprites);

    // tta::note_generator note_generator(70);

    // bn::music_items::onetwenty.play(0.5);

    // note_generator.start();

    bn::unique_ptr<tta::scene> scene(new tta::title_screen(text_generator));

    bn::optional<tta::scene_types> next_scene = bn::nullopt;

    while(true)
    {
        bn::core::update();
        // note_generator.update();
        if (scene)
        {
            next_scene = scene->update();
        }

        if (next_scene.has_value())
        {
            switch(next_scene.value())
            {
                case tta::scene_types::INTRO:
                    scene.reset(new tta::title_screen(text_generator));
                    break;
                case tta::scene_types::GAME:
                    scene.reset(new tta::game_screen(text_generator));
                    break;
                default:
                    BN_ERROR("Invalid next scene: ", int(next_scene.value()));
                    break;
            }
        }
    }
}
