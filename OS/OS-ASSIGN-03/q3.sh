#question 3

hr=$(date +"%H")
t=$(date +"%T")
if [ $hr -ge 4 -a $hr -lt 12 ]
then
	echo -e "GOOD MORNING, IT'S TIME FOR BREAKFAST.($t)1"
elif [ $hr -ge 12 -a $hr -lt 16 ]
then
	echo -e "GOOD AFTERNON, IT'S TIME FOR TEA.($t PM)"
elif [ $hr -ge 16 -a $hr -lt 19 ]
then
	echo -e "GOOD EVENING, IT'S TIME FOR SNACKS.($t PM)"
elif [ $hr -ge 19 -a $hr -le 23 ]
then
	echo -e "TIME TO SLEEP, IT'S $t PM NIGHT"
else
	echo -e "GOOD NIGHT, IT'S $t AM NIGHT"
fi
