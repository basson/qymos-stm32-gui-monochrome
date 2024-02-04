#pragma once

#include "stdint.h"
#include <string.h>
#include "gui/types.hpp"

namespace qymos
{
    namespace gui
    {
        /**
         * @brief Utf8 search font symbol
         *
         */
        class Utf8Char
        {
        public:
            static int GetCharCode(const char *str, int start, int *resultCode, int *nextIndex);
            static const tChar *FindCharByCode(int code, const tFont *font);
        };

    } // namespace qui
} // namespace qymos
