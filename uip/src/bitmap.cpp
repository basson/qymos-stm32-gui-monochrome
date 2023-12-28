#include "../include/bitmap.hpp"

namespace qymos
{
    namespace gui
    {
        void Bitmap::Render(DisplayBuffer *buffer)
        {
            return Render(buffer, 0, 0);
        }
        void Bitmap::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
        {
            if (!_visible)
                return;

            if (width > buffer->width || width == 0)
                width = buffer->width;
            if (height > buffer->height || height == 0)
                height = buffer->height;

            uint16_t byte = 0;
            uint8_t bit = 0;

            uint8_t value = 0;
            int x0, y0;
            int counter = 0;
            const uint8_t *pdata = (const uint8_t *)_image->data;
            // rows
            for (y0 = 0; y0 < _image->height; y0++)
            {
                // columns
                for (x0 = 0; x0 < _image->width; x0++)
                {
                    // load new data
                    if (counter == 0)
                    {
                        value = *pdata++;
                        counter = _image->dataSize;
                    }

                    counter--;

                    // set pixel
                    if ((value & 0x80) != 0)
                    {
                        if ((_position.x + x0 >= 0) and
                            (_position.x + x0 < width) and
                            (_position.y + y0 >= 0) and
                            (_position.y + y0 < height))
                        {
                            byte = (((_position.y + y0) / 8) * 128) + (_position.x + x0);
                            bit = (_position.y + y0) % 8;
                            if (!_invert)
                                buffer->data[byte] = buffer->data[byte] | (1 << bit);
                            else
                                buffer->data[byte] = buffer->data[byte] & ~(1 << bit);
                        }
                    }

                    value = value << 1;
                }
            }
        }
        void Bitmap::SetImage(const tImage *image)
        {
            _image = image;
            _position.width = _image->width;
            _position.height = _image->height;
        }
        void Bitmap::SetInvert(bool invert)
        {
            _invert = invert;
        }
        void Bitmap::SetPosition(Position position)
        {
            _position.x = position.x;
            _position.y = position.y;
        }
        void Bitmap::Visible(bool visible)
        {
            _visible = visible;
        }
    } // namespace qui
} // namespace qymos
