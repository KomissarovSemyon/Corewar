test_error() {
	CHAMPS=$(find . -name "*.s")
	# CHAMPS=$(find . -name bigzork.s)

	for CHAMP in $CHAMPS
	do
		OUTPUT=$(./asm $CHAMP | grep -i 'writing')
		if [ "$OUTPUT" ]
		then
			mv $CHAMP ${CHAMP%.s}_tmp.s
			hexdump -Cv ${CHAMP%.s}.cor > tmp_original
			./disassemble ${CHAMP%.s}.cor > /dev/null
			./asm $CHAMP > /dev/null
			hexdump -Cv ${CHAMP%.s}.cor > tmp_da
			DIFF=$(diff tmp_original tmp_da)
			if [ -z "$DIFF" ]
			then
				printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
			else
				printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
				echo "$DIFF"
			fi
			mv ${CHAMP%.s}_tmp.s $CHAMP
			rm -rf ${CHAMP%.s}.cor
		fi
	done 2> /dev/null
	rm -rf tmp_original tmp_da .s champs/Octobre_Rouge_V4.s ./champs/championships/2014/bguy/sam_2.s
}

test_valgrind()
{
	CHAMPS=$(find . -name *.s)
	COUNT=0
	CORRECT=$(echo "definitely lost: 0 bytes in 0 blocks\nindirectly lost: 0 bytes in 0 blocks")
	for CHAMP in $CHAMPS
	do
		OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all ./disassemble $CHAMP 2>&1 | grep -E "definitely|indirectly" | cut -c14-)
		if test "$OUTPUT" != "$CORRECT"
		then
			printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
			echo "$OUTPUT"
			COUNT=$($COUNT + 1)
		else
			printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
		fi
	done
	echo $COUNT
	rm -rf tmp_original tmp_da .s champs/Octobre_Rouge_V4.s ./champs/championships/2014/bguy/sam_2.s
}

if [[ $# -eq 0 ]]
then
	echo 'options: all, error, valgrind'
	exit 0
fi

if [ $1 = 'all' ]
then
	test_error
fi

if [ $1 = 'error' ]
then
	test_error
fi

if [ $1 = 'valgrind' ]
then
	test_valgrind
fi
