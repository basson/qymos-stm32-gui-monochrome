#pragma once

#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#include "types.hpp"
#include "ielement.hpp"

#include "uip/include/rect.hpp"

#include "uie/include/list.hpp"


namespace qymos
{
    namespace gui
    {
        class InputSelect : public IElement
        {
        private:
            Rect _border;
            Rect _rect;
            List _list;
            bool _isVisible = true;

        public:
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void RemoveItem(uint8_t index);
            void AddItem(Text *text, Bitmap *bitmap = nullptr);
            void AddItem(Text *text, CheckBox *check = nullptr);
            void SetPosition(Position position);
            void SetItemHeight(uint8_t height);
            void SetActiveItem(uint8_t active);
            uint8_t GetActiveItem();
            void ChangeActiveByDirection(bool direction);
            uint8_t GetSize();
            void Visible(bool visible = true);
        };

    } // namespace gui

} // namespace qymos
