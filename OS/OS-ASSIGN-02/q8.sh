#question 8

if [ $# == 2 ]
then
	echo -e "INPUT AS FOLLOWS"
	echo -e "1 : ADD\n2 : SUBTRACT\n3 : MULTIPLY\n4 : DIVIDE"
	read op
	if [ $2 -eq 0 -a $op -eq 4 ]
	then
		echo "DIVISION NOT POSSIBLE"
	else
		case "$op" in 
			1) echo "$1 + $2 = `expr $1 + $2`"
			;;
			2) echo "$1 - $2 = `expr $1 - $2`"
			;;
			3) echo "$1 * $2 = `expr $1 \* $2`"
			;;
			4) echo "$1 / $2 = `expr $1 / $2`"
			;;
		esac
	fi
else
	echo -e "ERROR\! INCORRECT NUMBER OF ARGUMENTS"
fi
