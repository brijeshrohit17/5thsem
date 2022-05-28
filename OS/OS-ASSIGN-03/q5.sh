#question 5

echo -e "ENTER FILE NAME : \c"
read filename
if [ -e $filename ]
then
	echo -e "TOTAL NUMBER OF BLANK LINES : \c"
	grep -c ^$ $filename
else
	echo "FILE DOESN'T EXIST!"
fi
