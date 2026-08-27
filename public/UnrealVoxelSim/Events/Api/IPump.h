#pragma once

#include "UnrealVoxelSim/Events/Api/DispatchError.h"

#include <cstddef>
#include <expected>

namespace UnrealVoxelSim::Events::Api
{
	class IPump
	{
	public:
		virtual ~IPump() = default;

		[[nodiscard]] virtual bool HasPending() const noexcept = 0;
		[[nodiscard]] virtual std::size_t PendingCount() const noexcept = 0;
		[[nodiscard]] virtual std::expected<std::size_t, DispatchError> DispatchPending() = 0;
	};
	// TODO Closing comments are not needed. Remove them in the whole project.
} // namespace UnrealVoxelSim::Events::Api
