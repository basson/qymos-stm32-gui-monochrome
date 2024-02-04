#include "../../../include/gui/uie/checkbox.hpp"

namespace qymos
{
    namespace gui
    {
        void CheckBox::Render(DisplayBuffer *buffer)
        {
            return Render(buffer, 0, 0);
        }
        void CheckBox::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
        {
            if (!_visible)
                return;
            if (_isCheck)
                _bitmapCheck->Render(buffer);
            else
                _bitmapUncheck->Render(buffer);
        }
        void CheckBox::SetImageCheck(Bitmap *bitmap)
        {
            _bitmapCheck = bitmap;
        }
        void CheckBox::SetImageUncheck(Bitmap *bitmap)
        {
            _bitmapUncheck = bitmap;
        }
        void CheckBox::SetPosition(Position position)
        {
            _position = position;
            _bitmapCheck->SetPosition({(uint16_t)(position.x + (position.width - _bitmapCheck->GetPosition().width) / 2), (uint16_t)(position.y + (position.height - _bitmapCheck->GetPosition().height) / 2), 0, 0});
            _bitmapUncheck->SetPosition({(uint16_t)(position.x + (position.width - _bitmapUncheck->GetPosition().width) / 2), (uint16_t)(position.y + (position.height - _bitmapUncheck->GetPosition().height) / 2), 0, 0});
        }
        void CheckBox::SetCheck(bool check)
        {
            _isCheck = check;
        }
        bool CheckBox::IsCheck()
        {
            return _isCheck;
        }
        void CheckBox::SetInvert(bool invert)
        {
            _invert = invert;
            _bitmapCheck->SetInvert(_invert);
            _bitmapUncheck->SetInvert(_invert);
        }
        void CheckBox::Visible(bool visible)
        {
            _visible = visible;
        };
    } // namespace qui
} // namespace qymos
