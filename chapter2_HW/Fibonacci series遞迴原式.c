/*資結作業_HW2-22
  姓名：張完如
  學號：0646016
*/

/*題目：
  Write the iterative version of the Fibonacci series algorithm using the hints given
  in Project 21. Note that step c in Project 21 will be different because factorial
  uses two recursive calls in the last statement
  (將Fibonacci Series的遞迴式，以疊代改寫)

  Project 21：
  a. Use a variable to replace the procedure call.
  b. Use a loop with the limit condition as the base case (or its complement).
  c. Enclose all executable statements inside the loop.
  d. Change the recursive call to an appropriate assignment statements.
  e. Use appropriate statements to reassign values to parameters.
  f. Return the value of the variable defined in step a.

  //使用Algorithm 2-2
*/

/*補充：
  遞迴->當計算或執行此程式時須使用到前一計算出結果或參數，則表示在計算過程中程式需將先前的計算結果記錄下來
        則為遞迴
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
