#question 11

echo -e "ENTER A NUMBER : \c"
read num
echo -e "REVERSE USING  REV : \c"
echo $num | rev
d=0
rev=0
while [ $num -gt 0 ]
do
	digit=`expr $num % 10`
	rev=`expr $rev \* 10`
	rev=`expr $rev + $digit`
	num=`expr $num / 10`
done
echo -e "REVERSE USING WHILE : \c"
echo "$rev"
