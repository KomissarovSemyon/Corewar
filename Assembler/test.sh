test_error()
{
    CHAMPS=$(find . -d 2 -name '*.s')
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

if [[ $# -eq 0 ]] ; then
    echo 'options: all, error, correct'
    exit 0
fi

if [ $1 = 'all' ] ; then
    coproc test_error 2> /dev/null
    test_correct
fi

if [ $1 = 'error' ] ; then
    # coproc test_error 2> /dev/null
    test_error
fi

if [ $1 = 'correct' ] ; then
    test_correct
fi
