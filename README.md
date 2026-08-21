# UnrealVoxelSim.Events.Api

Dynamic, type-safe event contracts shared by UnrealVoxelSim modules.

Each domain event exposes its own narrow source interface, normally as a domain-local alias such as
`using IFoundedSource = Events::Api::ISource<Founded>`. Consumers register `noexcept` functors and own the returned
move-only RAII subscription.

Publishers submit event values whose lifetime is owned by the event implementation. `IPump` provides generic
queued dispatch and pending-delivery inspection; it has no knowledge of simulation ticks, phases, ECS, or persistence.
All interfaces are thread-affine unless an implementation documents a stronger contract.
