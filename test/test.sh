test_asm_error() {
	CHAMPS=$(find ./champs/error_champ -name '*.s')
	for CHAMP in $CHAMPS; do
		OUTPUT=$(./asm $CHAMP | grep -i 'error\|ошибка')
		if [ -z $CHAMP ]; then
			printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
			rm -rf ${CHAMP%.s}.cor
		else
			printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
		fi
	done
	$(find ./champs/error_champ -name '*.cor' | xargs rm -rf)
}

test_asm_correct() {
	CHAMPS=$(find ./champs/championships ./champs/examples -name '*.s')
	for CHAMP in $CHAMPS; do
		OUTPUT=$(./asm $CHAMP | grep -i 'error\|ошибка')
		if [[ $OUTPUT ]]; then
			printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
		else
			mv ${CHAMP%.s}.cor tmp.cor
			./asm_original $CHAMP > /dev/null
			hexdump -Cv tmp.cor > our_tmp
			hexdump -Cv ${CHAMP%.s}.cor > or_tmp
			DIFF=$(diff -U 2 or_tmp our_tmp)
			rm -rf tmp.cor ${CHAMP%.s}.cor or_tmp our_tmp
			if [[ $OUTPUT ]]; then
				printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
				echo $DIFF
			else
				printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
			fi
		fi
		rm -rf ${CHAMP%.s}.cor
	done
}

test_asm_gen()
{
	CHAMPS=$(find ./champs/gen_champs -name '*.s')
	ERROR=()
	CORRECT=()
	for CHAMP in $CHAMPS
	do
		OUTPUT=$(./asm_original $CHAMP | grep -i 'Error\|invalid')
		if [ "$OUTPUT" ]
		then
			ERROR+=($CHAMP)
		else
			CORRECT+=($CHAMP)
		fi
		rm -rf ${CHAMP%.s}.cor
	done
	for CHAMP in ${ERROR[*]}
	do
		OUTPUT=$(./asm $CHAMP | grep -i 'error\|ошибка')
		if [ -z "$OUTPUT" ]
		then
			printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
		else
			printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
		fi
		rm -rf ${CHAMP%.s}.cor
	done
	for CHAMP in ${CORRECT[*]}
	do
		OUTPUT=$(./asm $CHAMP | grep -i 'writing')
		if [ -z "$OUTPUT" ]
		then
			printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
		else
			printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
		fi
		rm -rf ${CHAMP%.s}.cor
	done
}

test_asm_valgrind()
{
	CHAMPS=$(find ./champs -name *.s)
	COUNT=0
	CORRECT=$(echo "0\n0")
	for CHAMP in $CHAMPS
	do
		OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all ./asm $CHAMP 2>&1 | grep -E "definitely|indirectly" | awk '{ print $4 }')
		if test "$OUTPUT" != "$CORRECT"
		then
			printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
			COUNT=$(($COUNT + 1))
		else
			printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
		fi
		rm -rf ${CHAMP%.s}.cor
	done
	echo $COUNT
}

test_disasm() {
	CHAMPS=$(find . -name "*.s")

	for CHAMP in $CHAMPS
	do
		OUTPUT=$(./asm_original $CHAMP | grep -i 'writing')
		if [ "$OUTPUT" ]
		then
			mv $CHAMP ${CHAMP%.s}_tmp.s
			hexdump -Cv ${CHAMP%.s}.cor > tmp_original
			./disassemble ${CHAMP%.s}.cor > /dev/null
			./asm $CHAMP > /dev/null
			hexdump -Cv ${CHAMP%.s}.cor > tmp_da
			DIFF=$(diff tmp_original tmp_da)
			rm -rf tmp_original tmp_da
			if [ -z "$DIFF" ]
			then
				printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
			else
				printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
				echo "$DIFF"
			fi
			mv ${CHAMP%.s}_tmp.s $CHAMP
		fi
		rm -rf ${CHAMP%.s}.cor
	done 2> /dev/null
}

test_disasm_valgrind()
{
	CHAMPS=$(find . -name *.s)
	COUNT=0
	CORRECT=$(echo "0\n0")
	for CHAMP in $CHAMPS
	do
		OUTPUT=$(./asm_original $CHAMP | grep -i 'writing')
		if [ "$OUTPUT" ]
		then
			cp $CHAMP ${CHAMP%.s}_tmp.s
			OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all ./disassemble ${CHAMP%.s}.cor 2>&1 | grep -E "definitely|indirectly" | awk '{ print $4 }')
			if test "$OUTPUT" != "$CORRECT"
			then
				printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
				echo "$OUTPUT"
				COUNT=$(($COUNT + 1))
			else
				printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
			fi
			rm -rf ${CHAMP%.s}.cor
			mv ${CHAMP%.s}_tmp.s $CHAMP
		fi
	done
	echo $COUNT
}

if [[ $# -eq 0 ]]; then
	echo 'options: asm, asm_valgrind, vm, disasm, disasm_valgrind'
	exit 0
fi

if [ $1 = 'asm' ]; then
	make -C ../Assembler re > /dev/null
	cp ../Assembler/asm . > /dev/null
	make -C ../Assembler fclean > /dev/null
	test_asm_error
	test_asm_correct
	test_asm_gen
	rm -rf asm > /dev/null
fi

if [ $1 = 'asm_valgrind' ]; then
	make -C ../Assembler re > /dev/null
	cp ../Assembler/asm . > /dev/null
	make -C ../Assembler fclean > /dev/null
	test_asm_valgrind
	rm -rf asm > /dev/null
fi

if [ $1 = 'disasm' ] ; then
	make -C ../Disassembler re > /dev/null
	cp ../Disassembler/disassemble . > /dev/null
	make -C ../Disassembler fclean > /dev/null
	test_disasm
	rm -rf disassemble > /dev/null
fi

if [ $1 = 'disasm_valgrind' ] ; then
	make -C ../Disassembler re > /dev/null
	cp ../Disassembler/disassemble . > /dev/null
	make -C ../Disassembler fclean > /dev/null
	test_disasm_valgrind
	rm -rf disassemble > /dev/null
fi
