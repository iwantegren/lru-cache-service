#!/bin/bash

cd build/linux
cmake -S ../../ -B .
make

echo "..................................................."

./lru-cache-service