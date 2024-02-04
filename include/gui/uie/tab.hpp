#pragma once

#include "stdint.h"

#include "../types.hpp"
#include "ielement.hpp"

#include "../uip/text.hpp"
#include "../uip/rect.hpp"

namespace qymos
{
    namespace gui
    {
        class Tab : public IPrimitive
        {
        private:
            bool _isActive = false;
            Text *_text;
            Rect _rect;

        public:
            void Render(DisplayBuffer *buffer);
            void SetText(Text *text);
            void Active(bool active = false);
            void Visible(bool visible = true){};
        };

    } // namespace qui
} // namespace qymos
