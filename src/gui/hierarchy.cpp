#include "../../include/gui/hierarchy.hpp"

namespace qymos
{
    namespace gui
    {
        Hierarchy *Hierarchy::_hierarchy = nullptr;

        Hierarchy *Hierarchy::GetInstance()
        {

            if (_hierarchy == nullptr)
            {
                _hierarchy = new Hierarchy();
            }
            return _hierarchy;
        }

        void Hierarchy::AddItem(uint8_t id, uint8_t parentId, IScreen *element)
        {
            if (_lastIndex >= 60)
                return;
            _item[_lastIndex].id = id;
            _item[_lastIndex].parent = parentId;
            _item[_lastIndex].element = element;

            _lastIndex++;
        }
        int8_t Hierarchy::GetParent(uint8_t id)
        {
            for (uint8_t i = 0; i < _lastIndex; i++)
            {
                if (_item[i].id == id)
                    return _item[i].parent;
            }
            return -1;
        }
        int8_t Hierarchy::GetChild(uint8_t id, uint8_t *childs)
        {
            int8_t count = -1;
            for (uint8_t i = 0; i < _lastIndex; i++)
            {
                if (_item[i].parent == id)
                {
                    count++;
                    childs[count] = _item[i].id;
                }
            }
            return count;
        }
        IScreen *Hierarchy::GetItem(uint8_t id)
        {
            for (uint8_t i = 0; i < _lastIndex; i++)
            {
                if (_item[i].id == id)
                    return _item[i].element;
            }
            return nullptr;
        }

        void Hierarchy::SetSelectedItem(uint8_t id)
        {
            _selectedId = id;
        }
        uint8_t Hierarchy::GetSelectedItemId()
        {
            return _selectedId;
        }
    } // namespace qui
} // namespace qymos
