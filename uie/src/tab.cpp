#include "../include/tab.hpp"

namespace qymos
{
namespace gui
{
    void Tab::Render(DisplayBuffer *buffer)
    {
        _rect.SetPosition({_position.x, _position.y, _position.width, _position.height});
        _text->SetPosition({(uint16_t)(_position.x + (_position.width / 2 - _text->GetWidth() / 2)),
                           (uint16_t)(_position.y + (_position.height / 2 - _text->GetHeight() / 2)), 0, 0});
        _rect.Render(buffer);
        _text->Render(buffer);
    }
    void Tab::SetText(Text *text)
    {
        _text = text;
    }
    void Tab::Active(bool active)
    {
        _rect.SetFill(active);
        _text->SetInvert(active);
    }
} // namespace qui
} // namespace qymos
