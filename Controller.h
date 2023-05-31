#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class CacheGetCtrl : public drogon::HttpSimpleController<CacheGetCtrl, false>
{
public:
    void asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/", Get);
    PATH_LIST_END
};

class CachePostCtrl : public drogon::HttpSimpleController<CachePostCtrl, false>
{
public:
    void asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/", Post);
    PATH_LIST_END
};
