#question 4

if [ $# -ne 2 ]
then
	echo "INCORRECT NUMBER OF ARGUMENTS!"
else
i=0
while [ $i -lt $1 ]
do
	echo "$2"
	i=`expr $i + 1`
done
fi
