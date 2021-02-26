#!/bin/bash

#shopt extglob
#rm -i !(*.sh)
find . \! -name 'clean.sh' -delete

echo "#include <iostream>" > main.cpp
echo "int main()" >> main.cpp
echo "{" >> main.cpp
echo "  std::cout << \"Hello world!\" << std::endl;" >> main.cpp
echo "  return 0;" >> main.cpp
echo "}" >> main.cpp

echo "Done"