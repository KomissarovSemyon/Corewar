CHAMPS=$(find ./champs_tmp -name '*.s' | cut -c 3-)
for CHAMP in $CHAMPS
do
	./asm ${CHAMP} > out
	if cat out | grep "Writing"
	then
		./corewar_original -d 100 ${CHAMP%.s}.cor > out
		if cat out | grep "Introducing"
		then
			cp ${CHAMP%.s}.cor ch/
		fi
	fi
done
