#!/bin/bash

echo "=== Building and Running All Versions ==="
echo

echo "Running C version:"
gcc -O3 time_test.c -o time_test_c_release -lm && ./time_test_c_release
echo

echo "Running C++ version:"
g++ -std=c++11 -O3 time_test.cpp -o time_test_cpp_release && ./time_test_cpp_release
echo

echo "Running Rust version:"
rustc -O time_test.rs -o time_test_rust_release && ./time_test_rust_release
echo

echo "Running Go version:"
go run timeprimes.go
echo

echo "=== All versions completed ==="