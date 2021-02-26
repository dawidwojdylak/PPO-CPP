#!/bin/bash
read -p "Usunac wszystko? (T/N): " confirm
shopt -s extglob;
if [ "$confirm" = "t" ]; then
  rm -rv !("clearAll_IS.sh"|"CMakeLists.txt"|"Makefile");
fi
echo "int main(){
  
}" > main.cpp
