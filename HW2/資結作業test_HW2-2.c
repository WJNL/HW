/*資結作業test_HW2-2
  解析：
  將值傳入函式後，回傳函式 (這邊使用到recusive遞迴概念)

*/

#include <stdio.h>
#include <stdlib.h>
int fun2(int, int);

int main()
{
    int x,y,reT;

    /*printf("Enter x：");
    scanf("%d", &x);
    printf("Enter y：");
    scanf("%d", &y);
    printf("x=%d\t y=%d\n",x,y);
*/
    x=15;
    y=3;

    reT = fun2(x,y);
    printf("return value： %d\n", reT);

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
