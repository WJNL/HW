/*�굲�@�~test_HW2-2
  �ѪR�G
  �N�ȶǤJ�禡��A�^�Ǩ禡 (�o��ϥΨ�recusive���j����)

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
    int a,b,c,d;
    printf("\nx=%d , y=%d\n", x, y);

    if(x<y)
    {
        printf("\nx=%d , y=%d\n", x, y);
        return -3;
    }
    else
    {
        a=x-y;
        b=y+3;
        printf("<<a= %d\t b=%d>>\n",a,b);
        c= fun2(a,b);
        printf("fun2(%d,%d) = %d\n", a, b, c);
        d= c+y;
        printf("(fun2(x-y,y+3)+y= %d\n", d);

        return (d);
    }
}
