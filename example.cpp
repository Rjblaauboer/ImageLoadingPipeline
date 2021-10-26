
#include <string>
#include <optional>
#include <variant>
#include <vector>

#include "format_types.h"
#include "image.h"
#include "load_image_pipeline.h"

int main()
{
    printf("Running example\n");
    std::unique_ptr<Image> image = LoadImagePipeline::loadImageFromLocation("file://my-path-to-file");
}