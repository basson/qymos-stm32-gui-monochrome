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
            int8_t _active = 0;
            uint8_t _listItemHeight = 13;
            Scroll _scroll;
            bool _isVisible = true;

        public:
            void Render(DisplayBuffer *buffer);
            void AddItem(Text *text);
            void AddItem(Text *text, Bitmap *bitmap);
            void AddItem(Text *text, CheckBox *check);
            void RemoveItem(uint8_t index);
            void SetPosition(Position position);
            void SetItemHeight(uint8_t height);
            void SetActiveItem(uint8_t active);
            uint8_t GetActiveItem();
            void ChangeActiveByDirection(bool direction);
            uint8_t GetSize();
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
