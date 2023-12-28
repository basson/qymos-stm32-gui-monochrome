#pragma once

#include "types.hpp"
#include "uie/include/ielement.hpp"

namespace qymos
{
    namespace gui
    {
        /**
         * @brief Screen interface
         *
         */
        class IScreen
        {
        public:
            /**
             * @brief Get the Page element
             *
             * @return qymos::gui::IElement* Link page element
             */
            virtual qymos::gui::IElement *GetPage() = 0;
            /**
             * @brief Plase this function to default loop
             *
             */
            virtual void Process() = 0;
            /**
             * @brief Event encoder rotation
             *
             * @param direction Rotate direction
             */
            virtual void OnEncoderDirection(bool direction) = 0;
            /**
             * @brief Event encoder change value
             *
             * @param value Encoder value
             */
            virtual void OnEncoderValue(uint32_t value) = 0;
            /**
             * @brief Event button click
             *
             * @param ButtonPin Button pin
             */
            virtual void OnButtonClick(uint16_t ButtonPin = 0) = 0;
            /**
             * @brief Event button long click
             *
             * @param ButtonPin Button pin
             */
            virtual void OnButtonLongClick(uint16_t ButtonPin = 0) = 0;
        };

    } // namespace qui
} // namespace qymos
