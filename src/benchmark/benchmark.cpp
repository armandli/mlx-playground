#include <cassert>
#include <vector>

#include <mlx/mlx.h>
#include <benchmark/benchmark.h>

namespace mx = mlx::core;
namespace s = std;

static void BM_transpose_gpu(benchmark::State& state){
  mx::set_default_device(mx::Device::gpu);
  mx::array m = mx::random::normal({1024, 1024}, mx::float32);
  for (auto _ : state){
    mx::array n = mx::transpose(m, {1, 0});
    n.eval();
  }
}
BENCHMARK(BM_transpose_gpu);

static void BM_transpose_cpu(benchmark::State& state){
  mx::set_default_device(mx::Device::cpu);
  mx::array m = mx::random::normal({1024, 1024}, mx::float32);
  for (auto _ : state){
    mx::array n = mx::transpose(m, {1, 0});
    n.eval();
  }
}
BENCHMARK(BM_transpose_cpu);

void naive_transpose(s::vector<float>& out, const s::vector<float>& in, int n, int m){
  assert(out.size() == in.size());
  for (int r = 0; r < n; ++r)
    for (int c = 0; c < m; ++c)
      out[r * m + c] = in[c * n + r];
}

static void BM_transpose_naive(benchmark::State& state){
  s::vector<float> m(1024 * 1024, 1.);
  s::vector<float> n(1024 * 1024, 0.);
  for (auto _ : state){
    naive_transpose(n, m, 1024, 1024);
  }
}
BENCHMARK(BM_transpose_naive);

BENCHMARK_MAIN();
