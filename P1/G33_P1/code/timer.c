#include <stdio.h>
#include <string.h>
#include <time.h>

clock_t start, stop;
double duration;
char file_name[12];
int ticks[8]={1000,500,200,200,200,200,100,100};	//initialize ticks
int k, f;
void count_time(int i);
void liner_search(int x, int m, int n, int a[10005]);
void run_prog();

int main()
{
	int i;
    strcpy(file_name,"p1_case0.txt");	//initialize the file name of incoming data
    
    //----------------------
    FILE *fp1, *fp2;
    freopen(file_name,"r",stdin);
    freopen("result.txt","w",stdout);
    //----------------------*/
    
    for (i=1;i<=8;i++)
    {
        file_name[7]=i+'0';	//set file name
        freopen(file_name,"r",stdin);
        count_time(i);	//run programs and get time
        fclose(stdin);
    }
    return 0;	
}
void count_time(int i)
{
     int ti;
     
     start=clock();
     for (ti=0;ti<=ticks[i-1];ti++) run_prog();
     stop=clock();
     duration=((double)(stop-start))/CLK_TCK;
     printf("No, %d : %.4lf\n", i, duration);
     return;
} 
/*
void run_prog()
{
    int i;    
    int m, n;
    int a[10005];		//array a[] is for storing data
    scanf("%d ", &n);   //n is the capacity of data 
    scanf("%d\n", &m);	//m is the number we are looking for
    for (i=1;i<=n;i++) scanf("%d ", &a[i]);	//get data
	f=0;	//f=0 means the number are not found yet. f=1 means we've found the number 
	for (i=1;i<=n;i++)	//scan numbers in data by order, maximum n times
		if (a[i]==m){	//if we find number m
						f=1;	//lable
						break;
					}
    return;
}
*/

void run_prog()
{
    int i, m, n;
    int a[10005];
    f=k=0;
    scanf("%d ", &n);
    scanf("%d\n", &m);
    for (i=1;i<=n;i++) scanf("%d ", &a[i]);
	liner_search(1, m, n, a);	//call function liner_search to complete the process
	return;
}
void liner_search(int x, int m, int n, int a[10005])	//x:we are checking xth number in the data array 
{
     if (a[x]==m){	//if we find number m
                      f=1;	//lable
                      k=x;	//return the answer
                      return;	//quit this recursive function
                      }
     if (x>n) return;	//if the largest number in data is still smaller the m, quit function
     liner_search(x+1, m, n, a);	//if we have not find the number m, continue searching
}

/*
void run_prog()
{
    int i, m, n;
    int a[10005];
    f=k=0;
    scanf("%d ", &n);
	scanf("%d\n", &m);
	for (i=1;i<=n;i++)
		scanf("%d ", &a[i]);
	int mid;	//mid: the middle number of the sequence now 
	int l,r;	//l: the starting of now using sequence; r: the ending of now using sequence
	l=1; r=n;	//initialize the searching range
	while ((l<r)||(l==r))	//if l>r, we are sure that m is not in data and we can stop searching
	{
          mid=a[(l+r)>>1];	//initializing min
          if (mid==m) break;	//if we find m in data, quit searching process
          if (mid>m) r=((l+r)>>1)-1;	//if m should be in the left part of now using sequence, change the searching range 
          if (mid<m) l=((l+r)>>1)+1;	//if m should be in the right part of now using sequence, change the searching range
    }
   // if (mid!=m) printf("NOT FOUND.\n");	//mid!=m stands for not finding m
   //    else printf("No.%d\n",(l+r)>>1);	
    return;
}
*/
