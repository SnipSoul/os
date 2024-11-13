#!/bin/bash

# Output file
output_file="pattern_output.txt"

# Clear the output file
> "$output_file"

# Generate the pattern
for ((i=1; i<=4; i++))
do
    num=1
    for ((j=1; j<=i; j++))
    do
        echo -n "$num " >> "$output_file"
        num=$((num + 2))
    done
    echo "" >> "$output_file"
done

echo "Pattern written to $output_file"
