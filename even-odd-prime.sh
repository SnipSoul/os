#!/bin/bash
numbers=()

for (( i=0;i<5;i++ ))
do 
    read -p "Enter Number $i:" n 
    numbers+=("$n")
done

even=()
odd=()
for n in "${numbers[@]}"
do
    if (( n % 2 == 0 )); then
        even+=("$n")
    elif ((n%2!=0));then
        odd+=("$n")
    fi
done

prime=()
for n in "${numbers[@]}"
do
    if (( n <= 1 ));then
        continue
    fi

    is_prime=1  # Assume the number is prime
    for (( i=2; i*i<=n; i++ ))
    do
        if (( n % i == 0 )); then
            # If n is divisible by i, it's not prime
            is_prime=0
            break
        fi
    done

    if (( is_prime == 1 )); then
        # If no divisors were found, add to prime array
        prime+=("$n")
    fi

done

outputfile="result.txt"
{
    echo "All Numbers: ${numbers[@]}"
    echo "Even Numbers: ${even[@]}"
    echo "Odd Numbers: ${odd[@]}"
    echo "Prime Numbers: ${prime[@]}"
} > "$outputfile"

