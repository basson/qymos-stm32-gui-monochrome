#include "../../../include/gui/uie/input_float.hpp"

namespace qymos
{
namespace gui
{
    InputFloat::InputFloat()
    {
    }
    void InputFloat::Render(DisplayBuffer *buffer)
    {
        return Render(buffer, 0, 0);
    }
    void InputFloat::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
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

        if (HAL_GetTick() - _millis >= 250)
        {
            _millis = HAL_GetTick();
            _blink = !_blink;
        }

        strcpy(_str, "");
        for (uint8_t i = 0; i < 3; i++)
        {
            if (_time[i] <= 9)
                strcat(_str, "0");
            itoa(_time[i], _buffer, 10);
            strcat(_str, _buffer);
        }
        _text.SetText(_str);
        uint8_t widthAll = _text.GetWidth();
        uint8_t valign = (_position.height / 2 - _text.GetHeight() / 2);
        _text.SetText(":");
        uint8_t widthDelim = _text.GetWidth();
        widthAll += (widthDelim + 8) * 2;
        uint8_t widthSum = 0;
        for (uint8_t i = 0; i < 3; i++)
        {
            _text.SetInvert(false);
            strcpy(_str, "");
            itoa(_time[i], _buffer, 10);
            if (_time[i] <= 9)
                strcat(_str, "0");
            strcat(_str, _buffer);
            _text.SetText(_str);
            if (i == _active)
            {
                _text.SetInvert(_blink);
                _activeRect.SetPosition({(uint16_t)(_position.x + (_position.width / 2 - widthAll / 2) + widthSum - 1), (uint16_t)(_position.y + valign - 1), (uint16_t)(_text.GetWidth() + 1), (uint16_t)(_text.GetHeight() + 1)});
                _activeRect.SetFill(true);
                _activeRect.Render(buffer, width, height);
            }

            _text.SetPosition({(uint16_t)(_position.x + (_position.width / 2 - widthAll / 2) + widthSum), (uint16_t)(_position.y + valign), 0, 0});
            _text.Render(buffer, width, height);
            widthSum += _text.GetWidth();
            if (i < 2)
            {
                _text.SetInvert(false);
                _text.SetText(":");
                _text.SetPosition({(uint16_t)(_position.x + (_position.width / 2 - widthAll / 2) + widthSum + 4), (uint16_t)(_position.y + valign), 0, 0});
                _text.Render(buffer, width, height);
            }
            widthSum += (4 + widthDelim + 4);
        }
    }
    void InputFloat::SetFont(const tFont *font)
    {
        _text.SetFont(font);
    }
    void InputFloat::SetValue(float value)
    {
        _values[0] = (uint32_t)value;
        _values[1] = std::modf(value, nullptr);
    }
    void InputFloat::Next()
    {
        _active--;
        if (_active < 0)
            _active = 2;
    }
    void InputFloat::Increase(uint8_t value)
    {
        _time[_active] += value;
        if (_time[_active] > 60)
            _time[_active] = 60;

        if (_active == 0)
        {
            if (_time[0] > 24)
                _time[0] = 24;
        }
    }
    void InputFloat::Decrease(uint8_t value)
    {
        if (_time[_active] - value >= 0)
            _time[_active] -= value;
        else
            _time[_active] = 0;
    }
    float InputFloat::GetValue()
    {
        return (float)_values[0] + ((float)_values[1] / 10000);
    }
    void InputFloat::Visible(bool visible)
    {
        _active = 1;
        _isVisible = visible;
    }
} // namespace qui
} // namespace qymos
