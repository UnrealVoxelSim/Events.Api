#pragma once

#include "UnrealVoxelSim/Events/Api/IPublisher.h"
#include "UnrealVoxelSim/Events/Api/ISource.h"

namespace UnrealVoxelSim::Events::Api
{

template <typename TEvent> class IChannel : public ISource<TEvent>, public IPublisher<TEvent>
{
  public:
    ~IChannel() override = default;
};

} // namespace UnrealVoxelSim::Events::Api
