#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 256
#define MAX_FIELDS 5 /* 5 fields: views,user,upload_time,duration,title */

struct clip *build_a_lst();
struct clip *append();
int find_length();
void print_lst();
void split_line();

struct clip {
    char *views;
    char *user;
    char *upload_time;
    char *duration;
    char *title;
    struct clip *next;
} *head;

int main(int argc, char **argv) {
    int n;
    head = build_a_lst(*(argv+1));
    // n = find_length(head);
    //printf("%d clips\n",n);
    print_lst(head);    /* prints the table */
    return 0;
}

struct clip *build_a_lst(char *fn) {
    FILE *fp;
    struct clip *hp;
    char *fields[MAX_FIELDS];
    char line[LINE_LENGTH];
    int cnt=0;
    hp=NULL;
    fp=fopen(fn,"r");
    fp = fopen(fn, "r");
    if(fp == NULL) {
        printf("Unable to Open File");
    }
    else{
        while(!feof(fp)){
            if((fgets(line, LINE_LENGTH, fp)) != NULL){
                split_line(fields, line);
                hp=append(hp,fields);
            }
        }
    }
    // open fn
    // while no more lines
    // read a line
    // split the line into five substrings/int and store them in a struct
    // append - add the struct at the end of the list
    // return the head pointer holding the list

    return hp;
}

/* fields will have five values stored upon return */
void split_line(char **fields,char *line) {
    int i=0;
    char *token, *delim;
    delim = ",\n";
    token=strtok(line,delim);
    while(token!=NULL && i<5){
        fields[i]=token;
        token=strtok(NULL,delim);
        i++;
    }

    /*
           call strtok(line, delim);
           repeat until strtok returns NULL using strtok(NULL, delim);
           use the routine we wrote in class.
    */
}

/* set five values into a clip, insert a clip at the of the list */
struct clip *append(struct clip *hp,char **five) {
    struct clip *cp,*tp;

    cp=tp=NULL;
    tp=malloc(sizeof(struct clip));
    cp=malloc(sizeof(struct clip));
    tp->next= NULL;
    cp->next= NULL;

    tp->user= malloc(strlen(five[1]));
    tp->duration=malloc(strlen(five[3]));
    tp->title=malloc(strlen(five[0]));
    tp->views= malloc(strlen(five[4]));
    tp->upload_time= malloc(strlen(five[2]));

    strcpy(tp->views, five[4]);
    strcpy(tp->user, five[1]);
    strcpy(tp->duration, five[3]);
    strcpy(tp->title, five[0]);
    strcpy(tp->upload_time, five[2]);

    if(hp==NULL)
    {
        cp=hp=tp;
    }
    /*else{
        cp=hp;
        while(cp->next!=NULL){
            cp=cp->next;
        }
        cp->next=tp;
        cp=cp->next;
    }*/
   
    else{
        cp=tp;
        cp->next=hp;
        hp=cp;

    }

    return hp;

    /*
       malloc tp
       set views using atoi(*five)
       malloc for four strings.
       strcpy four strings to tp
       insert tp at the end of the list pointed by hp
       use cp to traverse the list
   */
}

void print_lst(struct clip *cp) {
    /*
        use a while loop and the statement below to print the list
        cp->views,cp->user,cp->id,cp->title,cp->time;
    */

    if(cp==NULL) {
        printf("CP is NULL\n");
    }
    while(cp!=NULL){
        printf("%s,%s,%s,%s,%s\n",cp->views,cp->user,cp->duration,cp->title,cp->upload_time);
        cp=cp->next;
    }

}































