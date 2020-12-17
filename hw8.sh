#!/bin/bash

#Run 
for (( i=0; i<60; i++ ))
do

       cdate=`date +"%Y_%m_%d_%H_%M_%S"`
       index_page='https://finance.yahoo.com/most-active'
       hfn=yahoo_${cdate}.html
       wget -O $hfn $index_page

	#Tagsoup the file into xhtml
 	java -jar tagsoup-1.2.1.jar --files $hfn
 	#Python 
	filee=${hfn/.html/.xhtml}
	python3 hw8.py $filee
	#Sleep for 1 minute
	sleep 1m
done
