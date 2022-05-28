#question 5

echo -e "ENTER ORIGINAL FILENAME : \c"
read original
echo -e "ENTER NEW FILENAME : \c"
read new
echo -e  "\n\nCONTENT BEFORE COPYING : "
echo -e "\nCONTENT OF ORIGINAL FILE :"
cat $original
echo -e "\nCONTENT OF NEW FILE :"
if [ -e $new ]
then
	cat $new
else
	echo -e "NEW FILE DOES NOT EXIST!"
fi
cat $original >> $new
echo -e  "\n\nCONTENT AFTER COPYING : "
echo -e "\nCONTENT OF ORIGINAL FILE :"
cat $original
echo -e "\nCONTENT OF NEW FILE :"
cat $new
echo ""
