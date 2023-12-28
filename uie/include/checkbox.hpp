#pragma once

#include "stdint.h"

#include "types.hpp"
#include "ielement.hpp"
#include "uip/include/rect.hpp"

namespace qymos
{
    namespace gui
    {
        class CheckBox : public IElement
        {
        private:
            Rect _border;
            Rect _check;
            bool _isCheck = false;
            bool _invert = false;
            bool _visible = true;

        public:
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void SetPosition(Position position);
            void SetCheck(bool check);
            bool IsCheck();
            void SetInvert(bool invert = false);
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
