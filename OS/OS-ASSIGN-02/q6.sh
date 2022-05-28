#question 6

if [ $# -ne 2 ]
then
	echo -e "INVALID NUMBER OF ARGUMENTS"
else
	echo "SUM : `expr $1 + $2`"
fi

