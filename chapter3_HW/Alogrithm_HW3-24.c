/*�굲�@�~_HW3-24
  �m�W�G�i���p
  �Ǹ��G0646016
*/

#include <stdio.h>
#include <stdlib.h>
#define row 3
#define col 5

int **maze_row,*maze_col;
/*�إ߰g�c���G�L�}�C*/

int main()
{
    int i,j;

    /*�bmain���ͤG���}�C�A�ΨӦs��g�c*/
    int maze[row][col]={{1,1,1,1,1},
                        {1,0,0,1,0},
                        {1,1,0,1,1}};   //row�C�Bcol��
//    maze_row = (int**)malloc(row*sizeof(int*));    /*�����ܼƷ|���Vint**(double point)���A�A�t�mint*�j�p���O����Ŷ�(�n���Wrow�Ӽ�) */
//    maze_col = (int*)malloc(row*col*sizeof(int));  /*���Vint*(point)���A*/
//    for(i=0;i<row;i++){
//        maze_row[i] = maze_col;
//    }

    /*Ū���ɮפ��g�c�A��m��}�C��*/


    /*��J��m�A�P�_��J���}�C��m����0/1 */
    int scanRow,scanCol;
    int *startJudg;
    do{
        printf("Please enter the mouse start point:\n""(row col)= ");
        scanf("%d %d",&scanRow, &scanCol);
        printf("scanRow= %d\tscanCol= %d\n",scanRow, scanCol);
        startJudg = &maze[scanRow][scanCol];
        printf("%d\n", *startJudg);
    }while(*startJudg == 1);

    //�ѹ�����





    return 0;
}
