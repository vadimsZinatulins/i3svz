#define TOML_EXCEPTIONS 0

#include "utils/ArgParser.h"
#include "utils/version.h"
#include "Engine.h"

#include <iostream>
#include <string>
#include <optional>
#include <thread>
#include <chrono>
#include <toml++/toml.h>

int main(int argc, char *argv[])
{
    // Send arguments to argument parsers
    i3svz::utils::ArgParser parser(argc, argv);

    std::optional<std::string> configFilePath;

    // Add arguments to be evaluated
    parser.add({"--config-file", "-c"}, [&configFilePath](std::string path) { configFilePath = path; });
    parser.add({"--version", "-v"}, []() { i3svz::utils::printVersion(); });
    // Parse the arguments and execute their actions
    parser.parse();
    
    // Check if config file was provided
    if(configFilePath.has_value())
    {
        toml::parse_result result = toml::parse_file(configFilePath.value());
        
        if(!result)
        {
            std::cerr << result.error() << std::endl;
            return 1;
        }

        i3svz::Engine().process(std::move(result).table());
    }

    return 0;
}