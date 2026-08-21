#pragma once

#include <functional>
#include <utility>

namespace UnrealVoxelSim::Events::Api
{

class Subscription final
{
  public:
    Subscription() noexcept = default;

    explicit Subscription(std::move_only_function<void() noexcept> unsubscribe) noexcept
        : Unsubscribe_(std::move(unsubscribe))
    {
    }

    ~Subscription()
    {
        Reset();
    }

    Subscription(const Subscription &) = delete;
    Subscription &operator=(const Subscription &) = delete;

    Subscription(Subscription &&other) noexcept : Unsubscribe_(std::move(other.Unsubscribe_))
    {
    }

    Subscription &operator=(Subscription &&other) noexcept
    {
        if (this != &other)
        {
            Reset();
            Unsubscribe_ = std::move(other.Unsubscribe_);
        }
        return *this;
    }

    [[nodiscard]] explicit operator bool() const noexcept
    {
        return static_cast<bool>(Unsubscribe_);
    }

    void Reset() noexcept
    {
        if (Unsubscribe_)
        {
            auto unsubscribe = std::move(Unsubscribe_);
            unsubscribe();
        }
    }

  private:
    std::move_only_function<void() noexcept> Unsubscribe_;
};

} // namespace UnrealVoxelSim::Events::Api
