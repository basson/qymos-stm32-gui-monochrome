#pragma once

#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#include "../types.hpp"
#include "ielement.hpp"

#include "../uip/rect.hpp"
#include "../uip/text.hpp"

namespace qymos
{
    namespace gui
    {
        class Message : public IElement
        {
        private:
            Rect _border;
            Rect _rect;
            Text *_textMessage;
            bool _isVisible = true;

        public:
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void SetMessageText(Text *text);
            void Visible(bool visible = true);
        };

    } // namespace gui

} // namespace qymos
