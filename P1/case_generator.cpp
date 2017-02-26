#include <cstdlib>
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{
    //----------------------
    FILE *fp1;
    freopen("p1_case8.txt","w",stdout);
    //----------------------*/
    
    int dura;
    int k;
    int i;
    srand((int)time(0));
    k=((int)rand())%1000;
    printf("%d %d\n", 10000, (int)rand());
    for (i=1;i<=10000;i++)
    {
        dura=((int)rand())%1000;
        k+=dura;
        printf("%d\n", k);
    }
    return 0;
}
     
    
