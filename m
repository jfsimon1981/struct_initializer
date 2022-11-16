echo "gcc build"
egcc main.c -o main.gcc

echo "gcc with flags build"
egcc main.c -pedantic -W -Wall -Werror -Wshadow -Wdouble-promotion -fno-common -Wconversion -Wundef -o main.gcc

echo "clang build"
clang main.c -o main.clang

echo "clang with flags build"
clang main.c -pedantic -W -Wall -Werror -Wshadow -Wdouble-promotion -fno-common -Wconversion -Wundef -o main.clang

# -pedantic -W -Wall -Werror -Wshadow -Wdouble-promotion -fno-common -Wconversion -Wundef