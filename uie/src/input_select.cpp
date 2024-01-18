#include "uie/include/input_select.hpp"

namespace qymos
{
    namespace gui
    {
        void InputSelect::Render(DisplayBuffer *buffer)
        {
            return Render(buffer, 0, 0);
        }
        void InputSelect::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
        {
            if (!_isVisible)
                return;

            _rect.SetPosition(_position);
            _rect.SetFill(true);
            _rect.SetInvert(true);
            _rect.Render(buffer, width, height);

            _border.SetPosition({(uint16_t)(_position.x + 1), (uint16_t)(_position.y + 1), (uint16_t)(_position.width - 2), (uint16_t)(_position.height - 2)});
            _border.SetBorder(1);
            _border.SetFill(false);
            _border.Render(buffer, width, height);

            _list.Render(buffer);
        }
        void InputSelect::RemoveItem(uint8_t index)
        {
            _list.RemoveItem(index);
        }
        void InputSelect::AddItem(Text *text)
        {
            _list.AddItem(text);
        }
        void InputSelect::AddItem(Text *text, Bitmap *bitmap)
        {
            _list.AddItem(text, bitmap);
        }
        void InputSelect::AddItem(Text *text, CheckBox *check)
        {
            _list.AddItem(text, check);
        }
        void InputSelect::SetPosition(Position position)
        {
            _position = position;
            _list.SetPosition({(uint16_t)(_position.x + 2), (uint16_t)(_position.y + 2), (uint16_t)(_position.width - 4), (uint16_t)(_position.height - 4)});
        }
        void InputSelect::SetItemHeight(uint8_t height)
        {
            _list.SetItemHeight(height);
        }
        void InputSelect::SetActiveItem(uint8_t active)
        {
            _list.SetActiveItem(active);
        }
        uint8_t InputSelect::GetActiveItem()
        {
            return _list.GetActiveItem();
        }
        void InputSelect::ChangeActiveByDirection(bool direction)
        {
            _list.ChangeActiveByDirection(direction);
        }
        void InputSelect::SetItemCheck(uint8_t index, bool check)
        {
            _list.SetItemCheck(index, check);
        }
        void InputSelect::SetAllItemCheck(bool check)
        {
            _list.SetAllItemCheck(check);
        }
        bool InputSelect::IsItemCheck(uint8_t index)
        {
            return _list.IsItemCheck(index);
        }
        uint8_t InputSelect::IsItemsCheck(uint8_t *indexes, bool check)
        {
            return _list.IsItemsCheck(indexes, check);
        }
        uint8_t InputSelect::GetSize()
        {
            return _list.GetSize();
        }
        void InputSelect::Visible(bool visible)
        {
            _isVisible = visible;
        }

    } // namespace gui

} // namespace qymos
