/*資結作業_HW2-16
  姓名：張完如
  學號：0646016
*/

/*題目：
  Write a recursive C function to calculus the square root of a number using Newton's method.
  Test your function by printing the square root of 125, 763, and 997.

  Newton's method 關係式:
  squareRoot(num, ans, tol)=
        //ans                                             if |ans^2 - num| <= tol //
        //squareRoot(num, (ans^2 + num)/(2*ans), tol)      otherwise              //
*/

/*Algorithm newton(num,ans,tol)
    if(|ans^2 - num| <= tol){
        return ans
    }
    else{
        return squareRoot(num, (ans^2 + num)/(2*ans), tol)
    }
    end if
  end algorithm

  //num:欲計算的值  ans:開根號之次方  tol:公差tolerance

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float squareRoot(float, float, float);

int main()
{
    int i;
    float num,ans,tol,sR;

    for(i=0;i<3;i++){
       printf("Please enter an integer：");
    scanf("%f", &num);
    ans=2;
    tol=0.01;

    sR= squareRoot(num, ans, tol);
    printf("<<The square root of number：%f>>\n\n", sR);
    }

}

float squareRoot(float num, float ans, float tol)
{
    //printf("num=%f\t ans=%f\t tol=%f\n\n", num, ans, tol);
    if(fabs(pow(ans,2)-num) <= tol){
        return ans;
    }
    else{
        return squareRoot(num, (pow(ans,2)+num)/(2*ans), tol);
    }
}
