#pragma once

#include <toml++/toml.h>

namespace i3svz
{

class Engine
{
public:
    void process(toml::table table);
private:
};

}