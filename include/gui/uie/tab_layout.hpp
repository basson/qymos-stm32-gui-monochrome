#pragma once

#include "stdint.h"

#include "../types.hpp"
#include "ielement.hpp"
#include "../uip/line.hpp"
#include "../uip/text.hpp"
#include "tab_bar.hpp"
#include "tab_page.hpp"

namespace qymos
{
    namespace gui
    {
        class TabLayout : public IElement
        {
        private:
            TabBar _tabBar;
            TabPage *_element[10];
            uint8_t _lastIndex = 0;
            uint8_t _active;
            uint8_t _tabBarHeight;

        public:
            void AddTab(Text *title, TabPage *page);
            void RemoveTab(uint8_t index);

            void Render(DisplayBuffer *buffer);
            void SetTabBarHeight(uint8_t _height);
            void SetActiveTab(uint8_t active);
            uint8_t GetActiveTab(TabPage *page);
            uint8_t GetActiveTab();
            uint8_t GetSize();
            void Visible(bool visible = true){};
        };

    } // namespace qui
} // namespace qymos
