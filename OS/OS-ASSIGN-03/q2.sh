#question 3

echo -e "ENTER NUMBER TO LIST DIVISORS : \c"
read n
i=1
while [ $i -le $n ]
do
	if [ $((n%i)) -eq 0 ]
	then
		echo -e "$i \c"
	fi
	i=`expr $i + 1`
done
echo ""
