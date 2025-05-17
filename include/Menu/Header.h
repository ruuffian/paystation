#pragma once

namespace Menu {
/** Enter the Command pattern. */
class Header {
public:
  virtual void render() = 0;
  virtual ~Header() = default;
};
} // namespace Menu
