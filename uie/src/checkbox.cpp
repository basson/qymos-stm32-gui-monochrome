#include "../include/checkbox.hpp"

namespace qymos
{
namespace gui
{
    void CheckBox::Render(DisplayBuffer *buffer)
    {
        return Render(buffer, 0, 0);
    }
    void CheckBox::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
    {
        if (!_visible)
            return;

        _border.SetPosition({_position.x, _position.y, _position.width, _position.height});
        _border.SetInvert(_invert);
        _border.Render(buffer);//, width, height);

        if (!_isCheck)
            return;

        _check.SetFill(true);
        _check.SetInvert(_invert);
        if (_position.height < 5 || _position.width < 5)
            _check.SetPosition({_position.x, _position.y, _position.width, _position.height});
        else
            _check.SetPosition({(uint16_t)(_position.x + 2), (uint16_t)(_position.y + 2), (uint16_t)(_position.width - 4), (uint16_t)(_position.height - 4)});
        _check.Render(buffer);//, width, height);
    }
    void CheckBox::SetPosition(Position position)
    {
        if (position.width != 0 && position.height != 0)
            _position = position;
        else
        {
            _position.x = position.x;
            _position.y = position.y;
        }
    }
    void CheckBox::SetCheck(bool check)
    {
        _isCheck = check;
    }
    bool CheckBox::IsCheck()
    {
        return _isCheck;
    }
    void CheckBox::SetInvert(bool invert)
    {
        _invert = invert;
    }
    void CheckBox::Visible(bool visible)
    {
        _visible = visible;
    };
} // namespace qui
} // namespace qymos
