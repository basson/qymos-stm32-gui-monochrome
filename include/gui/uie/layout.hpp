#pragma once

#include "stdint.h"

#include "../types.hpp"
#include "ielement.hpp"

namespace qymos
{
    namespace gui
    {
        class Layout : public IElement
        {
        private:
            IPrimitive *_primitive[40];
            uint8_t _lastIndex = 0;
            bool _isVisible = true;

        public:
            void Render(DisplayBuffer *buffer);
            void SetPrimitive(IPrimitive *primitive);
            void SetElement(IElement *element);
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
