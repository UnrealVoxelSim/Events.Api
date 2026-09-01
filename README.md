# UnrealVoxelSim.Events.Api

Type-safe local event contracts shared by UnrealVoxelSim modules. Each domain event exposes a narrow source interface;
consumers register `noexcept` listeners and own move-only RAII subscriptions.

Local publication is synchronous. The in-memory implementation invokes listeners immediately in deterministic
subscription order, and nested publication is depth-first. There is no generic event pump or pending-event buffer.
