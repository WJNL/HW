/*資結作業_HW3-12
  姓名：張完如
  學號：0646016
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

   /* 將filePtr所指向的檔案中字串分別以字元存放進temp陣列 */
   while((temp[i] = fgetc(filePtr)) != EOF){
        i++;
   }

    /*讀取file檔案，判斷是否為open parenthesis*/
    char openPare='{';
    char closePare='}';

    while(temp[j] != EOF){
        /*dataPtr point to temp,依序指向temp陣列*/
        dataPtr= &temp[j];
        j++;


        /*判斷現在dataPtr所指向的temp陣列字元*/
        if(*dataPtr == openPare){
            /*如果字元為opening parenthesis，則將{放入stack中*/
            pushStack(stack, dataPtr);
        }
        else{
            if(*dataPtr == closePare){
                /*當讀到close parenthesis，確認stack中是否有open parenthesis*/
                if(emptyStack(stack)){
                    /*(如果stack是空的會回傳1，表示closePare沒有配對到openPare)則印出Error*/
                    printf("Error: Closing parenthesis not matched.\n");
                }
                else{
                    /*如果stack中還有儲存的openPare會回傳0，表示closePare可配對(則去除一個stack中的openPare)*/
                    popStack(stack);
                }
            }
        }
    }//while

    /*確認stack是否清空，如果仍有資料，表示有opening parenthesis沒有配對到*/
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
