#include <stdio.h>
#include <string.h>
/*
Name: Tahmim Ahmed
Professor: Andrew Sohn
Class: CS 288
#Date: October 11, 2020
*/
int main(int argc, char **argv) {
   int i=0;
   printf("argc: address=%X value=%X\n", &argc, argc);
   printf("argv: address=%X value=%X\n\n", &argv, argv);
  while (*argv)
   {
       int l=strlen(*argv);
       int y;
       printf("arg+%d: Argument=%s Address=%X\n",i,*argv,argv);
      for(y=0;y<l;y++)
       {
           printf("Hex: %c (%x) Address: %X\n",*(*argv+y),*(*argv+y),&(*(*argv+y)));
       }
     printf("\n");
   	 argv++;
   	  i++;
   
   }

}



