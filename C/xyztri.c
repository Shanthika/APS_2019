#include<stdio.h>
int main()
{
  int a,b,c; 
  printf("enter the value of side\n");
  scanf("%d%d%d",&a,&b,&c);
  if((a+b)>c||(b+c)>a||(a+c)>b)
 {
  {
    printf(" forms triangle\n");
   }
   if(a=b&&b=c&&a=c)
    {
      printf("form equilateral triangle\n");
     }
    else if(a=b&&b!=c)
     {
       printf("forms issosalate triangle\n");
      }
     else if(a!=b&&b!=c&&a!=c)
     {
       printf("forms scalen\n");
      }
     else
     {
       printf("forms right angle tringle\n");
      }
  } 
  else
  {
    printf("do not forms triangle\n");
   }
  
}

