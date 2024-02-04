#include "gui/uie/input_dialog.hpp"

namespace qymos
{
    namespace gui
    {
        void InputDialog::Render(DisplayBuffer *buffer)
        {
            Render(buffer, 0, 0);
        }
        void InputDialog::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
        {
            if (!_isVisible)
                return;

            Position position;

            _rect.SetPosition(_position);
            _rect.SetFill(true);
            _rect.SetInvert(true);
            _rect.Render(buffer, width, height);

            _border.SetPosition({(uint16_t)(_position.x + 1), (uint16_t)(_position.y + 1), (uint16_t)(_position.width - 2), (uint16_t)(_position.height - 2)});
            _border.SetBorder(1);
            _border.SetFill(false);
            _border.Render(buffer, width, height);

            if (_result)
            {
                _selected.SetPosition({uint16_t(_position.x + 4), uint16_t(_position.y + _position.height - _textOk->GetHeight() - 6), uint16_t(_textOk->GetWidth() + 2), uint16_t(_textOk->GetHeight() + 2)});
                _textOk->SetInvert(true);
                _textCancel->SetInvert(false);
            }
            else
            {
                _selected.SetPosition({uint16_t(_position.x + _position.width - 6 - _textCancel->GetWidth()), uint16_t(_position.y + _position.height - _textCancel->GetHeight() - 6), uint16_t(_textCancel->GetWidth() + 2),uint16_t(_textCancel->GetHeight() + 2)});
                _textOk->SetInvert(false);
                _textCancel->SetInvert(true);
            }

            _selected.SetFill(true);
            _selected.Render(buffer, width, height);

            position = _textMessage->GetPosition();
            _textMessage->SetPosition({(uint16_t)(_position.x + (_position.width / 2 - position.width / 2)), (uint16_t)((_position.y + 3) + ((_position.height - _textCancel->GetHeight() - 7) / 2) - position.height / 2), 0, 0});
            _textMessage->Render(buffer, _position.x + _position.width, _position.y + _position.height);

            _textOk->SetPosition({uint16_t(_position.x + 5), uint16_t(_position.y + _position.height - 5 - _textOk->GetHeight()), 0, 0});
            _textOk->Render(buffer, _position.x + _position.width, _position.y + _position.height);

            position = _textCancel->GetPosition();
            _textCancel->SetPosition({uint16_t(_position.x + _position.width - 5 - position.width), uint16_t(_position.y + _position.height - 5 - _textCancel->GetHeight()), 0, 0});
            _textCancel->Render(buffer, _position.x + _position.width, _position.y + _position.height);
        }
        void InputDialog::SetMessageText(Text *text)
        {
            _textMessage = text;
        }
        void InputDialog::SetCancelText(Text *text)
        {
            _textCancel = text;
        }
        void InputDialog::SetOkText(Text *text)
        {
            _textOk = text;
        }
        void InputDialog::SetVariant(Variant variant)
        {
            _result = (bool)variant;
        }
        void InputDialog::Toggle()
        {
            _result = !_result;
        }
        bool InputDialog::GetResult()
        {
            return _result;
        }
        void InputDialog::Visible(bool visible)
        {
            _isVisible = visible;
        }
    } // namespace gui

} // namespace qymos
