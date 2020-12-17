# CS288 Homework 8
# Read the skeleton code carefully and try to follow the structure
# You may modify the code but try to stay within the framework.

import sys
import os
#import commands
import re
import sys

import pymysql

from xml.dom.minidom import parse, parseString

# for converting dict to xml 
#from cStringIO import StringIO
#from xml.parsers import expat

def get_elms_for_atr_val(tag,atr,val):
   lst=[]
   elms = dom.getElementsByTagName(tag)
   for i in range(len(elms)):
      lst.append(elms[i])

   return lst

# get all text recursively to the bottom
def get_text(e):
   lst=[]
   if e.nodeType in (3,4):
      lst.append(e.nodeValue)
   else:
      for x in e.childNodes:
         lst=lst+get_text(x)
        
   return lst

# replace whitespace chars
def replace_white_space(str):
   p = re.compile(r'\s+')
   new = p.sub(' ',str)   # a lot of \n\t\t\t\t\t\t
   return new.strip()

# replace but these chars including ': and .'
def replace_non_alpha_numeric(s):
   p = re.compile(r'[^a-zA-Z0-9.:-]+')
   #   p = re.compile(r'\W+') # replace whitespace chars
   new = p.sub(' ',s)
   return new.strip()

# convert to xhtml
# use: java -jar tagsoup-1.2.jar --files html_file
def html_to_xml(fn):
   # ............
   return xhtml_file

def extract_values(dm):
   lst_td= []
   ltrs = get_elms_for_atr_val('tr','class','most_actives')
   l=get_text(ltrs[1])
   # print(l)
   #print("length is "+str(len(ltrs)))
   del ltrs[0]
   #for tr in ltrs:
   data= map(lambda e: get_text(e), ltrs)
   result=list(data)
   #print(result)

   return result

# mysql> describe most_active;
def insert_to_db(l,tbl):
   mydb = pymysql.connect("localhost","root","cs288","stock_market")
   mycursor = mydb.cursor()
   # Create Table first
   s = "CREATE TABLE IF NOT EXISTS " + tbl + " (Symbol VARCHAR(80), Name VARCHAR(80), Price VARCHAR(80), Chng VARCHAR(80), pChng VARCHAR(80), Volume VARCHAR(80), AvgVol VARCHAR (80), Market_Cap VARCHAR(80))"
   mycursor.execute(s)

   sql = "INSERT INTO " + tbl + " (Symbol, Name, Price, Chng, pChng, Volume, AvgVol, Market_Cap) VALUES (%s, %s, %s, %s, %s, %s, %s, %s)"
   val = []
   count=0
   print("values to insert are:")
   for item in l:
      val.append((item[0], item[1], item[2], item[3], item[4], item[5], item[6], item[7]))
      print(val[count])
      count+=1
      

   mycursor.executemany(sql, val)
   mydb.commit()
   print(mycursor.rowcount, "rows were inserted.")
   return mycursor

# show databases;
# show tables;
def main():
   xhtml_fn = sys.argv[1]
   fn = xhtml_fn.replace('.xhtml','')
   #xhtml_fn = html_to_xml(html_fn)

   global dom
   dom = parse(xhtml_fn)

   lst = extract_values(dom)

   #make sure your mysql server is up and running
   cursor = insert_to_db(lst,fn) # fn = table name for mysql

   # l = select_from_db(cursor,fn) # display the table on the screen
   # make sure the Apache web server is up and running
   # write a PHP script to display the table(s) on your browser
   #return xml
# end of main()

if __name__ == "__main__":
    main()

# end of hw7.py
