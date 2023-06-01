#!/bin/bash

# Script tests service with some basic scenarios
# For capacity 3 expected output:
# 1
# -1
# 2
# -1
# 1
# -1
# 5
# 5
# 5

source $(dirname $0)/http_utils.sh


# basic set and get
POST 1 1
GET 1
# return 1


# simple cache capacity exceeded
POST 2 2
POST 3 3
POST 4 4
GET 1
# return -1


# update existing key
POST 1 1
POST 1 2
GET 1
# return 2


# get non-existent key
GET 5
# return -1


# access pattern for LRU
POST 1 1
POST 2 2
POST 3 3
GET 1 
# return 1
POST 4 4
GET 2
# return -1


# idempotent operations
POST 5 5
POST 5 5
POST 5 5
GET 5
GET 5
GET 5
# return 5 5 5
