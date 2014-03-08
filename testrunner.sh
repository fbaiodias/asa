#!/bin/bash

echo " Ficheiro que queres compilar: (ex: asa.cpp ou oMeuFicheiroLindo.c) "
read filename

s=0
passados=0
falhados=0
TLE=0
TLE_LIMIT=1.75
TLE_RESULT=-1

if find $filename; then
	
	if [[ $filename == *.cpp ]]; then
		if g++ -O3 -ansi -Wall $filename -lm -o proj; then
			s=1
		else
			s=-1
		fi
	else
		if [[ $filename == *.c ]]; then
			if gcc -O3 -ansi -Wall $filename -lm -o proj; then
				s=1
			else
				s=-1
			fi
		else
			echo "Ficheiro com extensão diferente de .c ou .cpp"
		fi
	fi

	if [ "$s" -eq 1 ]; then
		echo "Running tests"
		for file_in in tests/*.in 
		do
			file_out=${file_in//.in/.out}
			file_expected=${file_in//.in/.expected}
			file_diff=${file_in//.in/.diff}

			testname=${file_in//.in/}
			testname=${testname//test/}

			echo -e "\nRunning test $testname..."
			/usr/bin/time -f "%e" ./proj < $file_in > $file_out 2>tempo.time
			timmer=$(head -n 1 tempo.time)

			TLE_RESULT=$(echo $timmer'>'$TLE_LIMIT | bc -l)

			if [ "$TLE_RESULT" -eq 1 ]; then
				echo "TLE - TIME LIMIT EXCEEDED but"
				TLE=$[TLE+1]
			fi

			if diff $file_out $file_expected > $file_diff; then
				echo "Test passed!!! in $timmer s"
				rm $file_diff
				rm $file_out
				passados=$[passados+1]
			else
				echo "Incorrect output :("
				rm $file_diff
				rm $file_out
				#mv $file_diff .
				#mv $file_out .
				falhados=$[falhados+1]
			fi

		done
		rm proj
		echo ""
		echo "+----------+----------+"
		echo "|      RESULTADOS     |"
		echo "+----------+----------+"
	 	echo "| Passados | Falhados |"
		echo "+----------+----------+"
		echo "|    $passados    |     $falhados    |"
		echo "+----------+----------+"
		if [ "$TLE" -gt 0 ]; then
			echo "+      TLE: $TLE         +"
			echo "+----------+----------+"
		fi
	else
		echo "Compile Time Error :("
	fi
else
	echo "+-----------------------------+"
	echo "| Ficheiro não encontrado :'( |"
	echo "+-----------------------------+"
fi
