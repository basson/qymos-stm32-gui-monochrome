#pragma once

#include "stdint.h"

#include "types.hpp"
#include "ielement.hpp"
#include "uip/include/line.hpp"
#include "tab.hpp"

namespace qymos
{
    namespace gui
    {
        class TabBar : public IElement
        {
        private:
            Tab *_element[10];
            uint8_t _lastIndex = 0;
            uint8_t _active = 0;

        public:
            void AddTab(Text *text);
            void RemoveTab(uint8_t index);
            void Render(DisplayBuffer *buffer);
            void SetActiveTab(uint8_t active);
            void Visible(bool visible = true){};
        };

    } // namespace qui
} // namespace qymos
