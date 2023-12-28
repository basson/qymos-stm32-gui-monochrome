#pragma once

#include "stdint.h"

#include "types.hpp"
#include "ielement.hpp"
#include "uip/include/line.hpp"
#include "uip/include/rect.hpp"

namespace qymos
{
    namespace gui
    {
        class Progress : public IElement
        {
        private:
            uint8_t _count = 0;
            uint8_t _progress = 0;
            Rect _border;
            Rect _bar;
            Orientation _orientation = ORIENTATION_HORIZONTAl;

            void RenderVertical(DisplayBuffer *buffer);
            void RenderHorizontal(DisplayBuffer *buffer);

        public:
            void Render(DisplayBuffer *buffer);
            void SetCount(uint8_t count);
            void SetProgress(uint8_t progress);
            void SetOrientation(Orientation orientation = ORIENTATION_HORIZONTAl);
            void Visible(bool visible = true){};
        };

    } // namespace qui
} // namespace qymos
