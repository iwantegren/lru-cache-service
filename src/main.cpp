#include <iostream>
#include <string>
#include <drogon/drogon.h>
#include "Controller.h"

using namespace drogon;

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Not enough arguments\n";
        return 1;
    }

    int capacity, threads;
    try
    {
        capacity = std::stoi(argv[1]);
        threads = std::stoi(argv[2]);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Invalid arguments:\n";
        std::cout << "Capacity = " << argv[1] << "\n";
        std::cout << "Threads = " << argv[2] << "\n";
        return 1;
    }

    std::string ip{"127.0.0.1"};
    int port{8080};

    std::cout << "Started 'LRU cache' service with parameters:\n";
    std::cout << ip << ":" << port << "\n";
    std::cout << "Cache capacity: " << capacity << "\n";
    std::cout << "Number of threads: " << threads << "\n";

    app().setLogLevel(trantor::Logger::kWarn).addListener(ip, port).setThreadNum(threads);

    auto cache_ptr = std::make_shared<LRUCache>(capacity);

    auto ctrl_get_ptr = std::make_shared<CacheGetCtrl>(cache_ptr);
    auto ctrl_post_ptr = std::make_shared<CachePostCtrl>(cache_ptr);
    app().registerController(ctrl_get_ptr);
    app().registerController(ctrl_post_ptr);

    std::cout << "Ready!\n";

    app().run();

    return 0;
}