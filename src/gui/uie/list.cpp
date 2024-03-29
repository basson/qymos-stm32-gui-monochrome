#include "../../../include/gui/uie/list.hpp"

namespace qymos
{
    namespace gui
    {

        void List::AddItem(Text *text)
        {
            Bitmap *bitmap = nullptr;
            AddItem(text, bitmap);
        }
        void List::AddItem(Text *text, Bitmap *bitmap)
        {
            if (_lastIndex >= 30)
                return;
            _element[_lastIndex] = new ListItem();
            _element[_lastIndex]->SetText(text);
            _element[_lastIndex]->SetIcon(bitmap);
            _lastIndex++;
            _scroll.SetCount(_lastIndex);
        }
        void List::AddItem(Text *text, CheckBox *check)
        {
            if (_lastIndex >= 30)
                return;
            _element[_lastIndex] = new ListItem();
            _element[_lastIndex]->SetText(text);
            _element[_lastIndex]->SetCheckBox(check);
            _lastIndex++;
            _scroll.SetCount(_lastIndex);
        }
        void List::RemoveItem(uint8_t index)
        {
        }
        void List::Render(DisplayBuffer *buffer)
        {
            if (!_isVisible)
                return;

            uint8_t itemRenderStart = 0;
            uint8_t itemRenderLenght = _position.height / _listItemHeight;
            if (_position.height % _listItemHeight)
                itemRenderLenght++;

            if (_active >= _position.height / _listItemHeight)
                itemRenderStart = _active - _position.height / _listItemHeight + 1;

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
                _element[itemRenderStart + i]->Render(buffer, _position.x + _position.width, position.y + _position.height);
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
        uint8_t List::GetActiveItem()
        {
            return _active;
        }
        void List::ChangeActiveByDirection(bool direction)
        {
            if (!direction)
                _active++;
            else
                _active--;

            if (_active > GetSize())
                _active = 0;
            if (_active < 0)
                _active = GetSize();

            _scroll.SetProgress(_active);
        }
        void List::SetItemCheck(uint8_t index, bool check)
        {
            if (index >= _lastIndex)
                return;
            _element[index]->SetCheckBoxState(check);
        }
        void List::SetAllItemCheck(bool check)
        {
            for (uint8_t i = 0; i < _lastIndex; i++)
            {
                _element[i]->SetCheckBoxState(check);
            }
        }
        uint8_t List::IsItemsCheck(uint8_t *indexes, bool check)
        {
            uint8_t count = 0;
            for (uint8_t i = 0; i < _lastIndex; i++)
            {
                if (_element[i]->GetCheckBoxState() == check)
                {
                    indexes[count] = i;
                    count++;
                }
            }

            return count;
        }
        bool List::IsItemCheck(uint8_t index)
        {
            if (index >= _lastIndex)
                return false;
            return _element[index]->GetCheckBoxState();
        }
        uint8_t List::GetSize()
        {
            return _lastIndex - 1;
        }

        void List::Visible(bool visible)
        {
            _isVisible = visible;
        }
    } // namespace qui
} // namespace qymos
