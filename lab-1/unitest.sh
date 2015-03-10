#!/bin/bash
echo "unit testing ...."

array=(5 6 20)

for i in ${array[*]}
do
	yes $i | $EXEC_ARM ./fibseq_low
	ans_low=$?

	yes $i | $EXEC_ARM ./fibseq_high
	ans_high=$?
		
	ans_high=$(($ans_high<<8))
	ans=$(($ans_low|$ans_high))
	content=$(grep "^$i:" testbook)
	testans="${content#*:}"

	if [ $ans -eq $testans ]
		then
			echo "It's correct!"
		else
			echo "Something wrong! the answer is $testans"
			exit 1
	fi
done
