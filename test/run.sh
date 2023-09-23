:<<'header########################################'
@file run.sh
@author cuber-lotus
@version 0.1.2
@brief compile code and run valgrind to file

@run-instruction bash run.sh
    chmod u+x run.sh -> ./run.sh
header########################################

# compile program > a.out
g++                         \
    -g                      \
    -std=c++17              \
    main.cpp

# ignore in .gitignore
touch detail.log

# log to file
valgrind                    \
    --leak-check=full       \
    --track-origins=yes     \
    --log-file=detail.log   \
    ./a.out

# remove out file
rm a.out

// cppcheck main.cpp 2> check.txt