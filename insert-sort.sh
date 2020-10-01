#!/bin/bash
#Name: Tahmim Ahmed
#Professor: Andrew Sohn
#Class: CS 288
#Date: September 20 2020 

function sort(){
    array=("$@");
    n="${#array[@]}"
	for ((i = 0; i<n; i++))
	do
	    for((j=i; j<n; j++))
	    do
		if [ "${array[$i]}" -gt "${array[$j]}" ];
		then
		    temp="${array[$i]}"
		    array[$i]="${array[$j]}"
		    array[$j]="$temp" 		    
		fi
	    done
	   
	done
	echo ${array[@]};
}

sort $@

