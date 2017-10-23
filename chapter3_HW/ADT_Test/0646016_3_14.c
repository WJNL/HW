/*資料結構_chapter3.5_Stack應用_修改
  program_3-15
  Title：HW3_Stack應用(判斷字串)

  Function: 將temp陣列中的字串，判斷是否為"{"或是"}"，存入stack
  (pre)  輸入一連串數字
  (post) 顛倒數字輸入順序
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

   /* 將filePtr所指向的檔案中字元存放進temp陣列 */
   while((temp[i] = fgetc(filePtr)) != EOF){
        i++;
   }

    /*讀取file檔案，判斷是否為open parenthesis*/
    char openPare='{';
    char closePare='}';

    //要讓dataPtr依序指向temp去判斷
    while((dataPtr= temp[j])){
        printf("%s", *dataPtr);
        if(*dataPtr == openPare){
            pushStack(stack, dataPtr);
        }
        else{
            if(*dataPtr == closePare){
                //當讀到close parenthesis，確認stack中是否有open parenthesis
                if(emptyStack(stack)){
                    //(如果stack是空的會回傳1，表示closePare沒有配對到openPare)則印出Error
                    printf("Error: Closing parenthesis not matched.");
                }
                else{
                    //如果stack中還有儲存的openPare會回傳0，表示closePare可配對(則去除一個stack中的openPare)
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
