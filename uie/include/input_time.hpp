#pragma once

#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#include "stm32f1xx_hal.h"

#include "types.hpp"
#include "ielement.hpp"

#include "uip/include/text.hpp"
#include "uip/include/rect.hpp"

namespace qymos
{
    namespace gui
    {
        class InputTime : public IElement
        {
        private:
            Rect _border;
            Rect _rect;
            Rect _activeRect;
            bool _isVisible = true;
            int8_t _active = 2; // 2 - seconds, 1 - minutes, 0 - hours
            bool _blink = false;
            uint8_t _time[3] = {0, 0, 0};
            uint32_t _millis = 0;

            Text _text;

            char _str[20] = "00:00:00";
            char _buffer[4];

        public:
            InputTime();
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void SetFont(const tFont *font);
            void SetHours(uint8_t hours);
            void SetMinutes(uint8_t minutes);
            void SetSeconds(uint8_t seconds);
            void Next();
            void Increase(uint8_t value = 1);
            void Decrease(uint8_t value = 1);
            uint8_t GetHours();
            uint8_t GetMinutes();
            uint8_t GetSeconds();
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
