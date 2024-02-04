#include "../../../include/gui/uie/tab_layout.hpp"

namespace qymos
{
    namespace gui
    {
        void TabLayout::AddTab(Text *title, TabPage *page)
        {
            if (_lastIndex >= 10)
                return;
            _tabBar.AddTab(title);
            Position position = {_position.x, (uint16_t)(_position.y + _tabBarHeight - 1), _position.width, (uint16_t)(_position.height - _tabBarHeight + 1)};
            _element[_lastIndex] = page;
            _element[_lastIndex]->SetPosition(position);

            _lastIndex++;
        }
        void TabLayout::RemoveTab(uint8_t index)
        {
        }

        void TabLayout::Render(DisplayBuffer *buffer)
        {
            _tabBar.SetActiveTab(_active);
            _tabBar.Render(buffer);
            _element[_active]->Render(buffer);
        }
        void TabLayout::SetTabBarHeight(uint8_t _height)
        {
            _tabBarHeight = _height;
            Position position = {_position.x, _position.y, _position.width, _tabBarHeight};
            _tabBar.SetPosition(position);
        }
        void TabLayout::SetActiveTab(uint8_t active)
        {
            _active = active;
        }
        uint8_t TabLayout::GetActiveTab(TabPage *page)
        {
            return _active;
        }
        uint8_t TabLayout::GetActiveTab()
        {
            return _active;
        }
        uint8_t TabLayout::GetSize()
        {
            return (_lastIndex - 1);
        }
    } // namespace qui
} // namespace qymos
