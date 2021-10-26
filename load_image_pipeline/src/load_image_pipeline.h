#pragma once

#include <optional>
#include <memory>

struct Image;
struct File;
struct ImageData;


class LoadImagePipeline
{
public:

    /**
     * Given a file location will return an image
     *
     * Note:        Supports locations for local files (file://), URLs (http:// OR https://) and bundles (bundle://)
     * Also note:   Returns nullptr if location is invalid or file could not be read as image.
     *
     * @param location  Location of file to be loaded as image
     * @return          Pointer to image
     */
    static std::unique_ptr<Image> loadImageFromLocation(const std::string& location);

private:

    /**
     * Load local file from location.
     * Note: Location is assumed to start with 'file://'
     *
     * @param location  Location of local file to load
     * @return          File if load succeeded, otherwise std::optional without value.
     */
    static std::optional<File> loadFileFromLocation(const std::string& location);

    /**
     * Load local file from location.
     * Note: Location is assumed to start with 'file://'
     *
     * @param location  Location of local file to load
     * @return          File if load succeeded, otherwise std::optional without value.
     */
    static std::optional<File> loadFileFromPath(const std::string& location);

    /**
     * Load file from url.
     * Note: Location is assumed to start with 'http://' OR 'https://'
     *
     * @param location  Location of file to load
     * @return          File if load succeeded, otherwise std::optional without value.
     */
    static std::optional<File> loadFileFromUrl(const std::string& location);

    /**
     * Load bundle file from location.
     * Note: Location is assumed to start with 'bundle://'
     *
     * @param location  Location of bundle file to load
     * @return          File if load succeeded, otherwise std::optional without value.
     */
    static std::optional<File> loadFileFromBundle(const std::string& location);

    /**
     * Create ImageData (containing format info and data) given a file.
     * Will parse the file header to determine image format and will populate the FormatInfo accordingly.
     *
     * @param file  Image file to process
     * @return
     */
    static std::unique_ptr<ImageData> createImageDataFromFile(const File& file);

    /**
     * Decode the image data given the information in the format info.
     *
     * @param imageData     ImageData to decode.
     */
    static void decodeImage(std::unique_ptr<ImageData>& imageData);

    /**
     * Uncompress the image data given the information in the format info.
     *
     * @param imageData     ImageData to uncompress.
     */
    static void uncompressImage(std::unique_ptr<ImageData>& imageData);
};


