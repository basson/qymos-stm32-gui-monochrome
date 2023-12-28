#pragma once

#include "stdint.h"

#include "types.hpp"
#include "ielement.hpp"
#include "uip/include/line.hpp"
#include "uip/include/rect.hpp"
#include "tab.hpp"

namespace qymos
{
    namespace gui
    {
        class TabPage : public IElement
        {
        private:
            IPrimitive *_element[10];
            uint8_t _lastIndex = 0;
            Position _position;
            Rect _rect;

        public:
            void Render(DisplayBuffer *buffer);
            void SetElement(IPrimitive *element);
            void SetPosition(Position position);
            void Visible(bool visible = true){};
        };

    } // namespace qui
} // namespace qymos
