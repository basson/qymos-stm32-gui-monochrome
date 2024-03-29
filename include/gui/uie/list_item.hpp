#pragma once

#include "stdint.h"

#include "../types.hpp"
#include "ielement.hpp"

#include "checkbox.hpp"

#include "../uip/text.hpp"
#include "../uip/rect.hpp"
#include "../uip/bitmap.hpp"

namespace qymos
{
    namespace gui
    {
        class ListItem : public IElement
        {
        private:
            Text *_text;
            Rect _rect;
            Bitmap *_icon = nullptr;
            CheckBox *_check = nullptr;
            bool _isChecked = false;
            bool _active = false;

        public:
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void SetText(Text *text);
            void SetIcon(Bitmap *bitmap);
            void SetCheckBox(CheckBox *check);
            void SetCheckBoxState(bool state = false);
            bool GetCheckBoxState();
            void Active(bool active = false);
            void Visible(bool visible = true){};
        };

    } // namespace qui
} // namespace qymos
