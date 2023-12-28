#pragma once

#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#include "stm32f1xx_hal.h"

#include "types.hpp"
#include "ielement.hpp"

#include "uip/include/text.hpp"
#include "uip/include/rect.hpp"

namespace qymos
{
    namespace gui
    {
        class InputFloat : public IElement
        {
        private:
            Rect _border;
            Rect _rect;
            Rect _activeRect;
            bool _isVisible = true;
            int8_t _active = 8;
            bool _blink = false;
            uint8_t _time[3] = {
                0,
            };
            uint32_t _values[2] = {0, 0};
            uint32_t _millis = 0;

            Text _text;

            char _str[20] = "0000.00000";
            char _buffer[4];

        public:
            InputFloat();
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void SetFont(const tFont *font);
            void SetValue(float value);
            void Next();
            void Increase(uint8_t value = 1);
            void Decrease(uint8_t value = 1);
            float GetValue();
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos