#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[100],*rev[100];
    int n=0;
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    char *token=strtok(str," ");
    while(token!=NULL)
    {
        rev[n]=token;
        token=strtok(NULL," ");
        n++;
    }
    for(int i=n-1;i>=0;i--)
    {
        printf("%s",rev[i]);
    }
return 0;
}