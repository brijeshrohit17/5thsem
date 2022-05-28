#question 4

if [ -d "$@" ]
then
	echo "NUMBER OF FILES IS : $(find "$@" -type f | wc -l)"
	echo "NUMBER OF DIRECTORIES IS : $(find "$@" -type d | wc -l)"
else
	echo -e "ERROR\!, No FILES OF DIRECTORY FOUND\!"
	exit 1
fi
