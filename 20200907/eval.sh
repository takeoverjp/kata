#!/bin/bash

echo "WORKSET_KB,SEC"
for i in $(seq 15)
do
    WORKSET_KB=$((1 << $i))
    printf "${WORKSET_KB},"
    ./eval_cache ${WORKSET_KB}
done
