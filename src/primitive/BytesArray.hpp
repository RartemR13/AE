#pragma once

#include <cstring>
#include <initializer_list>

namespace ae {
namespace primitive {

template <uint8_t CountElements>
requires requires { CountElements > 0; }
class BytesArray {
 public:
  BytesArray() = default;

  ~BytesArray() = default;

  BytesArray(const BytesArray<CountElements>& other) {
    std::memcpy(storage_, &other, CountElements);
  }

  BytesArray(BytesArray<CountElements>&& other) = delete;

  BytesArray<CountElements>& operator=(const BytesArray<CountElements>& other) {
    if (this == &other) {
      return *this;
    }

    std::memcpy(storage_, &other, CountElements);
    return *this;
  }

  BytesArray<CountElements>& operator=(BytesArray<CountElements>&& other) =
      delete;

  BytesArray(std::initializer_list<uint8_t> initializer_list) {
    if (initializer_list.size() != CountElements) {
      throw std::invalid_argument(
          "BytesArray, initilize_list.size() != CountElements.");
    }

    std::memcpy(&storage_, std::data(initializer_list), CountElements);
  }

  bool operator==(const BytesArray<CountElements>& other) {
    return std::memcmp(&storage_, &other, CountElements) == 0;
  }

 private:
  uint8_t storage_[CountElements]{};
};

}  // namespace primitive
}  // namespace ae