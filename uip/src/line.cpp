#include "../include/line.hpp"

namespace qymos
{
    namespace gui
    {
        void Line::Render(DisplayBuffer *buffer)
        {
            return Render(buffer, 0, 0);
        }
        void Line::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
        {
            if (!_visible)
                return;

            if (width > _position.width || width == 0)
                width = _position.width;
            if (height > _position.height || height == 0)
                height = _position.height;

            if (width > buffer->width)
                width = buffer->width;
            if (height > buffer->height)
                height = buffer->height;

            uint8_t byteY = _position.y / 8;
            uint8_t bitY = _position.y % 8;
            for (uint8_t h = 0; h < height; h++)
            {
                byteY = (_position.y + h) / 8;
                bitY = (_position.y + h) % 8;
                for (uint8_t w = 0; w < width; w++)
                {
                    if (byteY * 128 + _position.x + w <= buffer->size)
                    {
                        if (!_invert)
                            buffer->data[byteY * 128 + _position.x + w] = (buffer->data[byteY * 128 + _position.x + w] | (1 << bitY));
                        else
                            buffer->data[byteY * 128 + _position.x + w] = (buffer->data[byteY * 128 + _position.x + w] & ~(1 << bitY));
                    }
                }
            }
        }
        void Line::SetPosition(Position position)
        {
            _position.x = position.x;
            _position.y = position.y;
            if (position.width != 0)
                _position.width = position.width;
            if (position.height != 0)
                _position.height = position.height;
        }
        void Line::SetInvert(bool invert)
        {
            _invert = invert;
        }
        void Line::Visible(bool visible)
        {
            _visible = visible;
        }
    } // namespace qui
} // namespace qymos
