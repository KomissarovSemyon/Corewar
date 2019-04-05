run()
{
	./corewar_original -d $1 $2 $3 > output_original
	./corewar -dump $1 $2 $3 > output
	DIFF=$(diff output output_original)
	if [ "$DIFF" ]
	then
		printf "\e[1;31mKO\e[0m "
	else
		printf "\e[1;32mOK\e[0m "
	fi
	echo $2 $3 $4 $5
	rm -rf output output_original
}

run_all()
{
	CHAMPS=$(find ./ch -name '*.cor' | cut -c 3-)
	for CHAMP1 in $CHAMPS
	do
		run $1 $CHAMP1
#		for CHAMP2 in $CHAMPS
#		do
#			run $1 $CHAMP1 $CHAMP2
#		done
	done
}

run_all $1
