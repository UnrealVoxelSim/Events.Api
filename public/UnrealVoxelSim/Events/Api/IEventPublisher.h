#pragma once

namespace UnrealVoxelSim::Events::Api
{

template <typename TEvent> class IEventPublisher
{
  public:
    virtual ~IEventPublisher() = default;

    virtual void Publish(TEvent event) = 0;
};

} // namespace UnrealVoxelSim::Events::Api
