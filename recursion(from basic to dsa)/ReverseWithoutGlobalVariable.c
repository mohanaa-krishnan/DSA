// Online C compiler to run C program online
#include <stdio.h>
#include<ctype.h>
#include<math.h>
int reverse(int n);
int Base(int n);
int main() {
   int n;
   scanf("%d",&n);
   printf("%d",reverse(n));
   

    return 0;
}

int reverse(int n)
{
    if(n%10==n)
    {
        return n;
    }
    int base=Base(n);
    
    
    int ans= (n%10)*pow(10,base) + reverse(n/10);
    //printf("%d\n",ans);
    return ans;
}

int Base(int n)
{
    int l=0;
    while(n%10!=n)
    {
        l++;
        n=n/10;
    }
    return l;
}