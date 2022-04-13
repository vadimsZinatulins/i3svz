#include "Engine.h"

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

namespace i3svz
{

void Engine::process(toml::table table)
{
    std::stringstream out;

    {
        toml::array modules;

        for (auto it : table)
        {
            if (toml::table *module = it.second.as_table())
            {
                modules.push_back(*module);
            }
        }

        out << toml::json_formatter(modules) << std::endl;
    }

    {
        toml::table tbl{ { "version", 1 } };
        std::cout << toml::json_formatter(tbl) << std::endl;
    }

    std::cout << "[[],";

    std::string output { out.str() + "," };

    while(true)
    {
        using namespace std::chrono_literals;

        std::cout << output << std::endl;

        std::this_thread::sleep_for(1000ms);
    }
}

}