#include "ArgParser.h"

#include <iostream>

namespace i3svz
{

namespace utils
{

ArgParser::ArgParser(int argc, char *argv[]) : m_arguments(std::vector<std::string>(argv + 1, argv + argc)) {}
ArgParser::~ArgParser() { }

void ArgParser::add(std::set<std::string> params, std::function<void()> action)
{
    for(const auto &arg : params)
        m_actions[arg] = [action](std::vector<std::string> &, std::size_t&) { action(); };
}

void ArgParser::add(std::set<std::string> params, std::function<void(std::string)> action)
{
    for(const auto &arg : params)
        m_actions[arg] = [action](std::vector<std::string> &args, std::size_t &index) { action(args[++index]); };

}

void ArgParser::parse()
{
    for(std::size_t i = 0; i < m_arguments.size(); ++i) 
    {
        auto ptr = m_actions.find(m_arguments[i]);
        if(ptr != m_actions.end()) ptr->second(m_arguments, i);
    }
}

}

}