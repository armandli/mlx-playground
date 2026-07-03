add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark PRIVATE mlx)
target_link_libraries(benchmark PRIVATE benchmark::benchmark_main)
