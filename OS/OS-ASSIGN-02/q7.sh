#question 7

if [ $# == 3 ]
then
	echo -e "GREATEST OF FROM $1, $2 AND $3 IS : \c"
	if [ $1 -ge $2 ] && [ $1 -ge $3 ]
	then
		echo $1
	elif [ $2 -ge $3 ]
	then
		echo $2
	else
		echo $3
	fi
else
	echo "ERROR! INCORRECT NUMBER OF ARGUMENTS"
fi
