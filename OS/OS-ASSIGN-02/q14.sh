#question 14

echo -e "ENTER NUMBER OF TERMS FOR FIBONACCI : \c"
read n
if [ $n -lt 1 ]
then
	echo -e "PLEASE ENTER A POSITIVE INTEGER"
else
	x=0
	y=1
	i=0
	while [ $i -lt $n ]
	do
		echo -e "$x \c"
		nxt=`expr $x + $y`
		x=$y
		y=$nxt
		i=`expr $i + 1` 
	done
	echo ""
fi
