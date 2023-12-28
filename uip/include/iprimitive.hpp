#pragma once

#include "stdint.h"

#include "../../types.hpp"

namespace qymos
{
    namespace gui
    {
        /**
         * @brief Intarface base primitive object to draw
         *
         */
        class IPrimitive
        {
        protected:
            Position _position;

        public:
            /**
             * @brief Called to draw to a buffer
             *
             * @param buffer Display buffer
             */
            virtual void Render(DisplayBuffer *buffer) = 0;
            /**
             * @brief Set the visible
             *
             * @param visible
             */
            virtual void Visible(bool visible = true) = 0;
            /**
             * @brief Set the Position
             *
             * @param position
             */
            void SetPosition(Position position) { _position = position; };
            /**
             * @brief Get the Position
             *
             * @return Position
             */
            Position GetPosition() { return _position; };
        };

    } // namespace qui
} // namespace qymos
