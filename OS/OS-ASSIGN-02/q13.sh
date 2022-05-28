#question 13

echo -e "ENTER NUMBER : \c"
read n
if [ $n -lt 0 ]
then
	echo -e "PLEASE ENTER A NON-NEGATIVE INTEGER!"
else
	num=$n
	fact=1
	while [ $n -gt 1 ]
	do
		fact=`expr $fact \* $n`
		n=`expr $n - 1`
	done
	echo -e "FACTORIAL OF $num = $fact"
fi
