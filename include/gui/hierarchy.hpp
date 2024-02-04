#pragma once

#include "stdint.h"
#include "gui/iscreen.hpp"

namespace qymos
{
    namespace gui
    {
        /**
         * @brief Hierrarcy class from organize screen/window on display, this is class a singleton
         *
         */
        class Hierarchy
        {
        protected:
            Hierarchy(){};
            static Hierarchy *_hierarchy;

        private:
            /**
             * @brief Item on entity to draw hierarhy on display
             *
             */
            struct Item
            {
                uint8_t id = 0;   ///< Id item entity
                uint8_t parent;   ///< Id parent item entity
                IScreen *element; /// Link screen element
            };
            Item _item[60];
            uint8_t _lastIndex = 0;
            uint8_t _selectedId = 0;

        public:
            Hierarchy(Hierarchy &other) = delete;
            void operator=(const Hierarchy &) = delete;
            /**
             * @brief Get the Instance
             *
             * @return Hierarchy* Instance link
             */
            static Hierarchy *GetInstance();
            /**
             * @brief Add itam in hierarchy
             *
             * @param id Current item Id
             * @param parentId Parent item Id
             * @param element Screen element
             */
            void AddItem(uint8_t id, uint8_t parentId, IScreen *element);
            /**
             * @brief Get the Parent item
             *
             * @param id Current item Id
             * @return int8_t Parrent item Id or -1
             */
            int8_t GetParent(uint8_t id);
            /**
             * @brief Get the Child item
             *
             * @param id Current item Id
             * @param childs Childs id array
             * @return int8_t Count childs item or -1
             */
            int8_t GetChild(uint8_t id, uint8_t *childs);
            /**
             * @brief Get the item scren by Id
             *
             * @param id Item Id
             * @return IScreen* link item screen
             */
            IScreen *GetItem(uint8_t id);
            /**
             * @brief Set item Id to default selected
             *
             * @param id Item Id
             */
            void SetSelectedItem(uint8_t id);
            /**
             * @brief Get default item Id selected
             *
             * @return uint8_t Item Id
             */
            uint8_t GetSelectedItemId();
        };

    } // namespace qui
} // namespace qymos
