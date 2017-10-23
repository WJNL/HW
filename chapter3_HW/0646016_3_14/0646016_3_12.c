/*�굲�@�~_HW3-12
  �m�W�G�i���p
  �Ǹ��G0646016
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxSize 500

#include "stacksADT.h"
#include "P3-07.h"		/* Create Stack */#include "P3-08.h"		/* Push Stack */#include "P3-09.h"		/* Pop Stack */#include "P3-10.h"		/* Retrieve Stack Top */#include "P3-11.h"		/* Empty Stack */#include "P3-12.h"		/* Full Stack */#include "P3-13.h"		/* Stack Count */#include "P3-14.h"		/* DestroyStack */

int main(void)
{
    char temp[maxSize];
    int i=0,j=0;
    char *dataPtr;

    /*Create a stack and allocate memory for data*/
    dataPtr = (char*)malloc(sizeof(char));

    STACK *stack;
    stack = createStack();

    /* opening file for reading */
    FILE *filePtr = fopen("test.txt","r");

   /* �NfilePtr�ҫ��V���ɮפ��r����O�H�r���s��itemp�}�C */
   while((temp[i] = fgetc(filePtr)) != EOF){
        i++;
   }

    /*Ū��file�ɮסA�P�_�O�_��open parenthesis*/
    char openPare='{';
    char closePare='}';

    while(temp[j] != EOF){
        /*dataPtr point to temp,�̧ǫ��Vtemp�}�C*/
        dataPtr= &temp[j];
        j++;


        /*�P�_�{�bdataPtr�ҫ��V��temp�}�C�r��*/
        if(*dataPtr == openPare){
            /*�p�G�r����opening parenthesis�A�h�N{��Jstack��*/
            pushStack(stack, dataPtr);
        }
        else{
            if(*dataPtr == closePare){
                /*��Ū��close parenthesis�A�T�{stack���O�_��open parenthesis*/
                if(emptyStack(stack)){
                    /*(�p�Gstack�O�Ū��|�^��1�A���closePare�S���t���openPare)�h�L�XError*/
                    printf("Error: Closing parenthesis not matched.\n");
                }
                else{
                    /*�p�Gstack���٦��x�s��openPare�|�^��0�A���closePare�i�t��(�h�h���@��stack����openPare)*/
                    popStack(stack);
                }
            }
        }
    }//while

    /*�T�{stack�O�_�M�šA�p�G������ơA��ܦ�opening parenthesis�S���t���*/
    if(!emptyStack(stack)){
        printf("Error: Opening parenthesis not matched.\n");
    }
    else{
        printf("No braces. ^^");
    }


//Destroying Stack
    destroyStack(stack);
    return 0;
}
