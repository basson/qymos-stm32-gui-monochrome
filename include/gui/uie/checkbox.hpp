#pragma once

#include "stdint.h"

#include "../types.hpp"
#include "ielement.hpp"
#include "../uip/bitmap.hpp"

namespace qymos
{
    namespace gui
    {
        class CheckBox : public IElement
        {
        private:
            Bitmap *_bitmapCheck;
            Bitmap *_bitmapUncheck;

            bool _isCheck = false;
            bool _invert = false;
            bool _visible = true;

        public:
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void SetImageCheck(Bitmap *bitmap);
            void SetImageUncheck(Bitmap *bitmap);
            void SetPosition(Position position);
            void SetCheck(bool check);
            bool IsCheck();
            void SetInvert(bool invert = false);
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
