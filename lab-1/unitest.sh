#!/bin/bash
echo "unit testing ...."

array=(5 6 9)

for i in ${array[*]}
do
	yes $i | qemu-arm -L /usr/arm-linux-gnueabihf ./fibseq
	ans=$?
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
