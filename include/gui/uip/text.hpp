#pragma once

#include "stdint.h"

#include "../types.hpp"
#include "iprimitive.hpp"

namespace qymos
{
    namespace gui
    {
        class Text : public IPrimitive
        {
        private:
            bool _isNeedRender = true;
            char *_text;
            bool _invert = false;
            const tFont *_font;
            bool _visible = true;
            void GetBounds();

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
             * @brief Set the Font
             *
             * @param font link tFont struct
             */
            void SetFont(const tFont *font);
            /**
             * @brief Set the Text
             *
             * @param text Char array
             */
            void SetText(char *text);
            void SetText(const char *text);
            /**
             * @brief Set the Invert
             *
             * @param invert Invert
             */
            void SetInvert(bool invert = false);
            /**
             * @brief Set the Position
             *
             * @param position
             */
            void SetPosition(Position position);
            /**
             * @brief Get the Width text
             *
             * @return uint16_t Width
             */
            uint16_t GetWidth();
            /**
             * @brief Get the Height text
             *
             * @return uint16_t Height
             */
            uint16_t GetHeight();
            /**
             * @brief Set the visible
             *
             * @param visible
             */
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
