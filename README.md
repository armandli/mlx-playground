# mlx_playground

Experiments with the [MLX](https://github.com/ml-explore/mlx) library on Mac, written in C++.

## Prerequisites

- macOS with Apple Silicon
- CMake 3.20+
- MLX installed via Homebrew: `brew install mlx`

## Build

```bash
cmake -B build
cmake --build build -j$(sysctl -n hw.logicalcpu)
```

If MLX is not picked up automatically, provide its CMake prefix:

```bash
cmake -B build -DCMAKE_PREFIX_PATH=/opt/homebrew
cmake --build build -j$(sysctl -n hw.logicalcpu)
```

All experiments are built with the single `cmake --build build` command.
Binaries land in `build/src/<experiment_name>/`.

## Adding an experiment

Create a subdirectory under `src/` with a `CMakeLists.txt`:

```
src/
  my_experiment/
    CMakeLists.txt
    main.cpp
```

Minimal `CMakeLists.txt`:

```cmake
add_executable(my_experiment main.cpp)
target_link_libraries(my_experiment PRIVATE mlx)
```

Headers from any experiment or shared library under `src/` can be included with angle brackets:

```cpp
#include <my_experiment/my_header.h>
#include <mlx/mlx.h>
```

## Structure

```
src/
  hello_mlx/     # minimal MLX sanity check
```
