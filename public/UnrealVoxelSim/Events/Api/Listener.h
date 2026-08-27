#pragma once

#include <functional>

namespace UnrealVoxelSim::Events::Api
{
	template <typename TEvent>
	using Listener = std::move_only_function<void(const TEvent&) noexcept>;
} // namespace UnrealVoxelSim::Events::Api
