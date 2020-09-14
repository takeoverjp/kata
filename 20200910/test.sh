#!/bin/bash

OUTPUT_DIR=out

setup() {
    rm -rf ${OUTPUT_DIR}
    mkdir -p ${OUTPUT_DIR}
}

min() {
    if [ $1 -le $2 ]; then
        echo $1
    else
        echo $2
    fi
}

test_gzip() {
    local CORE=$1
    setup

    SEC=$(date +%s)
    cat ${CORE} |
        ./core_pipe -v ${OUTPUT_DIR} ${SEC} exec_name > out/log

    DATE=$(date --utc --date="@${SEC}" +%Y%m%d_%H%M%S)
    EXP_CORE_NAME="core_000_${DATE}_exec_name.gz"
    if [ ! -f ${OUTPUT_DIR}/${EXP_CORE_NAME} ]; then
        echo "Error $0 $1: ${EXP_CORE_NAME} not found"
        cat out/log
        exit 1
    fi
    gunzip ${OUTPUT_DIR}/${EXP_CORE_NAME}
    diff ${CORE} ${OUTPUT_DIR}/${EXP_CORE_NAME%.*}
    if [ $? -ne 0 ]; then
        echo "Error $0 $1: ${CORE} and ${EXP_CORE_NAME%.*} differ"
        cat out/log
        exit 1
    fi
    printf "."
}

test_max_num() {
    local CORE=$1
    local MAX_NUM=$2
    setup

    for i in $(seq 10); do
        FNAME=$(printf "core_%03d.gz" ${i})
        touch ${OUTPUT_DIR}/${FNAME}
    done

    SEC=$(date +%s)
    cat ${CORE} |
        ./core_pipe -v -n ${MAX_NUM} ${OUTPUT_DIR} ${SEC} exec_name > out/log

    local FILE_NUM=$(find ${OUTPUT_DIR} -name 'core_*' | wc -l)
    local EXP_NUM=$(min $MAX_NUM 11)
    if [ ${FILE_NUM} -ne ${EXP_NUM} ]; then
        echo "Error $0 $1 $2: FILE_NUM=${FILE_NUM} EXP_NUM=${EXP_NUM}"
        cat out/log
        exit 1
    fi
    LAST_CORE_NAME=$(find out/ -name 'core_*' | sort | tail -1 | xargs basename)
    DATE=$(date --utc --date="@${SEC}" +%Y%m%d_%H%M%S)
    EXP_CORE_NAME="core_011_${DATE}_exec_name.gz"
    if [[ "${LAST_CORE_NAME}" != "${EXP_CORE_NAME}" ]]; then
        echo "Error $0 $1 $2: LAST_CORE_NAME=${LAST_CORE_NAME} EXP_CORE_NAME=${EXP_CORE_NAME}"
        cat out/log
        exit 1
    fi
    printf "."
}

prepare_testdata() {
    if [ -d testdata ]; then
        return
    fi

    mkdir testdata
    for BS in 1K 10K 100K 1M 10M; do
        dd if=/dev/urandom of=testdata/core_${bs} count=1 bs=${BS}
    done
}


prepare_testdata

for BS in 1K 10K 100K 1M 10M; do
    TESTDATA=testdata/core_${BS}
    test_gzip ${TESTDATA}
done

for MAX_NUM in 1 5 7 9 10 11 13 15 19; do
    test_max_num testdata/core_1M ${MAX_NUM}
done

# TODO: test_max_size ${TESTDATA} ${MAX_SIZE}

echo
echo "OK"
