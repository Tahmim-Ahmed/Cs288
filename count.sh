#!/bin/bash
#Name: Tahmim Ahmed
#Professor: Andrew Sohn
#Class: CS 288
#Date: September 20 2020
letters=(a b c d e f g h i j k l m n o p q r s t u v w x y z)
traverse()
{
   
   local unknown=$1
   lst=`ls $unknown`
   for l  in "${letters[@]}"
   do
       count=0
       for c in $lst
       do
	   if [ "$l" == "${c:0:1}" ]; then
	       ((count=count+1))
	   fi
       done
       echo "$l $count"
   done
    
}

traverse /bin
