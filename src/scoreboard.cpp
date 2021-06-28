#include "bn_string.h"

#include "scoreboard.h"
#include "text_utils.h"

namespace tta
{
    scoreboard::scoreboard(bn::sprite_text_generator& text_generator) :
        _text_generator(text_generator)
    {
        _text_generator.set_center_alignment();
        _text_generator.generate(88, -70, "SCORE 0", _score_text_sprites);
    }

    void scoreboard::set_visible(bool visible)
    {
        tta::text_utils::set_sprite_vector_visibility(visible, _score_text_sprites);
    }

    void scoreboard::update(int score)
    {
        _score = score;

        _score_text_sprites.clear();

        bn::string<12> score_text = bn::to_string<4>(_score);
        _text_generator.generate(82, -70, "SCORE " + score_text, _score_text_sprites);
    }
}