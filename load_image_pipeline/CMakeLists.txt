add_library(image_loading_pipeline
        src/format_types.h
        src/load_image_pipeline.cpp
        src/load_image_pipeline.h
)

target_include_directories(
        image_loading_pipeline
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(
        image_loading_pipeline
        PUBLIC
            datatype
)