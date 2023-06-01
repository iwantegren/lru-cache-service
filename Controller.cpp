#include "Controller.h"

#include <iostream>
#include <string>

CacheGetCtrl::CacheGetCtrl(const std::shared_ptr<LRUCache> &cache_prt)
    : cache(cache_prt)
{
}

void CacheGetCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req,
                                          std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto response = drogon::HttpResponse::newHttpResponse();

    std::string key_param = req->getParameter("key");
    std::cout << "GET(" << key_param << ")\n";

    try
    {
        int key = std::stoi(key_param);
        response->setBody(std::to_string(cache->get(key)));
    }
    catch (std::invalid_argument const &ex)
    {
        response->setStatusCode(k422UnprocessableEntity);
    }

    callback(response);
}

CachePostCtrl::CachePostCtrl(const std::shared_ptr<LRUCache> &cache_prt)
    : cache(cache_prt)
{
}

void CachePostCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req,
                                           std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto response = drogon::HttpResponse::newHttpResponse();

    std::string key_param = req->getParameter("key");
    std::string value_param = req->getParameter("value");

    std::cout << "POST(" << key_param << ", " << value_param << ")\n";
    try
    {
        int key = std::stoi(key_param);
        int value = std::stoi(value_param);

        cache->set(key, value);
    }
    catch (std::invalid_argument const &ex)
    {
        response->setStatusCode(k422UnprocessableEntity);
    }

    callback(response);
}