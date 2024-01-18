#include "../include/radio_box.hpp"

namespace qymos
{
    namespace gui
    {
        void RadioBox::Render(DisplayBuffer *buffer)
        {
            Render(buffer, 0, 0);
        }
        void RadioBox::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
        {
            if (!_visible)
                return;
            if(_isCheck)
                _bitmapCheck->Render(buffer);
            else
                _bitmapUncheck->Render(buffer);
        }
        void RadioBox::SetImageCheck(Bitmap *bitmap)
        {
            _bitmapCheck = bitmap;
        }
        void RadioBox::SetImageUncheck(Bitmap *bitmap)
        {
            _bitmapUncheck = bitmap;
        }
        void RadioBox::SetPosition(Position position)
        {
            _position = position;
            _bitmapCheck->SetPosition({(uint16_t)(position.x + (position.width - _bitmapCheck->GetPosition().width)/2), (uint16_t)(position.y + (position.height - _bitmapCheck->GetPosition().height)/2), 0, 0});
            _bitmapUncheck->SetPosition({(uint16_t)(position.x + (position.width - _bitmapUncheck->GetPosition().width)/2), (uint16_t)(position.y + (position.height - _bitmapUncheck->GetPosition().height)/2), 0, 0});
        }
        void RadioBox::SetCheck(bool check)
        {
            _isCheck = check;
        }
        bool RadioBox::IsCheck()
        {
            return _isCheck;
        }
        void RadioBox::SetInvert(bool invert)
        {
            _invert = invert;
            _bitmapCheck->SetInvert(_invert);
            _bitmapUncheck->SetInvert(_invert);
        }
        void RadioBox::Visible(bool visible)
        {
            _visible = visible;
        }
    } // namespace gui

} // namespace qymos
