cmake_minimum_required(VERSION 3.16.3)

project(lru-cache-service)

add_executable(${PROJECT_NAME} 
src/main.cpp
src/Controller.h
src/Controller.cpp
src/Cache.h
src/Cache.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(drogon)
target_include_directories(${PROJECT_NAME} PRIVATE drogon)

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads drogon)