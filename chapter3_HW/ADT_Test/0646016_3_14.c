/*��Ƶ��c_chapter3.5_Stack����_�ק�
  program_3-15
  Title�GHW3_Stack����(�P�_�r��)

  Function: �Ntemp�}�C�����r��A�P�_�O�_��"{"�άO"}"�A�s�Jstack
  (pre)  ��J�@�s��Ʀr
  (post) �A�˼Ʀr��J����
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxSize 500

#include "stacksADT.h"
#include "P3-07.h"		/* Create Stack */#include "P3-08.h"		/* Push Stack */#include "P3-09.h"		/* Pop Stack */#include "P3-10.h"		/* Retrieve Stack Top */#include "P3-11.h"		/* Empty Stack */#include "P3-12.h"		/* Full Stack */#include "P3-13.h"		/* Stack Count */#include "P3-14.h"		/* DestroyStack */

int main(void)
{
    bool done = false;
    char temp[maxSize];
    int i=0,j=0;
    int *dataPtr;

    /*Create a stack and allocate memory for data*/
    dataPtr = (int*)malloc(sizeof(int));

    STACK *stack;
    stack = createStack();

    /* opening file for reading */
    FILE *filePtr = fopen("test.txt","r");

   /* �NfilePtr�ҫ��V���ɮפ��r���s��itemp�}�C */
   while((temp[i] = fgetc(filePtr)) != EOF){
        i++;
   }

    /*Ū��file�ɮסA�P�_�O�_��open parenthesis*/
    char openPare='{';
    char closePare='}';

    //�n��dataPtr�̧ǫ��Vtemp�h�P�_
    while((dataPtr= temp[j])){
        printf("%s", *dataPtr);
        if(*dataPtr == openPare){
            pushStack(stack, dataPtr);
        }
        else{
            if(*dataPtr == closePare){
                //��Ū��close parenthesis�A�T�{stack���O�_��open parenthesis
                if(emptyStack(stack)){
                    //(�p�Gstack�O�Ū��|�^��1�A���closePare�S���t���openPare)�h�L�XError
                    printf("Error: Closing parenthesis not matched.");
                }
                else{
                    //�p�Gstack���٦��x�s��openPare�|�^��0�A���closePare�i�t��(�h�h���@��stack����openPare)
                    popStack(stack);
                }
            }
        }
    }//while

    if(!emptyStack(stack)){
        printf("Error: Opening parenthesis not matched.");
    }


//Destroying Stack
    destroyStack(stack);
    return 0;
}
