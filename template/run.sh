#!/bin/bash

g++ \
  -D_GLIBCXX_DEBUG \
  -Wall \
  -fsanitize=address,undefined \
  -g \
  -DLC_LOCAL \
  -std=c++20 \
  main.cpp && ./a.out
