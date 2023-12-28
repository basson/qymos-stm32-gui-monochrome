#include "../include/list.hpp"

namespace qymos
{
namespace gui
{
    void List::addItem(Text *text, Bitmap *bitmap)
    {
        if (_lastIndex >= 30)
            return;
        _element[_lastIndex] = new ListItem();
        _element[_lastIndex]->SetText(text);
        _element[_lastIndex]->SetIcon(bitmap);
        _scroll.SetCount(_lastIndex);
        _lastIndex++;
    }
    void List::addItem(Text *text, CheckBox *check)
    {
        if (_lastIndex >= 30)
            return;
        _element[_lastIndex] = new ListItem();
        _element[_lastIndex]->SetText(text);
        _element[_lastIndex]->SetCheckBox(check);
        _scroll.SetCount(_lastIndex);
        _lastIndex++;
    }
    void List::removeItem(uint8_t index)
    {
    }
    void List::Render(DisplayBuffer *buffer)
    {
        uint8_t itemRenderStart = 0;
        uint8_t itemRenderLenght = _position.height / _listItemHeight;
        if (_position.height % _listItemHeight)
            itemRenderLenght++;

        if (_active >= _position.height / _listItemHeight)
            itemRenderStart = _active - _position.height / _listItemHeight+1;

        Position position = {_position.x, 0, (uint16_t)(_position.width - 4), _listItemHeight};
        for (uint8_t i = 0; i < itemRenderLenght; i++)
        {
            if (itemRenderStart + i >= _lastIndex)
                break;
            position.y = _position.y + i * _listItemHeight - i;
            if (itemRenderStart + i == _active)
                _element[itemRenderStart + i]->Active(true);
            else
                _element[itemRenderStart + i]->Active(false);

            _element[itemRenderStart + i]->SetPosition(position);
            _element[itemRenderStart + i]->Render(buffer, _position.width - 4, position.y+_position.height);
        }

        _scroll.Render(buffer);
    }
    void List::SetPosition(Position position)
    {
        _position = position;
        _scroll.SetPosition({(uint16_t)(_position.x + _position.width - 3), _position.y, 3, _position.height});
    }
    void List::SetItemHeight(uint8_t height)
    {
        _listItemHeight = height;
    }
    void List::SetActiveItem(uint8_t active)
    {
        _active = active;
        _scroll.SetProgress(_active);
    }
    uint8_t List::GetSize()
    {
        return _lastIndex - 1;
    }
} // namespace qui
} // namespace qymos
