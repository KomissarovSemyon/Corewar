test()
{
	RANDOM=$$
	FAIL=0
	CHAMPS=$(find ./ch -mindepth 1 -maxdepth 5 -name '*.s' | cut -c 3-)
	for CHAMP1 in $CHAMPS
	do
		OUTPUT=$(./asm $CHAMP1 | grep -i 'error\|ошибка')
		if [ -z "$OUtPUT" ]
		then
			for CHAMP2 in $CHAMPS
			do
				OUTPUT=$(./asm $CHAMP2 | grep -i 'error\|ошибка')
				if [ -z "$OUTPUT" ]
				then
					DUMP=$RANDOM
					./corewar_original -d $DUMP ${CHAMP1%.s}.cor ${CHAMP2%.s}.cor > output_original
					./corewar -map -dump $DUMP ${CHAMP1%.s}.cor ${CHAMP2%.s}.cor > output
					DIFF=$(diff output output_original)
					if [ "$DIFF" ]
					then
						FAIL=$((FAIL+1))
						printf "\e[1;31mKO\e[0m ./corewar -d %s %s %s\n" $DUMP ${CHAMP1%.s}.cor ${CHAMP2%.s}.cor
						echo "./corewar -map -dump $DUMP ${CHAMP1%.s}.cor ${CHAMP2%.s}.cor" > $FAIL.diff
						echo "./corewar_original -d $DUMP ${CHAMP1%.s}.cor ${CHAMP2%.s}.cor" >> $FAIL.diff
						echo $DIFF >> $FAIL.diff
					fi
					rm -rf output output_original
				fi
				rm -rf ${CHAMP2%.s}.cor
				# exit 0
			done
		fi
		rm -rf ${CHAMP2%.s}.cor
	done
	echo "FAILED: $FAIL"
}

if [[ $# -eq 0 ]] ; then
    echo 'options: test, clean'
    exit 0
fi

if [ $1 = 'test' ] ; then
	test
fi

if [ $1 = 'clean' ] ; then
	rm -rf *.diff
fi
# if [ $1 = 'error' ] ; then
#     # coproc test_error 2> /dev/null
#     test_error
# fi

# if [ $1 = 'correct' ] ; then
#     test_correct
# fi
