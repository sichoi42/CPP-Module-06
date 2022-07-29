#!bin/bash

GREEN="\033[0;32m"
RESET="\033[0m"

echo -e "\033[0;32minput: 0\033[0m"
./scalar 0
echo "=========================="

echo -e "\033[0;32minput: nan\033[0m"
./scalar nan
echo "=========================="

echo -e "\033[0;32minput: inf\033[0m"
./scalar inf
echo "=========================="

echo -e "\033[0;32minput: -inf\033[0m"
./scalar -inf
echo "=========================="

echo -e "\033[0;32minput: 42\033[0m"
./scalar 42
echo "=========================="

echo -e "\033[0;32minput: 42.0\033[0m"
./scalar 42.0
echo "=========================="

echo -e "\033[0;32minput: 42.0f\033[0m"
./scalar 42.0f
echo "=========================="

echo -e "\033[0;32minput: a\033[0m"
./scalar a
echo "=========================="

echo -e "\033[0;32minput: abc\033[0m"
./scalar abc
echo "=========================="

echo -e "\033[0;32minput: 42.42a\033[0m"
./scalar 42.42a
echo "=========================="
