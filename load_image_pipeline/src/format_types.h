#include <variant>

#pragma once

/**
 * Format Information specific to the JPEG(or JFIF) image format.
 */
struct JPEGFormatInfo
{
    uint32_t huffmanTable{};
    int imageWidth{};
};

/**
 * Format Information specific to the TIFF image format.
 */
struct TIFFFormatInfo
{
    uint32_t bitsPerPixel{};
    uint32_t gamma{};
};

using FormatInfo = std::variant<JPEGFormatInfo, TIFFFormatInfo>;
using FormatData = std::vector<uint32_t>;

/**
 * DataType containing format info and format data
 * used for further decoding and decompression.
 */
struct ImageData
{
    ImageData(FormatInfo&& info, FormatData&& data)
            : info(std::move(info))
              , data(std::move(data))
    {}

    FormatInfo info;
    FormatData data;
};