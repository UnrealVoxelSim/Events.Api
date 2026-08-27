// TODO Please don't use "proxy headers". Include all files directly where needed. Interface Segregation Principle applies to many concepts, not only literal C++ interfaces.
// TODO additionally make a whole-project sweep for other instances of "proxy headers". Prohibit them in ModuleTemplate/AGENTS.md

#pragma once

#include "UnrealVoxelSim/Events/Api/DispatchError.h"
#include "UnrealVoxelSim/Events/Api/IChannel.h"
#include "UnrealVoxelSim/Events/Api/IPublisher.h"
#include "UnrealVoxelSim/Events/Api/IPump.h"
#include "UnrealVoxelSim/Events/Api/ISource.h"
#include "UnrealVoxelSim/Events/Api/Listener.h"
#include "UnrealVoxelSim/Events/Api/Subscription.h"
