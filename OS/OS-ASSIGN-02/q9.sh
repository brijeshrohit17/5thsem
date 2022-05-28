#question 9

echo -e "ENTER A NUMBER : \c"
read num
echo -e "THE DECREASING ORDER IS AS : \c"
while [ $num -ge 1 ]
do
	echo -e "$num \c"
	num=`expr $num - 1`
done
echo ""
