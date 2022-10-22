#!/usr/bin/env bash

set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

function check_log() {
    LOG=$( { ${1}; } 2>&1 )
    STATUS=$?
    echo "$LOG"
    if echo "$LOG" | grep -q -E "${2}"
    then
        exit 1
    fi

    if [ $STATUS -ne 0 ]
    then
        exit $STATUS
    fi
}

# print_header "RUN clang-format"
# check_log "clang-format -i -style=file ./BitCounter/*.cpp ./BitCounter/*.h" "error:"

print_header "RUN cpplint"
check_log "cpplint --extensions=cpp ./bitCounter/*.cpp \
    ./bitCounter/*.h \
    ./bitInversion/*.cpp \
    ./bitInversion/*.h \
    memoryError/*cpp \
    memoryError/*h \
    tests/*cpp" "Can't open for reading"

print_header "SUCCESS"