#pragma once

#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#include "types.hpp"
#include "ielement.hpp"

#include "uip/include/text.hpp"
#include "uip/include/rect.hpp"

namespace qymos
{
    namespace gui
    {
        class InputText : public IElement
        {
        private:
            Rect _border;
            Rect _rect;
            Rect _activeRect;
            bool _isVisible = true;
            uint32_t _millis = 0;

            Text _text;

            char _str[30] = "0";
            char _symbols[41] = "1234567890-=qwertyuiopasdfghjklzxcvbnm,.";

        public:
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void SetFont(const tFont *font);
            void SetMin(int32_t min);
            void SetMax(int32_t max);
            void SetValue(int32_t value);
            void Increase(uint8_t value = 1);
            void Decrease(uint8_t value = 1);
            int32_t GetValue();
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
