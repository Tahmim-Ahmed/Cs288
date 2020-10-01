#!/bin/bash
#Name: Tahmim Ahmed
#Professor: Andrew Sohn
#Class: CS 288
#Date: September 27 2020


function breadth()
{
    open=$3
    d=$1
    b=$2

    for((i=0;i<d;i++))
    do
	    temp_open=()
	 
	    for x in ${open[@]}
	    do
           temp=()
	       for((j=0;j<b;j++))
	       do
		   echo mkdir $x/$j
	            mkdir -p $x/$j
	           # temp+=($x/$j)

	        done
	        temp_open+=(${temp[@]})
	   done
       open=(${temp_open[@]})
    done
}

function depth(){

    local dir=$3
    local d=$1
    local b=$2
    
    echo "mkdir " $dir
    #mkdir -p $dir
	
        if [[ $d -le 0 ]];then
                return
        fi
	local i;
	for((i=0;i<$b;i++))
	do
	    depth $((d-1)) $b $dir/$i
	done
}

function main()
{

        if [ "$4" == "breadth" ];
        then
		breadth $1 $2 $3
	fi

	if [ "$4" == "depth" ];
	then
	    depth $1 $2 $3
	fi
	
}

main $@
