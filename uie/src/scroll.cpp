#include "../include/scroll.hpp"

namespace qymos
{
    namespace gui
    {
        void Scroll::RenderVertical(DisplayBuffer *buffer)
        {
            _line.SetPosition({(uint16_t)(_position.x + 1), _position.y, 1, _position.height});
            _line.Render(buffer);
            _bar.SetFill(true);
            uint8_t height = _position.height / _count;
            if (_position.height % _count)
                height = _position.height / (_count + 1);
            _bar.SetPosition({_position.x, (uint16_t)(_position.y + height * _progress), 3, height});
            _bar.Render(buffer);
        }
        void Scroll::RenderHorizontal(DisplayBuffer *buffer)
        {
            _line.SetPosition({_position.x, (uint16_t)(_position.y + 1), _position.width, 1});
            _line.Render(buffer);
            _bar.SetFill(true);
            uint8_t width = _position.width / _count;
            if (_position.width % _count)
                width = _position.width / (_count + 1);
            _bar.SetPosition({(uint16_t)(_position.x + width * _progress), _position.y, width, 3});
            _bar.Render(buffer);
        }
        void Scroll::Render(DisplayBuffer *buffer)
        {
            if (_orientation == ORIENTATION_VERTICAL)
                RenderVertical(buffer);
            else
                RenderHorizontal(buffer);
        }
        void Scroll::SetCount(uint8_t count)
        {
            _count = count;
        }
        void Scroll::SetProgress(uint8_t progress)
        {
            _progress = progress;
        }

        void Scroll::SetOrientation(Orientation orientation)
        {
            _orientation = orientation;
        }

    } // namespace qui
} // namespace qymos
