#include "Controller.h"

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

    auto &json = req->getJsonObject();
    if (json)
    {
        int key = json->get("key", -1).asInt();
        int value = json->get("value", -1).asInt();

        if (key != -1 && value != -1)
        {
            cache->set(key, value);
        }
    }
    else
    {
        response->setStatusCode(k422UnprocessableEntity);
    }

    callback(response);
}