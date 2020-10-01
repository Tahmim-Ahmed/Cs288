#!/bin/bash
#Name: Tahmim Ahmed
#Professor: Andrew Sohn
#Class: CS 288
#Date: September 20 2020 
function average(){
	count=0
	i=0
	sum=0
	while read line
	do val=(`echo $line`)
	
    		if [ $count -gt 0 ] 
    		then   
		    asize[ $i ]="${val[4]}"
    		    aname[ $i ]="${val[8]}"
		    sum=`expr $sum + ${val[4]}`
    		fi  
    	      ((count=count+1 ))
	      ((i=i+1))
	done < <(ls -l $1)
	
       size="${#asize[@]}"
       average=`expr $sum / $size`
}
function filter ()
{
       fil=()
       for((i=1;i<="${#asize[@]}";i++)) 
	do
	    if [ ${asize[${i}]} -gt  $average ]
	    then
		fil+="${aname[${i}]} "
	     fi
	done

       lst=("${fil[@]}")
       echo "\"$lst\""


}

function main()
{
    average $1
    filter $1

}
main $1
