/*資結作業_HW3-24
  姓名：張完如
  學號：0646016
*/

#include <stdio.h>
#include <stdlib.h>
#define row 3
#define col 5

int **maze_row,*maze_col;
/*建立迷宮的二微陣列*/

int main()
{
    int i,j;

    /*在main產生二維陣列，用來存放迷宮*/
    int maze[row][col]={{1,1,1,1,1},
                        {1,0,0,1,0},
                        {1,1,0,1,1}};   //row列、col行
//    maze_row = (int**)malloc(row*sizeof(int*));    /*指標變數會指向int**(double point)型態，配置int*大小的記憶體空間(要乘上row個數) */
//    maze_col = (int*)malloc(row*col*sizeof(int));  /*指向int*(point)型態*/
//    for(i=0;i<row;i++){
//        maze_row[i] = maze_col;
//    }

    /*讀取檔案中迷宮，放置到陣列中*/


    /*輸入位置，判斷輸入之陣列位置內為0/1 */
    int scanRow,scanCol;
    int *startJudg;
    do{
        printf("Please enter the mouse start point:\n""(row col)= ");
        scanf("%d %d",&scanRow, &scanCol);
        printf("scanRow= %d\tscanCol= %d\n",scanRow, scanCol);
        startJudg = &maze[scanRow][scanCol];
        printf("%d\n", *startJudg);
    }while(*startJudg == 1);

    //老鼠移動





    return 0;
}
