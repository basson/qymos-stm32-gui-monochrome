#include "../../../include/gui/uie/tab_bar.hpp"

namespace qymos
{
    namespace gui
    {
        void TabBar::AddTab(Text *text)
        {
            if (_lastIndex >= 10)
                return;
            _element[_lastIndex] = new Tab();
            _element[_lastIndex]->SetText(text);
            _lastIndex++;
        }
        void TabBar::RemoveTab(uint8_t index)
        {
        }
        void TabBar::Render(DisplayBuffer *buffer)
        {
            uint8_t width = _position.width / _lastIndex;
            uint8_t mod = _position.width % _lastIndex;

            Position position = {_position.x, _position.y, width, _position.height};

            for (uint8_t i = 0; i < _lastIndex; i++)
            {
                _element[i]->Active(false);
                if (_active == i)
                    _element[i]->Active(true);
                position.x = _position.x + width * i;
                if (i > 0)
                    position.x -= i;
                if (i == _lastIndex - 1)
                    position.width += mod + i;

                _element[i]->SetPosition(position);
                _element[i]->Render(buffer);
            }
        }
        void TabBar::SetActiveTab(uint8_t active)
        {
            _active = active;
        }

    } // namespace qui
} // namespace qymos
