read -p "Enter Month: " m 
if (( m<1 || m>12 ));then
    echo "Enter Valid Month"
fi
read -p "Enter Year: " y 
if (( y<2000 ));then
    echo "Enter Valid Year"
fi
cal $m $y