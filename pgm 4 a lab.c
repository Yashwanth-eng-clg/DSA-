#include <stdio.h>
#include <stdlib.h>

void TOH(int n,char s,char d,char t)
{
    if(n==1){
        printf("\n move disc 1 %c -> %c ",s,d);
        return ;
    }
        TOH(n-1,s,t,d);
        printf("\n move disc %d disc from %c -> %c\n",n,s,d);
        TOH(n-1,t,d,s);

}
 int main()
{
    int n;
    printf("\n enter no of discs:");
    scanf("%d",&n);
    printf("\n sequence of moves:\n");
    TOH(n,'s','d','t');
    int totalmoves = (1 << n)-1;
    printf("\n total number of moves =%d\n",totalmoves);
    return 0;
}
