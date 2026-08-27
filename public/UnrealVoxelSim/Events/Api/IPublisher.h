#pragma once

namespace UnrealVoxelSim::Events::Api
{
	template <typename TEvent>
	class IPublisher
	{
	public:
		virtual ~IPublisher() = default;

		virtual void Publish(TEvent event) = 0;
	};
}
