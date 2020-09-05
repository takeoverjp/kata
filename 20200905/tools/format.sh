#!/bin/bash -e

TARGET_FILES=$(find src test -name '*.cpp' -o -name '*.h')
echo ${TARGET_FILES} |
    xargs clang-format -i
echo ${TARGET_FILES} |
    xargs cpplint.py --filter=-build/header_guard,-build/include
