#include "../include/tab_page.hpp"

namespace qymos
{
namespace gui
{
    void TabPage::Render(DisplayBuffer *buffer)
    {
        _rect.Render(buffer);
        for (uint8_t i = 0; i < _lastIndex; i++)
        {
            _element[i]->Render(buffer);
        }
    }
    void TabPage::SetElement(IPrimitive *element)
    {
        if(_lastIndex >= 10)
            return;
        _element[_lastIndex] = element;
        _lastIndex++;
    }
    void TabPage::SetPosition(Position position)
    {
        _position = position;
        _rect.SetPosition({_position.x , _position.y, _position.width,  _position.height});
    }
} // namespace qui
} // namespace qymos
