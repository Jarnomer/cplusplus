#pragma once

#include <cstdint>

#include "Data.hpp"

class Serializer {
public:
  Serializer(void) = delete;
  Serializer(const Serializer &other) = delete;
  Serializer &operator=(const Serializer &other) = delete;
  ~Serializer(void) = delete;

  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
