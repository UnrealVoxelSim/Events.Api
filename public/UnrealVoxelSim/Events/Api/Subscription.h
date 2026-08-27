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
        : m_Unsubscribe(std::move(unsubscribe))
    {
    }

    ~Subscription()
    {
        Reset();
    }

    Subscription(const Subscription &) = delete;
    Subscription &operator=(const Subscription &) = delete;

    Subscription(Subscription &&other) noexcept : m_Unsubscribe(std::move(other.m_Unsubscribe))
    {
    }

    Subscription &operator=(Subscription &&other) noexcept
    {
        if (this != &other)
        {
            Reset();
            m_Unsubscribe = std::move(other.m_Unsubscribe);
        }
        return *this;
    }

    [[nodiscard]] explicit operator bool() const noexcept
    {
        return static_cast<bool>(m_Unsubscribe);
    }

    void Reset() noexcept
    {
        if (m_Unsubscribe)
        {
            auto unsubscribe = std::move(m_Unsubscribe);
            unsubscribe();
        }
    }

  private:
    std::move_only_function<void() noexcept> m_Unsubscribe;
};

}
