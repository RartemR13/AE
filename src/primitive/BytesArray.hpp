#pragma once

template<uint8_t CountElements>
requires requires {CountElements > 0; }
class BytesArray {
public:
    BytesArray() = default;
private:
    uint8_t storage_[CountElements]{};
};