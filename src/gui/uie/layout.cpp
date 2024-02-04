#include "../../../include/gui/uie/layout.hpp"

namespace qymos
{
    namespace gui
    {

        void Layout::SetPrimitive(IPrimitive *primitive)
        {
            if (_lastIndex >= 40)
                return;
            _primitive[_lastIndex] = primitive;
            _lastIndex++;
        }

        void Layout::SetElement(IElement *element)
        {
            if (_lastIndex >= 40)
                return;
            _primitive[_lastIndex] = element;
            _lastIndex++;
        }

        void Layout::Render(DisplayBuffer *buffer)
        {
            if (!_isVisible)
                return;
            for (uint8_t i = 0; i < _lastIndex; i++)
            {
                _primitive[i]->Render(buffer);
            }
        }
        void Layout::Visible(bool visible)
        {
            _isVisible = visible;
        }
    } // namespace gui
} // namespace qymos
