#include "Controller.h"

#include <iostream>
#include <string>

void CacheGetCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req,
                                          std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto response = drogon::HttpResponse::newHttpResponse();

    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>\n";
    std::cout << "method: " << req->getMethodString() << std::endl;
    // std::cout << "key: " << req->getParameter(std::string("key")) << std::endl;
    // std::cout << "value: " << req->getParameter(std::string("value")) << std::endl;
    auto params = req->getParameters();
    std::cout << "params " << params.size() << std::endl;

    response->setBody("Hello, Drogon from GET Ctrl!\n");
    callback(response);
}

void CachePostCtrl::asyncHandleHttpRequest(const HttpRequestPtr &req,
                                           std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto response = drogon::HttpResponse::newHttpResponse();

    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>\n";
    std::cout << "method: " << req->getMethodString() << std::endl;
    // std::cout << "key: " << req->getParameter(std::string("key")) << std::endl;
    // std::cout << "value: " << req->getParameter(std::string("value")) << std::endl;
    auto params = req->getParameters();
    std::cout << "params " << params.size() << std::endl;

    response->setBody("Hello, Drogon from POST Ctrl!\n");
    callback(response);
}