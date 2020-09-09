#!/bin/bash

check() {
    rm -rf out
    mkdir -p out

    for i in $(seq 20); do
        FNAME=$(printf "core_%03d.gz" ${i})
        touch out/${FNAME}
    done

    ./rotate
}

check
