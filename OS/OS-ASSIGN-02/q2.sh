#quesiton 2

echo -e "1 : NUMBER OF USERS \n2 : CALENDAR \n3 : DATE"
read op
case "$op" in
	1) who --count | grep users
	;;
	2) cal
	;;
	3) date
	;;
	*) echo -e "INCORRECT INPUT!"
	;;
esac
