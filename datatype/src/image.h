#pragma once

struct Image
{
    explicit Image(std::vector<uint32_t>&& data)
        : data(std::move(data))
    {}

    std::vector<uint32_t> data{};
};
