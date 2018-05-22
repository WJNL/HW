/*資結作業_HW2-22
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

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size,i,j;
    int *a;
    a = (int*)malloc(sizeof(int)*size);

    printf("Please enter series size：");
    scanf("%d", &size);


    printf("\nPrint a Fibonacci series.\n");
    //Statements
    for(i=0;i<size;i++){
        if(i==0){
            a[i]=0;
        }
        else if(i==1 || i==2){
            a[i]=1;
        }
        else{
            a[i]=a[i-1] + a[i-2];
        }
    }

    for(j=0;j<size;j++){
        printf("%d\t",a[j]);
    }

    return 0;
}

