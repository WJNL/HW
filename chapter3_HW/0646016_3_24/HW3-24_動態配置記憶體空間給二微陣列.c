/*資結作業_HW3-24
  Function：動態配置記憶體空間給二微陣列
  姓名：張完如
*/

int **maze_row,*maze_col;
/*建立迷宮的二微陣列*/

int main()
{
    int i,j;

    /*在main產生二維陣列，用來存放迷宮*/
    //int maze[row][col];   //row列、col行
    maze_row = (int**)malloc(row*sizeof(int*));    /*指標變數會指向int**(double point)型態，配置int*大小的記憶體空間(要乘上row個數) */
    maze_col = (int*)malloc(row*col*sizeof(int));  /*指向int*(point)型態*/
    for(i=0;i<row;i++){
        maze_row[i] = maze_col;
    }
}
