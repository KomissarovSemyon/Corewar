test()
{
	echo $1 '  ' $2
	for ((i=1; i < 35000; i++))
	do
		./corewar_original -d $i $1 $2 > output_original
		./corewar -dump $i $1 $2 > output
		DIFF=$(diff output output_original)
		if [ "$DIFF" ]
		then
			printf "\e[1;31mKO\e[0m "
			echo $i
			echo "./corewar_original -d " $i $1 $2
			echo "./corewar -dump " $i $1 $2
			break
		else
			printf "\e[1;32mOK\e[0m "
			echo $i
		fi
	done
}

test $1 $2
