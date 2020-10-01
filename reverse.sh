#!/bin/bash
#Name: Tahmim Ahmed
#Professor: Andrew Sohn
#Class: CS 288
#Date: September 20 2020

function main()
{
    local unknown="$1"
    [[ -d $unknown ]] && {
    dlist=`ls $unknown`
    local array=()
    for x in $dlist
    do
         array+=("$x")
    done

    reverse $array
   }

}

function reverse()
{
    local a=0
    local b=`expr "${#array[@]}" - 1`
    local mid=`expr "${#array[@]}" / 2`
   
    while  [ "$a" != "$mid" ] 
    do
    local temp="${array[$a]}"
    array[$a]="${array[$b]}"
       array[$b]=$temp
    ((b=b-1))
    ((a=a+1))
   done

   rev=()
   for y in "${array[@]}"
   do
       rev+="$y "
      ((count=count+1))
   done
   echo "\"${rev[@]}\""
}

main $@ 

