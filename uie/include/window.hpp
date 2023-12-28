#pragma once

#include "stdint.h"

#include "types.hpp"
#include "ielement.hpp"
#include "layout.hpp"

#include "uip/include/bitmap.hpp"
#include "uip/include/text.hpp"
#include "uip/include/line.hpp"
#include "uip/include/rect.hpp"

namespace qymos
{
    namespace gui
    {
        class Window : public IElement
        {
        private:
            Rect _titleBar;
            Rect _bodyBorder;
            Text *_titleText;
            Bitmap *_icon = nullptr;
            Layout *_layout;
            bool _isVisible = true;
            uint8_t _titleHeight = 13;

        public:
            void Render(DisplayBuffer *buffer);
            void SetTitle(Text *text, Bitmap *icon = nullptr);
            void SetBody(Layout *layout);
            void SetTitleHeight(uint8_t height);
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
