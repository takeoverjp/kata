#!/bin/bash

check() {
    local CORE=$1

    rm -rf out
    mkdir -p out

    cat $CORE | ./zcore out $(date +%s) executable 6 1234 1234

    gunzip out/*.gz
    diff $CORE out/core_*
}

check testdata/test1
