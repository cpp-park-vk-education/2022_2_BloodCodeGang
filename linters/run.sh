#!/usr/bin/env bash
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

function check_log() {
    local log=$($1 2>&1) # run command and save output to log
    if [[ $log == *"$2"* ]]; then # check if log contains error
        echo -e "\033[31m$1 failed\033[0m" # print error
        echo "$log" # print log
        exit 1
    fi
}

print_header "RUN clang-format"
check_log "clang-format -style=file ./BitCounter/*.cpp \
     ./BitCounter/*.h \
     ./bitInversion/*.cpp\
     memoryError/*cpp \
     memoryError/*h \
     tests/*cpp" "error:"

print_header "RUN cpplint"
check_log "cpplint --extensions=cpp ./bitCounter/*.cpp \
    ./bitCounter/*.h \
    ./bitInversion/*.cpp \
    ./bitInversion/*.h \
    memoryError/*cpp \
    memoryError/*h \
    tests/*cpp" "error:"

print_header "RUN clang-tidy"
check_log "clang-tidy -- -std=c++17 ./bitCounter/*.cpp \
    ./bitCounter/*.h \
    ./bitInversion/*.cpp \
    ./bitInversion/*.h \
    memoryError/*cpp \
    memoryError/*h \
    tests/*cpp" "error:"

print_header "SUCCESS"
