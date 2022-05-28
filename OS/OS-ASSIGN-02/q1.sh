#question 1:

echo -e "Enter character: \c"
read c
case "$c" in
	"a"|"e"|"i"|"o"|"u") echo "A LOWERCASE VOWEL"
	;;
	"A"|"E"|"I"|"O"|"U") echo "A UPPERCASE VOWEL"
	;;
	[[:lower:]]) case "$c" in
		*)echo "LOWERCASE CONSONANT"
		;;
	esac
	;;
	[[:upper:]]) case "$c" in
		*) echo "UPPERCASE CONSONANT"
		;;
	esac
	;;
	[[:digit:]]) echo "NUMERIC DIGIT"
	;;
	[[:punct:]]) echo "SPECIAL CHARACTER"
	;;
	*) echo "OTHER CHARACTER"
	;;
esac
