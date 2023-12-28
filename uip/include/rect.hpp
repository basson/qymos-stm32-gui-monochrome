#pragma once

#include "stdint.h"

#include "types.hpp"
#include "iprimitive.hpp"
#include "line.hpp"

namespace qymos
{
    namespace gui
    {
        class Rect : public IPrimitive
        {
        private:
            bool _isNeedRender = true;
            uint8_t _border = 1;
            bool _fill = false;
            Line _line;
            bool _visible = true;
            bool _invert = false;

        public:
            /**
             * @brief Called to draw to a buffer
             *
             * @param buffer Display Buffer
             */
            void Render(DisplayBuffer *buffer);
            /**
             * @brief Called to draw to a buffer
             *
             * @param buffer Display Buffer
             * @param width Width draw
             * @param height Height draw
             */
            void Render(DisplayBuffer *buffer, uint16_t width, uint16_t height);
            /**
             * @brief Set the fill rect
             *
             * @param fill
             */
            void SetFill(bool fill = false);
            /**
             * @brief Set the Border react
             *
             * @param border Border width
             */
            void SetBorder(uint8_t border = 1);
            /**
             * @brief Set the Invert
             *
             * @param invert Invert
             */
            void SetInvert(bool invert = false);
            /**
             * @brief Set the visible
             *
             * @param visible
             */
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
