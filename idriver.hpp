#pragma once

#include "stdint.h"
#include "types.hpp"

namespace qymos
{
    namespace gui
    {
        /**
         * @brief Intefаce graphical driver
         *
         */
        class IDriver
        {
        public:
            /**
             * @brief Initialize driver
             *
             * @return true Done
             * @return false Error
             */
            virtual bool Initialize() = 0;
            /**
             * @brief Deinitialize driver
             *
             * @return true Done
             * @return false Error
             */
            virtual bool DeInitialize() = 0;
            /**
             * @brief Send command to display
             *
             * @param command command
             * @param delayUs Time delay us
             * @return true Done
             * @return false Error
             */
            virtual bool SendCommand(uint8_t command, uint16_t delayUs = 0) = 0;
            /**
             * @brief Send buffer to display
             *
             * @param buffer Buffer
             * @param x X point area
             * @param y Y point area
             * @return true Done
             * @return false Error
             */
            virtual bool SendFrame(DisplayBuffer *buffer, uint16_t x = 0, uint16_t y = 0) = 0;
            /**
             * @brief Reset display
             *
             * @return true Done
             * @return false Error
             */
            virtual bool Reset() = 0;
            /**
             * @brief Check display
             *
             * @return true Done
             * @return false Error
             */
            virtual bool Check() = 0;
        };

    } // namespace qui
} // namespace qymos
