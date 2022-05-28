#question 12

echo -e "ENTER A NUMBER : \c"
read num
digit=0
sum=0
while [ $num -gt 0 ]
do
	digit=`expr $num % 10`
	sum=`expr $sum + $digit`
	num=`expr $num / 10`
done
echo "SUM OF DIGITS OF NUMBER YOU ENTERED IS : $sum"
