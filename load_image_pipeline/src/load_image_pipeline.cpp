#include "load_image_pipeline.h"

#include <string>
#include <optional>
#include <variant>
#include <vector>
#include <memory>

#include "image.h"
#include "file.h"
#include "format_types.h"


bool starts_with(const std::string& str, const std::string& starts_with)
{
    return starts_with.size() <= str.size() &&
           std::equal(starts_with.cbegin(), starts_with.cend(), str.cbegin());
}


std::unique_ptr<Image> LoadImagePipeline::loadImageFromLocation(const std::string& location)
{
    std::optional<File> file = loadFileFromLocation(location);
    if (!file.has_value())
        return {};

    std::unique_ptr<ImageData> imageData = createImageDataFromFile(file.value());
    if (!imageData)
        return {};

    decodeImage(imageData);
    if (!imageData)
        return {};

    uncompressImage(imageData);
    if (!imageData)
        return {};

    return std::make_unique<Image>(std::move(imageData->data));
}

std::optional<File> LoadImagePipeline::loadFileFromLocation(const std::string& location)
{
    if (starts_with(location, "file://"))
        return loadFileFromPath(location);
    else if (starts_with(location, "http://") || starts_with(location, "https://"))
        return loadFileFromUrl(location);
    else if (starts_with(location, "bundle://"))
        return loadFileFromBundle(location);
    else
        return {};
}

std::optional<File> LoadImagePipeline::loadFileFromPath(const std::string& location)
{
    return File();
}

std::optional<File> LoadImagePipeline::loadFileFromUrl(const std::string& location)
{
    return File();
}

std::optional<File> LoadImagePipeline::loadFileFromBundle(const std::string& location)
{
    return File();
}

std::unique_ptr<ImageData> LoadImagePipeline::createImageDataFromFile(const File& file)
{
    FormatInfo info = JPEGFormatInfo{};
    FormatData data(2000, 0);
    return std::make_unique<ImageData>(ImageData(std::move(info), std::move(data)));
}

void LoadImagePipeline::decodeImage(std::unique_ptr<ImageData>& imageData)
{
    // Do nothing
}

void LoadImagePipeline::uncompressImage(std::unique_ptr<ImageData>& imageData)
{
    // Do nothing
}