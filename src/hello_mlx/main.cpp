#include <mlx/mlx.h>
#include <iostream>

namespace mx = mlx::core;

int main() {
    auto a = mx::array({1.0f, 2.0f, 3.0f});
    auto b = mx::array({4.0f, 5.0f, 6.0f});
    auto c = mx::add(a, b);
    mx::eval(c);
    std::cout << c << std::endl;
}
