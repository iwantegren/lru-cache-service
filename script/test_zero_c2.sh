#!/bin/bash

# Script tests service with some basic scenarios
# For capacity 2 expected output:
# 1
# -1
# -1
# 3
# 4

source $(dirname $0)/http_utils.sh

POST 1 1
POST 2 2
GET 1
POST 3 3
GET 2
POST 4 4
GET 1
GET 3
GET 4
