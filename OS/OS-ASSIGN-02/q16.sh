#question 16

echo -e "SEARCH FILE NAME : \c"
read filename
if [ -e $filename ]
then
	lines=`wc -l < $filename`
	words=`wc -w < $filename`
	chars=`wc -m < $filename`
echo "No. of Characters: $chars"
echo "No. of Words: $words"
echo "No. of Lines: $lines"
else
echo "FILE DOES NOT EXIST"
fi
