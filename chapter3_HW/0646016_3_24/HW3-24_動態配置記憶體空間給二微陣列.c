/*�굲�@�~_HW3-24
  Function�G�ʺA�t�m�O����Ŷ����G�L�}�C
  �m�W�G�i���p
*/

int **maze_row,*maze_col;
/*�إ߰g�c���G�L�}�C*/

int main()
{
    int i,j;

    /*�bmain���ͤG���}�C�A�ΨӦs��g�c*/
    //int maze[row][col];   //row�C�Bcol��
    maze_row = (int**)malloc(row*sizeof(int*));    /*�����ܼƷ|���Vint**(double point)���A�A�t�mint*�j�p���O����Ŷ�(�n���Wrow�Ӽ�) */
    maze_col = (int*)malloc(row*col*sizeof(int));  /*���Vint*(point)���A*/
    for(i=0;i<row;i++){
        maze_row[i] = maze_col;
    }
}
