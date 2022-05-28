#question 1

echo -e "ENTER NUMBER TO FIND PRIME FACTORS OF IT : \c"
read num

if [ $num -le 0 ]
then
	echo "ENTERED NUMBER IS NON-POSITIVE"
	exit 1
fi
echo -e "THE PRIME FACTORS OF $num IS/ARE : \c"
i=2
while [ $i -lt $num ]
do
	primecheck=0
	if [ $((num%i)) -eq 0 ]
	then
		j=2
		while [ $j -le $((i/2)) ]
		do
			if [ $((i%j)) -eq 0 ]
			then
				primecheck=1
				break
			fi
			j=`expr $j + 2`
		done
		if [ $primecheck -eq 0 ]
		then
			echo -e "$i \c"
		fi
	fi
	i=`expr $i + 1`
done
echo ""
