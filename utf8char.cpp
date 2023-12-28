#include "utf8char.hpp"

namespace qymos
{
    namespace gui
    {
        int Utf8Char::GetCharCode(const char *str, int start, int *resultCode, int *nextIndex)
        {
            int len = 0;
            int index = 0;
            *resultCode = 0;

            while (*(str + index) != 0)
            {
                len++;
                index++;
            }

            unsigned char c;
            unsigned int code = 0;
            int result = 0;
            int skip = 0;

            *resultCode = 0;
            *nextIndex = -1;

            if (start >= 0 && start < len)
            {
                index = start;

                while (index < len)
                {
                    c = *(str + index);
                    index++;

                    // msb
                    if (skip == 0)
                    {
                        // if range 0x00010000-0x001fffff
                        if ((c & 0xf8) == 0xf0)
                        {
                            skip = 3;
                            code = c;
                        }
                        // if range 0x00000800-0x0000ffff
                        else if ((c & 0xf0) == 0xe0)
                        {
                            skip = 2;
                            code = c;
                        }
                        // if range 0x00000080-0x000007ff
                        else if ((c & 0xe0) == 0xc0)
                        {
                            skip = 1;
                            code = c;
                        }
                        // if range 0x00-0x7f
                        else // if ((c & 0x80) == 0x00)
                        {
                            skip = 0;
                            code = c;
                        }
                    }
                    else
                    { // not msb
                        code = code << 8;
                        code |= c;
                        skip--;
                    }

                    if (skip == 0)
                    {
                        // completed
                        *resultCode = code;
                        *nextIndex = index;
                        result = 1;
                        break;
                    }
                }
            }

            return (result);
        }

        const tChar *Utf8Char::findCharByCode(int code, const tFont *font)
        {
            int count = font->length;
            int first = 0;
            int last = count - 1;
            int mid = 0;

            if (count > 0)
            {
                if ((code >= font->chars[0].code) && (code <= font->chars[count - 1].code))
                {
                    while (last >= first)
                    {
                        mid = first + ((last - first) / 2);

                        if (font->chars[mid].code < code)
                        {
                            first = mid + 1;
                        }
                        else
                        {
                            if (font->chars[mid].code > code)
                            {
                                last = mid - 1;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }

                    if (font->chars[mid].code == code)
                    {
                        return (&font->chars[mid]);
                    }
                }
            }

            return (0);
        }
    } // namespace qui
} // namespace qymos
