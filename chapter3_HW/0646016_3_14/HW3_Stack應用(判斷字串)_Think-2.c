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
    bool done = false;   //宣告型態為布林的變數done，done為False(0)
    char *dataPtr;        //宣告型態為整數的指標變數
    dataPtr = (char*)malloc(sizeof(char));    //動態配置記憶體空間給dataPtr(在主程式宣告的指標變數)


    STACK *stack;        //宣告型態為STACK的指標變數
    stack = createStack();

    //開啟檔案
    FILE *filePtr = fopen("test.txt","r");

//Statements
    //Create a stack and allocate memory for data


    //讀取file檔案，判斷是否為open parenthesis
    char openPare='{';
    char closePare='}';
    while((dataPtr=getc(FILE *filePtr)) != EOF || fullStack(stack)){
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
        printf("Error: Opening parenthesis not matched.")
    }
    else{
        printf("No braces. ^^");
    }

//Destroying Stack
    destroyStack(stack);
    return 0;
}
