#pragma once

#include <drogon/HttpSimpleController.h>
#include "Cache.h"

using namespace drogon;

class CacheGetCtrl : public drogon::HttpSimpleController<CacheGetCtrl, false>
{
public:
    CacheGetCtrl(const std::shared_ptr<LRUCache> &cache_prt);

    void asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/", Get);
    PATH_LIST_END

private:
    const std::shared_ptr<LRUCache> &cache;
};

class CachePostCtrl : public drogon::HttpSimpleController<CachePostCtrl, false>
{
public:
    CachePostCtrl(const std::shared_ptr<LRUCache> &cache_prt);

    void asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/", Post);
    PATH_LIST_END

private:
    const std::shared_ptr<LRUCache> &cache;
};
