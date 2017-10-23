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

#include "Stack ADT.h"
#include "Create stack.h"
#include "Full stack.h"
#include "Push stack.h"
#include "Destroy stack.h"
#include "Empty stack.h"
#include "Pop stack.h"
#include "Stack Count.h"
#include "Stack top.h"

int main(void)
{
    bool done = false;   //�ŧi���A�����L���ܼ�done�Adone��False(0)
    char *dataPtr;        //�ŧi���A����ƪ������ܼ�
    dataPtr = (char*)malloc(sizeof(char));    //�ʺA�t�m�O����Ŷ���dataPtr(�b�D�{���ŧi�������ܼ�)


    STACK *stack;        //�ŧi���A��STACK�������ܼ�
    stack = createStack();

    //�}���ɮ�
    FILE *filePtr = fopen("test.txt","r");

//Statements
    //Create a stack and allocate memory for data


    //Ū��file�ɮסA�P�_�O�_��open parenthesis
    char openPare='{';
    char closePare='}';
    while((dataPtr=getc(FILE *filePtr)) != EOF || fullStack(stack)){
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
        printf("Error: Opening parenthesis not matched.")
    }
    else{
        printf("No braces. ^^");
    }

//Destroying Stack
    destroyStack(stack);
    return 0;
}
