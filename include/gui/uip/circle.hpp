#pragma once

#include "stdint.h"
#include "math.h"

#include "../types.hpp"
#include "iprimitive.hpp"

namespace qymos
{
    namespace gui
    {

        class Circle : public IPrimitive
        {
        private:
            bool _isNeedRender = true;
            bool _visible = true;
            void RenderFill(DisplayBuffer *buffer);
            void RenderContour(DisplayBuffer *buffer);

        public:
            void Render(DisplayBuffer *buffer);
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            void SetPosition(Position position);
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
