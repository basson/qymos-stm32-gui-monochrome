#pragma once

#include "stdint.h"
#include "types.hpp"
#include "uip/include/iprimitive.hpp"

namespace qymos
{
    namespace gui
    {
        class IElement : public IPrimitive
        {
        protected:
        public:
            // virtual void Render(DisplayBuffer *buffer) = 0;
            // virtual void Visible(bool visible = true) = 0;
        };

    } // namespace qui
} // namespace qymos
