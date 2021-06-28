#include "scoreboard.h"
#include "text_utils.h"

namespace tta
{
    scoreboard::scoreboard(bn::sprite_text_generator& text_generator) :
        _text_generator(text_generator)
    {
        _text_generator.set_center_alignment();
        _text_generator.generate(88, -70, "Score: 0", _score_text_sprites);
    }

    void scoreboard::set_visible(bool visible)
    {
        tta::text_utils::set_sprite_vector_visibility(visible, _score_text_sprites);
    }

    void scoreboard::update(int score)
    {
        _score = score;
    }
}