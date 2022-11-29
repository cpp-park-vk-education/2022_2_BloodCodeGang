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

print_header "RUN clang-tidy"
# check_log "clang-tidy ./BitCounter/*.cpp -- -std=c++17 -I./BitCounter" "error:"

print_header "RUN clang-format"
check_log "clang-format -style=file ./BitCounter/*.cpp \
     ./BitCounter/*.hpp \
     ./bitInversion/*.cpp\
     memoryError/*cpp \
     memoryError/*hpp \
     tests/*cpp" "error:"

print_header "RUN cpplint"
check_log "cpplint --extensions=cpp ./bitCounter/*.cpp \
    ./bitCounter/*.hpp \
    ./bitInversion/*.cpp \
    ./bitInversion/*.hpp \
    memoryError/*cpp \
    memoryError/*hpp \
    tests/*cpp" "error:"

print_header "SUCCESS"
