#include "../include/text.hpp"

#include <string.h>
// #include "HellenicaRus8px.h"
#include "utf8char.hpp"

namespace qymos
{
    namespace gui
    {
        void Text::Render(DisplayBuffer *buffer)
        {
            return Render(buffer, 0, 0);
        }
        void Text::Render(DisplayBuffer *buffer, uint16_t width, uint16_t height)
        {
            if (!_visible)
                return;

            if (width > buffer->width || width == 0)
                width = buffer->width;
            if (height > buffer->height || height == 0)
                height = buffer->height;

            int len = strlen(_text);
            int index = 0;
            int nextIndex;
            int code = 0;
            uint16_t byte = 0;
            uint8_t bit = 0;

            uint8_t widthNextChar = 0;

            while (index < len)
            {
                if (Utf8Char::GetCharCode(_text, index, &code, &nextIndex) != 0)
                {
                    const tChar *ch = Utf8Char::FindCharByCode(code, _font);
                    uint8_t value = 0;
                    int x0, y0;
                    int counter = 0;
                    const uint8_t *pdata = (const uint8_t *)ch->image->data;
                    // rows
                    for (y0 = 0; y0 < ch->image->height; y0++)
                    {
                        // columns
                        for (x0 = 0; x0 < ch->image->width; x0++)
                        {
                            // load new data
                            if (counter == 0)
                            {
                                value = *pdata++;
                                counter = ch->image->dataSize;
                            }

                            counter--;

                            // set pixel
                            if ((value & 0x80) != 0)
                            {
                                if ((_position.x + widthNextChar + x0 >= 0) &&
                                    (_position.x + widthNextChar + x0 < width) &&
                                    (_position.y + y0 >= 0) &&
                                    (_position.y + y0 < height))
                                {
                                    byte = (((_position.y + y0) / 8) * 128) + (_position.x + widthNextChar + x0);
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
                    widthNextChar += ch->image->width;
                }

                index = nextIndex;

                if (nextIndex < 0)
                {
                    break;
                }
            }
        }

        uint16_t Text::GetWidth()
        {
            return _position.width;
        }
        uint16_t Text::GetHeight()
        {
            return _position.height;
        }

        void Text::GetBounds()
        {
            int len = strlen(_text);
            int index = 0;
            int nextIndex;
            int code = 0;

            uint8_t widthNextChar = 0;
            uint8_t maxHeight = 0;

            while (index < len)
            {
                if (Utf8Char::GetCharCode(_text, index, &code, &nextIndex) != 0)
                {
                    const tChar *ch = Utf8Char::FindCharByCode(code, _font);
                    widthNextChar += ch->image->width;
                    if (maxHeight < ch->image->height)
                        maxHeight = ch->image->height;
                }
                index = nextIndex;

                if (nextIndex < 0)
                {
                    break;
                }
            }
            _position.width = widthNextChar;
            _position.height = maxHeight;
        }

        void Text::SetFont(const tFont *font)
        {
            _font = font;
        }

        void Text::SetText(char *text)
        {
            _isNeedRender = true;
            _text = text;
            GetBounds();
        }
        void Text::SetInvert(bool invert)
        {
            _invert = invert;
        }
        void Text::SetPosition(Position position)
        {
            _position.x = position.x;
            _position.y = position.y;
        }
        void Text::Visible(bool visible)
        {
            _visible = visible;
        }
    } // namespace qui
} // namespace qymos
