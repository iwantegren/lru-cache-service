#!/bin/bash

cd build/linux
rm lru-cache-service
make

echo "..................................................."

./lru-cache-service 2 5