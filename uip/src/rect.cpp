#include "../include/rect.hpp"

namespace qymos
{
    namespace gui
    {
        void Rect::Render(DisplayBuffer *buffer)
        {
            return Render(buffer, 0, 0);
        }
        void Rect::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
        {
            if (!_visible)
                return;
            if (width == 0 && height == 0)
            {
                width = _position.width;
                height = _position.height;
            }
            if (_fill)
            {
                _line.SetPosition({_position.x, _position.y, _position.width, _position.height});
                _line.SetInvert(_invert);
                _line.Render(buffer, width, height);
                return;
            }
            _line.SetPosition({_position.x, _position.y, _position.width, _border});
            _line.SetInvert(_invert);
            _line.Render(buffer, width, height);
            _line.SetPosition({_position.x, (uint16_t)(_position.y + _position.height - _border), _position.width, _border});
            _line.SetInvert(_invert);
            _line.Render(buffer, width, height);
            _line.SetPosition({_position.x, _position.y, _border, _position.height});
            _line.SetInvert(_invert);
            _line.Render(buffer, width, height);
            _line.SetPosition({(uint16_t)(_position.x + _position.width - _border), _position.y, _border, _position.height});
            _line.SetInvert(_invert);
            _line.Render(buffer, width, height);
        }
        void Rect::SetFill(bool fill)
        {
            _fill = fill;
        }
        void Rect::SetBorder(uint8_t border)
        {
            _border = border;
        }
        void Rect::Visible(bool visible)
        {
            _visible = visible;
        }
        void Rect::SetInvert(bool invert)
        {
            _invert = invert;
        }
    } // namespace qui
} // namespace qymos
