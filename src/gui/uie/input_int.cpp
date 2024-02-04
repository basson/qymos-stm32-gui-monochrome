#include "../../../include/gui/uie/input_int.hpp"

namespace qymos
{
    namespace gui
    {
        void InputInt::Render(DisplayBuffer *buffer)
        {
            return Render(buffer, 0, 0);
        }
        void InputInt::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
        {
            if (!_isVisible)
                return;

            if (width == 0)
                width = _position.x + _position.width;
            if (height == 0)
                height = _position.y + _position.height;

            _rect.SetPosition(_position);
            _rect.SetFill(true);
            _rect.SetInvert(true);
            _rect.Render(buffer, width, height);

            _border.SetPosition(_position);
            _border.SetBorder(1);
            _border.SetFill(false);
            _border.Render(buffer, width, height);

            itoa(_value, _str, 10);
            _text.SetText(_str);
            _text.SetPosition({(uint16_t)(_position.x + (_position.width / 2 - _text.GetWidth() / 2)), (uint16_t)(_position.y + (_position.height / 2 - _text.GetHeight() / 2)), 0, 0});
            _text.Render(buffer, width, height);
        }
        void InputInt::SetFont(const tFont *font)
        {
            _text.SetFont(font);
        }
        void InputInt::SetMin(int32_t min)
        {
            _min = min;
        }
        void InputInt::SetMax(int32_t max)
        {
            _max = max;
        }
        void InputInt::SetValue(int32_t value)
        {
            if (value > _max)
                value = _max;
            if (value < _min)
                value = _min;
            _value = value;
        }
        void InputInt::Increase(uint8_t value)
        {
            _value += value;
            if (_value > _max)
                _value = _max;
        }
        void InputInt::Decrease(uint8_t value)
        {
            if (_value - value >= _min)
                _value -= value;
            else
                _value = _min;
        }
        int32_t InputInt::GetValue()
        {
            return _value;
        }
        void InputInt::Visible(bool visible)
        {
            _isVisible = visible;
        }
    } // namespace qui
} // namespace qymos
