#pragma once

#include "stdint.h"

#include "types.hpp"
#include "ielement.hpp"
#include "list_item.hpp"
#include "scroll.hpp"

namespace qymos
{
    namespace gui
    {
        class List : public IElement
        {
        private:
            ListItem *_element[30];
            uint8_t _lastIndex = 0;
            uint8_t _active = 0;
            uint8_t _listItemHeight = 13;
            Scroll _scroll;

        public:
            void AddItem(Text *text, Bitmap *bitmap = nullptr);
            void AddItem(Text *text, CheckBox *check = nullptr);
            void removeItem(uint8_t index);
            void Render(DisplayBuffer *buffer);
            void SetPosition(Position position);
            void SetItemHeight(uint8_t height);
            void SetActiveItem(uint8_t active);
            uint8_t GetSize();
            void Visible(bool visible = true){};
        };

    } // namespace qui
} // namespace qymos
