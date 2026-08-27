#pragma once

#include "UnrealVoxelSim/Events/Api/Listener.h"
#include "UnrealVoxelSim/Events/Api/Subscription.h"

namespace UnrealVoxelSim::Events::Api
{
	template <typename TEvent>
	class ISource
	{
	public:
		virtual ~ISource() = default;

		[[nodiscard]] virtual Subscription Subscribe(Listener<TEvent> listener) = 0;
	};
} // namespace UnrealVoxelSim::Events::Api
