#!/bin/bash

# Prompt user for input
read -p "Enter a string: " str

# Reverse the string
rev_str=$(echo "$str" | rev)

# Check if the original string is the same as the reversed string
if [ "$str" == "$rev_str" ]; then
    echo "$str is a palindrome."
else
    echo "$str is not a palindrome."
fi
