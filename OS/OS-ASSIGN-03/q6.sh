#question 6

echo -e "ENTER DIRECTORY : \c"
read dirname
if [ -d $dirname ]
then
	find $dirname -type f -size +1000c -exec du -h {} \; | sort -rh
	echo -e "NUMBER OF SUCH FILES : \c"
	find $dirname -type f -size +1000c | wc -l
fi
