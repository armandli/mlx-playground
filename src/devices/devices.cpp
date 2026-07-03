#include <mlx/mlx.h>

#include <print>

namespace mx = mlx::core;
namespace s = std;

int main(){
  s::print("number of CPU device: {0}\n", mx::device_count(mx::Device::DeviceType::cpu));
  s::print("number of GPU device: {0}\n", mx::device_count(mx::Device::DeviceType::gpu));

  const mx::Device& dev = mx::default_device();

  s::print("is default device cpu? {0}\n", dev == mx::Device::cpu);
  s::print("is default device gpu? {0}\n", dev == mx::Device::gpu);
}
