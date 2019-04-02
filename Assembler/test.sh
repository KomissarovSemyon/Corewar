test_error()
{
    CHAMPS=$(find champs -d 1 -name '*.s')
    ERROR=()
    NOT_VALID=()
    for CHAMP in $CHAMPS
    do
        OUTPUT=$(./asm_original $CHAMP | grep -i 'error')
        if [ -z "$OUTPUT" ]
        then
            NOT_VALID+=($CHAMP)
        else
            ERROR+=($CHAMP)
        fi
    done
    for CHAMP in ${ERROR[*]} ; do
        OUTPUT=$(./asm $CHAMP | grep -i 'error\|ошибка')
        if [ -z "$OUTPUT" ] ; then
            printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
        else
            printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
        fi
    done 2> /dev/null
    for CHAMP in ${NOT_VALID[*]} ; do
        OUTPUT=$(./asm $CHAMP | grep -i 'error\|ошибка')
        if [ -z "$OUTPUT" ] ; then
            printf "%s: \e[1;33mOK(it creates a file, but it's ok)\e[0m\n" "$CHAMP"
        else
            printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
        fi
    done 2> /dev/null
}

test_gen()
{
    CHAMPS=$(find gen_champs -name '*.s')
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
            printf "\e[1;32mOK\e[0m %s\n" "$CHAMP"
		fi
	done
	for CHAMP in ${CORRECT[*]}
	do
		OUTPUT=$(./asm $CHAMP | grep -i 'writing')
		if [ -z "$OUTPUT" ]
		then
            printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
        else
            printf "\e[1;32mOK\e[0m %s\n" "$CHAMP"
		fi
	done
}

test_correct()
{
    # CHAMPS=$(find . -mindepth 3 -maxdepth 3 -name '*.s' | cut -c 3-)
    CHAMPS=$(find . -mindepth 3 -maxdepth 5 -name '*.s' | cut -c 3-)
    for CHAMP in $CHAMPS
    do
        OUTPUT=$(./asm_original $CHAMP | grep -i 'Writing')
        if [ -z "$OUTPUT" ]
        then
            printf "\e[1;31mERROR IN FILE: %s\e[0m\n" "$CHAMP"
        else
            mv ${CHAMP%.s}.cor tmp.cor
            OUTPUT=$(./asm $CHAMP | grep -i 'Writing')
            if [ -z "$OUTPUT" ]
            then
                printf "\e[1;31mYOUR PROGRAMM DETECTED ERROR IN FILE: %s\e[0m\n" "$CHAMP"
            else
                # echo $OUTPUT
                hexdump -Cv tmp.cor > tmp1
                # hexdump -Cv .cor > tmp2
                # uncomment when finish
                hexdump -Cv ${CHAMP%.s}.cor > tmp2
                DIFF=$(diff tmp1 tmp2)
                if [ -z "$DIFF" ]
                then
                    printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
                else
                    printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
                    echo "$DIFF"
                fi
            fi
            # rm -rf tmp.cor tmp1 tmp20
        fi
    done
}

test_valgrind()
{
    CHAMPS=$(find . -name *.s)
    COUNT=0
    CORRECT=$(echo "definitely lost: 0 bytes in 0 blocks\nindirectly lost: 0 bytes in 0 blocks")
    CORRECT=$(echo "0\n0")
    for CHAMP in $CHAMPS
    do
        #OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all ./asm $CHAMP 2>&1 | grep -E "definitely|indirectly" | cut -c14-)
		OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all ./asm $CHAMP 2>&1 | grep -E "definitely|indirectly" | awk '{ print $4 }')
        if test "$OUTPUT" != "$CORRECT"
        then
            printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
            # echo "$OUTPUT"
            COUNT=$(($COUNT + 1))
        else
            printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
        fi
    done
    echo $COUNT
}

if [[ $# -eq 0 ]] ; then
    echo 'options: all, error, correct, gen, valgrind'
    exit 0
fi

if [ $1 = 'all' ] ; then
    test_error
    test_gen
    test_correct
fi

if [ $1 = 'error' ] ; then
    test_error
fi

if [ $1 = 'correct' ] ; then
    test_correct
fi

if [ $1 = 'gen' ] ; then
    test_gen
fi

if [ $1 = 'valgrind' ] ; then
    test_valgrind
fi
