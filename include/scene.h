#ifndef SCENE_H
#define SCENE_H

#include "bn_optional.h"

#include "scene_types.h"

namespace tta
{
    class scene
    {
        public:

            virtual ~scene() = default;
            virtual bn::optional<tta::scene_types> update() = 0;
    };
}

#endif