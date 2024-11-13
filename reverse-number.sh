read -p "Enter Number: " n 
rem=0
rev=0
on=$n
while (( n>0 ))
do 
   rem=$((n%10)) 
   rev=$((rev*10+rem))
   n=$((n/10))
done

outputfile="result.txt"
{
    echo "Reverse of $on is $rev"
}>$outputfile
