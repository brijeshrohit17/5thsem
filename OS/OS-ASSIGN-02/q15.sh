#question 15

echo -e "ENTER LOWER LIMIT : \c"
read ll
echo -e "ENTER UPPER LIMIT : \c"
read ul
if [ $ll -ge $ul ]
then
	echo "INVALID INPUT!"
fi
rem=`expr $ll % 2`
if [ $rem == 1 ]
then
	ll=`expr $ll + 1`
else
	ll=`expr $ll + 2`
fi
while [ $ll -lt $ul ]
do
	echo -e "$ll \c"
	ll=`expr $ll + 2`
done
echo ""
