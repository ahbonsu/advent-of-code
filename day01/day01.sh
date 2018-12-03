#!/bin/bash

if [ -z "$1" ]; then
	echo "no input!";
	exit 1;
fi



frequency=0
regex='^[+-]?[0-9]+([.][0-9]+)?$'

pt2_solved=false

array=()
array+=(0)

done=0

while [ "$done" -eq 0 ] ; do
	while read -r line; do
		if ! [[ $line =~ $regex ]]; then
			echo "invalid input: $line"
			exit 1;
		fi
		number=$line
		if [[ $line == +* ]]; then
			number=$(echo $line | tr -d '+')
		fi
	
		frequency=$(( $frequency + $number ))
	
		if [ "$(printf "%s\n" ${array[@]} | grep -w ^$(echo $frequency | sed 's/\-/\\\-/g')$ | wc -l)" -gt 0 ]; then
			echo "result $frequency"
			done=1
			break
		else
			array+=($frequency)
		fi
	
	done < $1
done
