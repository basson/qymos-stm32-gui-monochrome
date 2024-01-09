#pragma once

#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#include "types.hpp"
#include "ielement.hpp"

#include "uip/include/rect.hpp"
#include "uip/include/text.hpp"

namespace qymos
{
    namespace gui
    {
        class InputDialog : public IElement
        {
        private:
            Rect _border;
            Rect _rect;
            Rect _selected;
            Text *_textMessage;
            Text *_textCancel;
            Text *_textOk;
            bool _result = false;
            bool _isVisible = true;

        public:
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void SetMessageText(Text *text);
            void SetCancelText(Text *text);
            void SetOkText(Text *text);
            bool GetResult();
            void Toggle();
            void Visible(bool visible = true);
        };

    } // namespace gui

} // namespace qymos
