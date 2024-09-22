#pragma once

#include <memory>

namespace EA
{
template <typename T>
class CopyOnWrite
{
    using Storage = std::shared_ptr<const T>;
    using Stateful = std::shared_ptr<T>;

public:
    CopyOnWrite() { create(); }

    CopyOnWrite(const T& debugger) { create(debugger); }
    CopyOnWrite(const CopyOnWrite& other) = default;
    CopyOnWrite(const Stateful& other) { internal = other; }

    CopyOnWrite& operator=(const CopyOnWrite& other) = default;

    T get() const { return *internal; }
    Stateful copy() const { return std::make_shared<T>(*internal); }

    const T* operator->() const { return internal.get(); }
    const T& operator*() const { return *internal; }

    void set(const T& other) { create(other); }

private:
    template <typename... Args>
    void create(Args&&... args)
    {
        internal = std::make_shared<const T>(std::forward<Args>(args)...);
    }

    Storage internal;
};

template <typename T>
using COW = CopyOnWrite<T>;

template <typename T, typename... Args>
COW<T> makeCOW(Args&&... args)
{
    return {T(std::forward<Args>(args)...)};
}
}