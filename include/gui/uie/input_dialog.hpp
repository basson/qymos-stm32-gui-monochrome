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
            enum Variant {
                VARIANT_CANCEL = 0,
                VARIANT_OK,
            };
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void SetMessageText(Text *text);
            void SetCancelText(Text *text);
            void SetOkText(Text *text);
            void SetVariant(Variant variant = VARIANT_CANCEL);
            bool GetResult();
            void Toggle();
            void Visible(bool visible = true);
        };

    } // namespace gui

} // namespace qymos
