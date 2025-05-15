#pragma once

namespace Menu {
/** Enter the Command pattern. */
class Header {
public:
  virtual void print() = 0;
  virtual ~Header() = default;
};
} // namespace Menu
