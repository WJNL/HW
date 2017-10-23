/*�굲�@�~_HW2-22
  �m�W�G�i���p
  �Ǹ��G0646016
*/

/*�D�ءG
  Write the iterative version of the Fibonacci series algorithm using the hints given
  in Project 21. Note that step c in Project 21 will be different because factorial
  uses two recursive calls in the last statement
  (�NFibonacci Series�����j���A�H�|�N��g)

  Project 21�G
  a. Use a variable to replace the procedure call.
  b. Use a loop with the limit condition as the base case (or its complement).
  c. Enclose all executable statements inside the loop.
  d. Change the recursive call to an appropriate assignment statements.
  e. Use appropriate statements to reassign values to parameters.
  f. Return the value of the variable defined in step a.

  //�ϥ�Algorithm 2-2
*/

/*�ɥR�G
  ���j->��p��ΰ��榹�{���ɶ��ϥΨ�e�@�p��X���G�ΰѼơA�h��ܦb�p��L�{���{���ݱN���e���p�⵲�G�O���U��
        �h�����j
*/

#include <stdio.h>
#include <stdlib.h>
long fib(long num);

int main()
{
    int seriesSize=10,looper,count;
    printf("Print a Fibonacci series.\n");

    //Statements
    for(looper=0; looper<seriesSize; looper++){
        if(looper%5){
            printf(", %8ld", fib(looper));
            count++;
        }
        else{
            printf("\n%8ld", fib(looper));
            count++;
        }
    }//for

    printf("\n %d\n",count);
    return 0;
}

long fib(long num)
{
    //Statements
    if(num == 0 || num == 1){
        //Base case
        return num;
    }
    else{
        return (fib(num-1) + fib(num-2));
    }
}  //fib
