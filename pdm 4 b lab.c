#include <stdio.h>
#include <stdlib.h>

int GDC(int a,int b)
{
    if(a==0) return b;
    return GDC(b%a,a);
}
int main()
{
    int a,b;
    printf("\n valur for a&b\n");
    scanf("\n%d%d",&a,&b);
    printf("\n GDC of %d&%d is %d",a,b,GDC(a,b));
    return 0;
}
