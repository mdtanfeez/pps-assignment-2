#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
int n,m;	
float q,r;
scanf("%d %d",&n,&m);
scanf("%f %f",&q,&r);
printf("%d %d\n",n+m,n-m);
printf("%.1f %.1f\n",q+r,q-r);   
    return 0;
}
