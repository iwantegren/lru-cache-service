#!/bin/bash

GET ()
{
    # echo "GET($1):"
    curl -X GET http://127.0.0.1:8080?key=$1
    echo
}

POST ()
{
    # echo "POST($1,$2)"
    curl -X POST http://127.0.0.1:8080 -H "Content-Type: application/json" -d '{"key": '$1', "value": '$2'}'
}