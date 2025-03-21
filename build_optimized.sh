#!/bin/bash

echo "=== Building Optimized Versions ==="
echo

echo "Building optimized C version..."
gcc -O3 -march=native -flto time_test.c -o time_test_c_opt -lm

echo "Building optimized C++ version..."
g++ -O3 -march=native -flto -std=c++11 time_test.cpp -o time_test_cpp_opt

echo "Building optimized Rust version..."
rustc -C opt-level=3 -C target-cpu=native -C lto time_test.rs -o time_test_rust_opt

echo "Building optimized Go version..."
go build -ldflags="-s -w" -o timeprimes_opt timeprimes.go

echo
echo "=== Build Complete ==="
echo "Optimized binaries created:"
echo "- time_test_c_opt     (C version)"
echo "- time_test_cpp_opt   (C++ version)"
echo "- time_test_rust_opt  (Rust version)"
echo "- timeprimes_opt      (Go version)"