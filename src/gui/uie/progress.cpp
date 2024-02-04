#include "../../../include/gui/uie/progress.hpp"

namespace qymos
{
    namespace gui
    {
        void Progress::RenderVertical(DisplayBuffer *buffer)
        {
            _border.SetPosition({_position.x, _position.y, _position.width, _position.height});
            _border.Render(buffer);
            _bar.SetFill(true);
            uint8_t height = (_position.height - 4) / _count;
            if (_progress == _count)
                height = _position.height - 4;
            else
                height = height * _progress;

            if (_position.width < 5)
                _bar.SetPosition({_position.x, _position.y, _position.width, (uint16_t)(height + 4)});
            else
                _bar.SetPosition({(uint16_t)(_position.x + 2), (uint16_t)(_position.y + 2), (uint16_t)(_position.width - 4), height});
            _bar.Render(buffer);
        }
        void Progress::RenderHorizontal(DisplayBuffer *buffer)
        {
            _border.SetPosition({_position.x, _position.y, _position.width, _position.height});
            _border.Render(buffer);
            _bar.SetFill(true);
            uint8_t width = (_position.width - 4) / _count;
            if (_progress == _count)
                width = _position.width - 4;
            else
                width = width * _progress;

            if (_position.height < 5)
                _bar.SetPosition({_position.x, _position.y, (uint16_t)(width + 4), _position.height});
            else
                _bar.SetPosition({(uint16_t)(_position.x + 2), (uint16_t)(_position.y + 2), width, (uint16_t)(_position.height - 4)});

            _bar.Render(buffer);
        }
        void Progress::Render(DisplayBuffer *buffer)
        {
            if (_orientation == ORIENTATION_HORIZONTAl)
                RenderHorizontal(buffer);
            else
                RenderVertical(buffer);
        }
        void Progress::SetCount(uint8_t count)
        {
            _count = count;
        }
        void Progress::SetProgress(uint8_t progress)
        {
            if (progress > _count)
                progress = _count;
            _progress = progress;
        }

        void Progress::SetOrientation(Orientation orientation)
        {
            _orientation = orientation;
        }
    } // namespace qui
} // namespace qymos
