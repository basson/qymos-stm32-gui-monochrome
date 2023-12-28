#include "../include/window.hpp"

namespace qymos
{
namespace gui
{
    void Window::Render(DisplayBuffer *buffer)
    {
        if (!_isVisible)
            return;
        Position position = {0, 0, 0, 0};

        _layout->Render(buffer);

        _bodyBorder.SetPosition({_position.x, (uint16_t)(_position.y +_titleHeight - 1), _position.width, (uint16_t)(_position.height - _titleHeight + 1)});
        _bodyBorder.SetBorder(1);
        _bodyBorder.Render(buffer);

        _titleBar.SetPosition({_position.x, _position.y, _position.width, _titleHeight});
        _titleBar.SetFill(true);
        _titleBar.Render(buffer);

        if (_icon != nullptr)
        {
            position = _icon->GetPosition();
            _icon->SetPosition({(uint16_t)(_position.x + 3), (uint16_t)(_position.y + (_titleHeight / 2 - position.height / 2)), 0, 0});
            _icon->SetInvert(true);
            _icon->Render(buffer);
        }

        position = _titleText->GetPosition();
        _titleText->SetPosition({(uint16_t)(_position.x + (_position.width / 2 - position.width / 2)), (uint16_t)(_position.y + (_titleHeight / 2 - position.height / 2)), 0, 0});
        _titleText->SetInvert(true);
        _titleText->Render(buffer);
    }
    void Window::SetTitle(Text *text, Bitmap *icon)
    {
        _titleText = text;
        _icon = icon;
    }
    void Window::SetBody(Layout *layout)
    {
        _layout = layout;
    }
    void Window::SetTitleHeight(uint8_t height)
    {
        _titleHeight = height;
    }
    void Window::Visible(bool visible)
    {
        _isVisible = visible;
    }
} // namespace qui
} // namespace qymos
