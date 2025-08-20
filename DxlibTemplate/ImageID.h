#pragma once
#include <type_traits>

enum class ImageID : int {
    MainChara = 0,
    Enemy = 1,
    Item = 2,
};

constexpr int to_i(ImageID id) noexcept { return static_cast<int>(id); }
