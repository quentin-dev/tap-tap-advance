#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_timer.h"
#include "bn_log.h"
#include "bn_vector.h"

#include "gj_big_sprite_font.h"
#include "bn_sprite_items_red_note.h"

#include "bn_music_items.h"

int main()
{
    bn::core::init();

    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    bn::sprite_text_generator text_generator(gj::big_sprite_font);

    text_generator.set_center_alignment();
    bn::vector<bn::sprite_ptr, 32> text_sprites;

    bn::sprite_ptr red_sprite = bn::sprite_items::red_note.create_sprite(0, 0);
    red_sprite.set_scale(0.5);

    // text_generator.generate(0, 0, "Hello, World!", text_sprites);

    bn::music_items::midiboi.play(0.0);

    bn::timer timer;

    const int TICKS_PER_SECONDS = 262123;

    int seconds = 0;

    timer.restart();

    while(true)
    {
        bn::core::update();
        if (timer.elapsed_ticks() >= TICKS_PER_SECONDS)
        {
            seconds += 1;
            timer.restart();
        }
        BN_LOG("Seconds: ", seconds);
    }
}
