#! /bin/bash -l

shopt -s nullglob

codePath=$1
cppFiles=( "$codePath"*.cpp )
code="${cppFiles[0]}"
echo $code
if [[ -f $code ]]; then
    clang++-12 -Wall -Wextra -std=c++17 "$code" -o submission
else
    echo "No code submitted."
fi
