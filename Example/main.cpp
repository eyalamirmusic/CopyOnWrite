#include <iostream>
#include "CopyOnWrite/CopyOnWrite.h"

struct Debugger
{
    Debugger() { std::cout << "Constructor\n"; }
    ~Debugger() { std::cout << "Destructor\n"; }

    Debugger(const Debugger&) { std::cout << "Copy Constructor\n"; }

    Debugger(Debugger&&) noexcept { std::cout << "Move Constructor\n"; }

    Debugger& operator=(const Debugger&)
    {
        std::cout << "Copy Assign\n";
        return *this;
    }

    Debugger& operator=(Debugger&&) noexcept
    {
        std::cout << "Move Assign\n";
        return *this;
    }
};

struct StatefulDebugger
{
    Debugger debugger;
    int x = 0;
};

int main()
{
    auto x = EA::makeCOW<std::string>("Hey");
    auto y = EA::makeCOW<std::string>("Hello!");
}