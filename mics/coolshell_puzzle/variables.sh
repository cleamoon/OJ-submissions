#!/bin/bash

number=2014

while true; do
    url="https://fun.coolshell.cn/n/$number"
    response=$(curl -s "$url")
    number=$((response))
    echo "$number"
done