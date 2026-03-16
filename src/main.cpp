#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include "math_utils.h"

int main() {
  std::cout << "Welcome to Stratum C++ Project!" << '\n';

  int result1 = MathUtils::add(5, 3);
  std::cout << "5 + 3 = " << result1 << '\n';

  int result2 = MathUtils::multiply(5, 3);
  std::cout << "5 * 3 = " << result2 << '\n';
  uint32_t price = 42000;

  // to bytes
  std::array<uint8_t, 4> buf{};
  std::memcpy(buf.data(), &price, sizeof(price));
  std::cout << "Price in bytes: ";
  for (auto& byte : buf) {
    std::cout << std::hex << static_cast<int>(byte) << " ";
  }
  std::cout << std::dec << '\n'; // reset to decimal
  // back from bytes
  uint32_t recovered = -1;
  std::memcpy(&recovered, buf.data(), sizeof(recovered));
  std::cout << "Recovered price: " << recovered << '\n';
  return 0;
}
