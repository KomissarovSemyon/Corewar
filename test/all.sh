run()
{
	./corewar_original -d $1 $2 $3 $4 $5 > output_original
	./corewar -dump $1 $2 $3 $4 $5 > output
	DIFF=$(diff output output_original)
	if [ "$DIFF" ]
	then
		printf "\e[1;31mKO\e[0m "
#		echo $2 $3 $4 $5 >> all_err
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
		if [ $# -eq 2 ]
		then
			run $1 $2 $CHAMP1
		elif [ $# -eq 1 ]
		then
			sh all.sh $1 $CHAMP1
		fi
	done
}

run_two()
{
	CHAMPS=$(find ./ch -name '*.cor' | cut -c 3-)
	for CHAMP1 in $CHAMPS
	do
#		for CHAMP2 in $CHAMPS
#		do
#			for CHAMP3 in $CHAMPS
#			do
#				for CHAMP4 in $CHAMPS
#				do
					run $1 $CHAMP1 $CHAMP2 $CHAMP3 $CHAMP4
#				done
#			done
#		done
	done
}

run_two $1
