#pragma once

#include "stdint.h"

#include "types.hpp"
#include "iprimitive.hpp"

namespace qymos
{
    namespace gui
    {
        /**
         * @brief Bitmap class
         *
         */
        class Bitmap : public IPrimitive
        {
        private:
            bool _invert = false;
            const tImage *_image;
            bool _visible = true;

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
             * @brief Set the Image
             *
             * @param image link tImage struct
             */
            void SetImage(const tImage *image);
            /**
             * @brief Set the Invert image
             *
             * @param invert Invert
             */
            void SetInvert(bool invert = false);
            /**
             * @brief Set the Position image to draw
             *
             * @param position Position struct
             */
            void SetPosition(Position position);
            /**
             * @brief Set the visible
             *
             * @param visible
             */
            void Visible(bool visible = true);
        };

    } // namespace qui
} // namespace qymos
