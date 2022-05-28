#question 10

echo -e "ENTER 1st NUMBER : \c"
read num1
echo -e "ENTER 2nd NUMBER : \c"
read num2
echo -e "INPUT AS FOLLOW :"
echo -e "1 : ADD\n2 : SUBTRACT\n3 : MULTIPLY\n4 : DIVIDE"
read op
if [ $num2 -eq 0 -a $op -eq 4 ]
then
	echo "DIVISION NOT POSSIBLE"
else
	case "$op" in
		1) echo -e "$num1 + $num2 = `expr $num1 + $num2`"
		;;
		2) echo -e "$num1 - $num2 = `expr $num1 - $num2`"
		;;
		3) echo -e "$num1 * $num2 = `expr $num1 \* $num2`"
		;;
		4) echo -e "$num1 / $num2 = `expr $num1 / $num2`"
		;;
	esac
fi
