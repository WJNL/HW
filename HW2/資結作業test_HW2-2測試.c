/*�굲�@�~test_HW2-2_���������D
  �D�ءG
  int fun1(int x, int y)
  {
    if(x == 0)
       return y;
    else
       return fun1(x - 1,  x + y);
  }
  ����
  The function fun() calculates and returns ((1 + 2 �K + x-1 + x) +y) which is x(x+1)/2 + y.
  For example if x is 5 and y is 2, then fun should return 15 + 2 = 17.
*/

#include <stdio.h>
#include <stdlib.h>
int fun2(int, int);

int main()
{
    int x,y,reT;

    /*printf("Enter x�G");
    scanf("%d", &x);
    printf("Enter y�G");
    scanf("%d", &y);
    printf("x=%d\t y=%d\n",x,y);
*/
    x=15;
    y=3;

    reT = fun2(x,y);
    printf("return value�G %d\n", reT);

}

//algorithm

int fun2(int x, int y)
{
    int a,b,c;
    printf("x= %d\t y= %d\n",x,y);
    if(x == 0)
	   return y;
    else
	   return fun2(x - 1, x + y);
}
