#pragma once

#include "UnrealVoxelSim/Events/Api/DispatchError.h"

#include <cstddef>
#include <expected>

namespace UnrealVoxelSim::Events::Api
{

class IEventPump
{
  public:
    virtual ~IEventPump() = default;

    [[nodiscard]] virtual bool HasPending() const noexcept = 0;
    [[nodiscard]] virtual std::size_t PendingCount() const noexcept = 0;
    [[nodiscard]] virtual std::expected<std::size_t, DispatchError> DispatchPending() = 0;
};

} // namespace UnrealVoxelSim::Events::Api
