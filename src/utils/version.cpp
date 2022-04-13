#include "version.h"
#include "../config.h"

#include <iostream>

namespace i3svz
{

namespace utils
{

void printVersion()
{
    std::cout << "i3svz VERSION " << MAJOR_VERSION << "." << MINOR_VERSION << "." << PACTH_VERSION << std::endl << std::endl;
    std::cout << "MIT License" << std::endl << std::endl;
    std::cout << "Copyright (c) 2022 Vadims Zinatlins" << std::endl;
    std::exit(0);
}

}

}