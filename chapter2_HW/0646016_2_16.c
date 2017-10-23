/*�굲�@�~_HW2-16
  �m�W�G�i���p
  �Ǹ��G0646016
*/

/*�D�ءG
  Write a recursive C function to calculus the square root of a number using Newton's method.
  Test your function by printing the square root of 125, 763, and 997.

  Newton's method ���Y��:
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

  //num:���p�⪺��  ans:�}�ڸ�������  tol:���ttolerance

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
       printf("Please enter an integer�G");
    scanf("%f", &num);
    ans=2;
    tol=0.01;

    sR= squareRoot(num, ans, tol);
    printf("<<The square root of number�G%f>>\n\n", sR);
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
