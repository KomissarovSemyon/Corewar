run()
{
	./corewar_original -d $1 $2 $3 $4 $5 > output_original
	./corewar -dump $1 $2 $3 $4 $5 > output
	DIFF=$(diff output output_original)
	if [ "$DIFF" ]
	then
		printf "\e[1;31mKO\e[0m "
	else
		printf "\e[1;32mOK\e[0m "
	fi
	echo $2 $3 $4 $5
}

run $1 $2 $3 $4 $5
