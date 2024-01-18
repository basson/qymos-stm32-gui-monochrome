#include "../include/list_item.hpp"

namespace qymos
{
    namespace gui
    {

        void ListItem::Render(DisplayBuffer *buffer)
        {
            return Render(buffer, 0, 0);
        }
        void ListItem::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
        {

            Position position = {0, 0, 0, 0};
            uint8_t iconMargin = 0;
            if (_active)
            {
                _rect.SetPosition({_position.x, _position.y, _position.width, _position.height});
                _rect.SetFill(true);
                _rect.Render(buffer, width, height);
            }

            if (_icon != nullptr)
            {
                position = _icon->GetPosition();
                iconMargin = position.width + 3;
                _icon->SetPosition({(uint16_t)(_position.x + 3), (uint16_t)(_position.y + (_position.height / 2 - position.height / 2)), 0, 0});
                _icon->SetInvert(_active);
                _icon->Render(buffer, width, height);
            }
            else if (_check != nullptr)
            {
                position = _check->GetPosition();
                iconMargin = position.width + 3;
                _check->SetCheck(_isChecked);
                _check->SetPosition({(uint16_t)(_position.x + 3), (uint16_t)(_position.y + (_position.height / 2 - position.height / 2)), position.width, position.height});
                _check->SetInvert(_active);
                _check->Render(buffer, width, height);
            }

            position = _text->GetPosition();
            _text->SetPosition({(uint16_t)(_position.x + iconMargin + 3), (uint16_t)(_position.y + (_position.height / 2 - position.height / 2)), 0, 0});
            _text->SetInvert(_active);
            _text->Render(buffer, width, height);
        }
        void ListItem::SetText(Text *text)
        {
            _text = text;
        }
        void ListItem::SetIcon(Bitmap *bitmap)
        {
            _icon = bitmap;
        }
        void ListItem::SetCheckBox(CheckBox *check)
        {
            _check = check;
        }
        void ListItem::SetCheckBoxState(bool state )
        {
            _isChecked = state;
        }
        bool ListItem::GetCheckBoxState()
        {
            return _isChecked;
        }
        void ListItem::Active(bool active)
        {
            _active = active;
        }

    } // namespace qui
} // namespace qymos
