read -p "Enter Number: " num 
fact=1
if (( num==1 ));then
    echo "Factorial of 1 is 1"
elif (( num<=0 ));then
    echo "There is No factorial for number<=0 "
else
    for (( i=num;i>=1;i-- ))
    do
        fact=$((fact*i))
    done
fi


flag=0
if (( num==1 ));then
    flag=1
fi
for (( i=2;i*i<=num;i++ ))
do 
    if (( num%i==0 ));then
        flag=1
        break
    fi
done
if (( flag==0 ));then
outputfile="result.txt"
{
    echo "Factorial of $num is $fact"
    echo "$num is a Prime Number"
} > "$outputfile"

else
outputfile="result.txt"
{
    echo "Factorial of $num is $fact"
    echo "$num is Not a Prime Number"
} > "$outputfile"

fi

