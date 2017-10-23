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

#include <stdio.h>
#include <stdlib.h>
//long fib(long num);

int main()
{
    int seriesSize,i;
    int *a;

    printf("Please enter series size�G");
    scanf("%d", &seriesSize);
    *a = malloc(sizeof(int)*seriesSize);


    printf("\nPrint a Fibonacci series.\n");
    //Statements
    for(i=0;i<seriesSize;i++){
        if(i==0){
            a[i]=0;
        }
        else if(i==1 || i==2){
            a[i]==1;
        }
        else{
            a[i]=a[i-1] + a[i-2];
        }
    }

    for(i=0;i<seriesSize;i++){
        printf("%d\t",a[i]);
    }

    //printf("\n");
    return 0;
}

/*long fib(long num)
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
*/
