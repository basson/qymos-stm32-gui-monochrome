#include "../../../include/gui/uie/message.hpp"

namespace qymos
{
    namespace gui
    {
        void Message::Render(DisplayBuffer *buffer)
        {
            Render(buffer, 0, 0);
        }
        void Message::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
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

            _textMessage->SetPosition({(uint16_t)(_position.x + (_position.width / 2 - _textMessage->GetWidth() / 2)), (uint16_t)(_position.y + (_position.height / 2 - _textMessage->GetHeight() / 2)),0,0});
            _textMessage->Render(buffer, _position.x + _position.width, _position.y + _position.height);
        }
        void Message::SetMessageText(Text *text)
        {
            _textMessage = text;
        }
        void Message::Visible(bool visible)
        {
            _isVisible = visible;
        }

    } // namespace gui

} // namespace qymos
