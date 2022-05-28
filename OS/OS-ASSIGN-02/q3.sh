#question 3

echo -e "SEARCH FILE BY NAME : \c"
read filename
if [ -e $filename ]
then
	echo "FILE EXISTS"
else
	echo "FILE DOES NOT EXISTS"
fi
