#!/bin/bash

echo "=== Running Optimized Versions ==="
echo

# Function to extract time from output
get_time() {
    # Extract time value, handling both integer and decimal formats
    time=$(echo "$1" | grep -E "Time taken:|Time:" | grep -o '[0-9]*\.?[0-9]*' | head -n1)
    if [ -n "$time" ]; then
        # Convert to integer milliseconds
        printf "%.0f" "$time"
    else
        echo "0"
    fi
}

echo "Running C version:"
C_OUTPUT=$(./time_test_c_opt 2>&1)
[ -n "$C_OUTPUT" ] && echo "$C_OUTPUT"
echo

echo "Running C++ version:"
CPP_OUTPUT=$(./time_test_cpp_opt 2>&1)
[ -n "$CPP_OUTPUT" ] && echo "$CPP_OUTPUT"
echo

echo "Running Rust version:"
RUST_OUTPUT=$(./time_test_rust_opt 2>&1)
[ -n "$RUST_OUTPUT" ] && echo "$RUST_OUTPUT"
echo

echo "Running Go version:"
GO_OUTPUT=$(./timeprimes_opt 2>&1)
[ -n "$GO_OUTPUT" ] && echo "$GO_OUTPUT"
echo

echo "=== All optimized versions completed ==="