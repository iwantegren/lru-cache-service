#!/bin/bash

cd build/linux
rm lru-cache-service
make
cp lru-cache-service ../../bin/linux/lru-cache-service

echo "..................................................."

./lru-cache-service 2 5