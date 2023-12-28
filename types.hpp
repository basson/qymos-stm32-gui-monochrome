#pragma once
#include "stdint.h"

namespace qymos
{
    namespace gui
    {
        /**
         * @brief Orinetation display draw
         *
         */
        enum Orientation
        {
            ORIENTATION_HORIZONTAl,
            ORIENTATION_VERTICAL
        };

        /**
         * @brief Postion x,y,w,h
         *
         */
        typedef struct
        {
            uint16_t x;
            uint16_t y;
            uint16_t width;
            uint16_t height;
        } Position;

        /**
         * @brief Display buffer struct
         *
         */
        typedef struct
        {
            uint8_t *data;   ///< byte array buffer
            uint16_t size;   ///< size array buffer
            uint16_t width;  ///< width pixels buffer
            uint16_t height; ///< height pixels buffer
        } DisplayBuffer;

        /**
         * @brief Structure of one bitmap data
         *
         */
        typedef struct
        {
            const uint8_t *data; ///< byte array image data
            uint16_t width;      ///< witdth in pixels
            uint16_t height;     ///< width in height
            uint8_t dataSize;    ///< data array element size Uint8-t / uint16-t etc
            uint8_t dataLenght;  ///< lenght of data array
        } tImage;

        /**
         * @brief Structure of animation bitmap data
         *
         */
        typedef struct
        {
            const tImage *frame; ///< Массив с изображениями
            uint8_t frameLenght; ///< Количество кадров
        } tAnimationImage;

        /**
         * @brief Structure from char image
         *
         */
        typedef struct
        {
            long int code;       ///< Symbol code in UTF-8 encoding
            const tImage *image; ///< Symbol graphics data array
        } tChar;

        /**
         * @brief Structure from fonts
         *
         */
        typedef struct
        {
            int length;         ///< Lenngh symbols in fonts
            const tChar *chars; ////< Symbol data array
        } tFont;

    } // namespace qui
} // namespace qymos
