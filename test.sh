test=Drogue
colormin=31
colormax=37
colorcurr=$colormin

while true; do 
	echo -n "\r\033["$colorcurr"m"$test
	export colorcurr=$(echo $colorcurr" + 1" | bc)
	if [ $colorcurr = $colormax ]
	then
		export colorcurr=$colormin 
	fi
done
