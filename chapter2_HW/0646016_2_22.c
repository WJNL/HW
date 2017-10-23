/*資結作業_HW2-22
  姓名：張完如
  學號：0646016
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
    //print Fibonacci series
    for(j=0;j<size;j++){
        printf("%d\t",a[j]);
    }

    return 0;
}

