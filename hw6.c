/* HW6 read cafefully and follow all the instructions/comments
   this program compiles and runs as is although it's not doing much.
   DO NOT CHANGE THE SEED. Changing seed gives a different sequence of
   numbers but we want the same numbers for comparison purposes.

   FLOATING point radix sort requires some substantial changes to this code
   float n, lst[N],tmp[N];	
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <sys/time.h>
//return code
#define OK 1
#define NOK 0
//control this for number of elems u want to use
#define NELM 1000000  /* default 100 elements */
#define N 1048576		/* 2^20 or 1 meg elements  */
//#define N 2097152
//#define N 4194304
//#define N 8388608
//#define N 16777216
//#define N 33554432
void selection_sort();
void swap();

void merge_sort();
void msort_recursive();

void int_radix_sort();
void float_radix_sort();
void swap();
void self_check();
int rand(void);
void srand();
int rand_r();
void init_lst();
void print_lst();
 //for float do: float n, lst[N],tmp[N]
int n, lst[N], buf[N];
int main(int argc,char **argv) {

  long int del_sec,del_msec;
   struct timeval tv_s,tv_e;

  if (argc>1) n = atoi(argv[1]);
  else n = NELM;
  printf("n=%d\n",n);
  init_lst(lst,n);

    //radix sort
    gettimeofday(&tv_s, NULL);
    int_radix_sort(lst,buf,n,8);
    gettimeofday(&tv_e, NULL);
    printf("Radix Sort took: %ld milliseconds\n", (((tv_e.tv_sec - tv_s.tv_sec)*1000) + ((tv_e.tv_usec - tv_s.tv_usec)/1000)) );

    //merge sort
    /*gettimeofday(&tv_s, NULL);
     merge_sort(lst,0,n-1);
    gettimeofday(&tv_e, NULL);
    printf("Merge Sort took: %ld milliseconds\n", (((tv_e.tv_sec - tv_s.tv_sec)*1000) + ((tv_e.tv_usec - tv_s.tv_usec)/1000)) );
    */
    // selection sort
   /*gettimeofday(&tv_s, NULL);
     selection_sort(lst,n);
    gettimeofday(&tv_e, NULL);
    printf("Selection Sort took: %ld milliseconds\n", (((tv_e.tv_sec - tv_s.tv_sec)*1000) + ((tv_e.tv_usec - tv_s.tv_usec)/1000)) );
    */

    //printf("%ld seconds\n", (((tv_e.tv_sec - tv_s.tv_sec)*1000) + ((tv_e.tv_usec - tv_s.tv_usec) / 1000)) );

      //selection_sort(lst,n);
     // merge_sort(lst,0,n-1);
     //print_lst(lst,n);
    //int_radix_sort(lst,buf,n,8);
  //  float_radix_sort(lst,tmp,n);
  //  gettimeofday(&tv_e, NULL);
    //print_lst(lst,n);
    self_check(lst,n);
    /****
      PRINT elapsed time in sec and milli secs
    ****/

  //  print_lst(lst,n);
  /*
    self_check(lst,n);
    self_check(buf,n);
   */
  return 0;
}

void selection_sort(int lst[],int n){
  // fill here
  int i;
  int x;
  int min;
  for(i=0;i<n-1;i++){
      min=i;
      for(x=i+1;x<n;x++)
      {
          if(lst[x]<lst[min])
          {
              min=x;
          }
      }
      int temp=lst[min];
      lst[min]=lst[i];
      lst[i]=temp;
  }
}

void merge_sort(int lst[], int left, int right){
    if (left < right) {

        int mid = left + (right - left) / 2;
        merge_sort(lst, left, mid);
        merge_sort(lst, mid + 1, right);
        msort_recursive(lst, left, mid, right);
    }

}

//use recursion
void msort_recursive(int lst[], int left, int mid, int right){
    int i;
    int x;
    int y;
    int index1 = mid- left + 1;
    int index2= right - mid;

    int L[index1];
    int R[index2];

    for (i = 0; i < index1; i++)
        L[i] = lst[left + i];
    for (x = 0; x < index2; x++)
        R[x] = lst[mid + 1 + x];

    i = 0;
    x = 0;
    y = left;
    while (i < index1 && x < index2) {
        if (L[i] <= R[x]) {
            lst[y] = L[i];
            i++;
        }
        else {
            lst[y] = R[x];
            x++;
        }
        y++;
    }

    while (i < index1) {
        lst[y] = L[i];
        i++;
        y++;
    }

    while (x < index2) {
        lst[y] = R[x];
        x++;
        y++;
    }
}

//fix the bucket size to 256. run 4 passes where each pass processes 8 bits
//use lst and tmp only. do not use any more memory of size n.
void int_radix_sort(int lst[], int buf[], int n, int group) {
    //group=8;
    int i;
    int j;
    int mask=255;
    int buckets=256;
    int flag,*src,*dst;
    src=NULL;
    dst=NULL;
    int track=0;
    int cnt[buckets];
    int map[buckets];
    for (i=0;i<32;i=i+group)
    {
        if(track==0){
            src=lst;
            dst=buf;
            track = 1;
        }
        else
        {
            src=buf;
            dst=lst;
            track=0;
        }

        for(j=0;j<buckets;j++){
            cnt[j]=0;
        }
        for(j=0;j<n;j++){
            cnt[src[j]>>i&mask]++;

        }
        map[0]=0;
        for(j=1;j<buckets;j++){
            map[j]=map[j-1]+cnt[j-1];
        }
        for(j=0;j<n;j++){
            dst[map[(src[j]>>i)&mask]++]=src[j];
        }

        for(j=0; j<n; j++)
        {
            lst[j] = dst[j];
        }

    }
    // set src/dst to lst/buf depending on iter number
// fill here with what's discussed in class
// ...
}




void print_lst(int *l,int n){
  int i;
  for (i=0; i<n; i++) {
    printf("%d\n",l[i]);
  }
  printf("\n");
}

void init_lst(int *l,int n){
  int i;
  //  int seed = time(0) % 100;	/* seconds since 1/1/1970 */
  //  printf ("seed=%d\n", seed);
  srand(1234);			/* SEED */
  for (i=0; i<n; i++) {
    l[i] = rand();
    //printf("%d %d\n",i,l[i]);
  }

}

void self_check(int *lst,int n) {
  int i,j,flag=OK,*lstp;

  lstp = lst;
  for (i=0;i<n-1;i++)
     if (lstp[i] > lstp[i+1]) { flag = NOK; break; }

  if (flag == OK) printf("sorted\n");
  else printf("NOT sorted at %d\n",i);
}


/* End of file */
