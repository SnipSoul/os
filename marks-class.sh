#!/bin/bash

# Initialize variables
total=0
num_subjects=5

# Read marks for 5 subjects
echo "Enter marks for 5 subjects:"
for ((i=1; i<=num_subjects; i++))
do
    read -p "Subject $i: " mark
    total=$((total + mark))
done

# Calculate average
average=$((total / num_subjects))

# Determine the class based on the average
class=""

case $average in
    9[0-9]|100) class="Distinction" ;;
    7[5-9]) class="First Class" ;;
    5[0-9]|6[0-9]) class="Second Class" ;;
    3[5-9]|4[0-9]) class="Pass Class" ;;
    *) class="Fail" ;;
esac

# Display results
echo "Total Marks: $total"
echo "Average Marks: $average"
echo "Final Class: $class"
