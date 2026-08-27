#include "UnrealVoxelSim/Events/Api/Subscription.h"

#include <gtest/gtest.h>

#include <utility>

namespace UnrealVoxelSim::Events::Api
{

TEST(SubscriptionTest, DestructionUnsubscribesExactlyOnce)
{
    std::size_t calls{};
    {
        Subscription subscription{[&calls]() noexcept { ++calls; }};
        EXPECT_TRUE(subscription);
    }

    EXPECT_EQ(calls, 1U);
}

TEST(SubscriptionTest, MoveTransfersSubscriptionOwnership)
{
    std::size_t calls{};
    Subscription first{[&calls]() noexcept { ++calls; }};
    Subscription second{std::move(first)};

    EXPECT_FALSE(first);
    EXPECT_TRUE(second);
    second.Reset();
    second.Reset();

    EXPECT_EQ(calls, 1U);
}

}
