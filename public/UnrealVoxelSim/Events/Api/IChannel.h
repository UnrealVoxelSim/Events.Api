#pragma once

#include "UnrealVoxelSim/Events/Api/IPublisher.h"
#include "UnrealVoxelSim/Events/Api/ISource.h"

namespace UnrealVoxelSim::Events::Api
{
	// TODO Combined interfaces should be avoided. IChannel does not contain anything new, it is just a helper to violate Interface Segregation Principle.
	template <typename TEvent>
	class IChannel : public ISource<TEvent>, public IPublisher<TEvent>
	{
	public:
		~IChannel() override = default;
	};
} // namespace UnrealVoxelSim::Events::Api
