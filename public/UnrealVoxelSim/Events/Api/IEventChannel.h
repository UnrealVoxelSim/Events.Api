#pragma once

#include "UnrealVoxelSim/Events/Api/IEventPublisher.h"
#include "UnrealVoxelSim/Events/Api/IEventSource.h"

namespace UnrealVoxelSim::Events::Api
{

template <typename TEvent> class IEventChannel : public IEventSource<TEvent>, public IEventPublisher<TEvent>
{
  public:
    ~IEventChannel() override = default;
};

} // namespace UnrealVoxelSim::Events::Api
