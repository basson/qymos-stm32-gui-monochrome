#pragma once

#include "stdint.h"

#include "../types.hpp"
#include "ielement.hpp"
#include "../uip/line.hpp"
#include "../uip/rect.hpp"

namespace qymos
{
    namespace gui
    {
        class Scroll : public IElement
        {
        private:
            uint8_t _count = 0;
            uint8_t _progress = 0;
            Line _line;
            Rect _bar;
            Orientation _orientation = ORIENTATION_VERTICAL;
            void RenderVertical(DisplayBuffer *buffer);
            void RenderHorizontal(DisplayBuffer *buffer);

        public:
            void Render(DisplayBuffer *buffer);
            void SetCount(uint8_t count);
            void SetProgress(uint8_t progress);
            void SetOrientation(Orientation orientation = ORIENTATION_VERTICAL);
            void Visible(bool visible = true){};
        };

    } // namespace qui
} // namespace qymos
