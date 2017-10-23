/*
�q�T�u�{�t
�m�W�G�c���
�Ǹ��G492430027

HW4�Gmaze

---�w�g�ΧU�е����d��:maze.txt���չL�i�H��X���T����---

offset���c�ŧi��move�}�C�G�w�q6�ز��ʤ覡�A�]�t�W�U��
maze�}�C�G�s��&�@�Ӫ��a��array�A���ޭȤ��N�q��[��][row][col]
mark�}�C�G�s��&�@�Ӫ�"�����O�_���L��"�a��array

move:
[0]==>�V�e�����@�B
[1]==>�V�᪽���@�B
[2]==>�V�������@�B
[3]==>�V�k�����@�B
[4]==>�W��
[5]==>�U��


�ŧi�a�Ϯɦb��ɳ��U�[�@��A�o�˴N���ݭn�w����ɦA�S��B�z
==>�X�J�f����G���W��(0,1,1)�O�g�c���J�f,1�ӥk�U��(1,m,n)�O�g�c���X�f

�{��²�z�G
�Q�Ψ�ӰʺA�T���}�C���O�x�s�a�ϸ�ƥH�μХܤw�����a��A�̧Ǵ��դ��ئ樫��V�A
�Y���\�N�s�Jpush�A�Y�Ҧ���V�Ҥ���Npop�X�ӡC

��J�����G�Q��fscanfŪ�J�@�����Ϋ�s�J�}�C

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int found = 0; //�O�_���X�f

char ***maze;
int ***mark; //�ʺA�ŧi�T���}�C

typedef struct
{
	int vert;  //������V
	int horiz; //������V
	int floor; //�Ӽh
}offsets;

typedef struct
{
	int row;
	int col;
	int floor;
	int dir;
}element;

offsets move[6];
//6�ز��ʤ�V�A�]�t�W��&�U��

int max_row,max_col;
//�a�Ϫ��j�p=input���a�Ϥj�p�U�O�A�[�G

int top = -1; //stack��top

element stack[500]; //stack

int exit_row,exit_col; //�X�f��m�A���@��

char file_name[] = "maze.txt";
//�ɮצW��

//-----------------------------�H�U���禡�ŧi-----------------------------------
void push(element data)
{
	int i;
	i = ++top;
	stack[i].row = data.row;
	stack[i].col = data.col;
	stack[i].floor = data.floor;
	stack[i].dir = data.dir;
}

element pop()
{
	element result;

	result.row = stack[top].row;
	result.col = stack[top].col;
	result.floor = stack[top].floor;
	result.dir = stack[top].dir;

	top--;
	return result;
}

void create_array(void)
{
	int i,j,k;
	//�ʺA����maze&mark�}�C�A�Ҭ��T���}�C�G[��][row][col]

	//����maze�}�C
	maze = malloc(2 * sizeof(char**));
	maze[0] = malloc(max_row * sizeof(char*));
	maze[1] = malloc(max_row * sizeof(char*));

	for (i=0;i<=max_row;i++)
	{
		maze[0][i] = malloc(max_col * sizeof(char));
		maze[1][i] = malloc(max_col * sizeof(char));
	}

	//����mark�}�C
	mark = malloc(2 * sizeof(int**));
	mark[0] = malloc(max_row * sizeof(int*));
	mark[1] = malloc(max_row * sizeof(int*));

	for (i=0;i<=max_row;i++)
	{
		mark[0][i] = malloc(max_col * sizeof(int));
		mark[1][i] = malloc(max_col * sizeof(int));
	}

	//��l�ư}�C���e

	for(i=0;i<=1;i++)
	{
		for(j=0;j<=max_row;j++)
		{
			for (k=0;k<=max_col;k++)
			{
				maze[i][j][k] = '1';
				mark[i][j][k] = 0;
			}
		}
	}

}
void read_map(void)
{
	FILE *fptr;
	//Ū���a�Ϥ��e�i�Jarray
	int m,n,i,j,f; //m,n���a�Ϥj�p
	char temp1[20],temp2[20],temp_char; //��J��ƼȦs��
	char *temp;
	temp = temp1;


	fptr = fopen(file_name,"r");

	if(fptr ==NULL)
	{
		printf("open file error! can not open the file");
		return;
		//�Y�}���ɮץ��ѫh��ܿ��~�T��
	}

	fscanf(fptr,"%d %d\n",&m,&n);
	//Ū�J�a�Ϥj�p

	max_row = m + 2;
	max_col = n + 2;
	//�p���ڦa�ϰ}�C�j�p

	exit_row = m;
	exit_col = n; //�X�f��m(1,m,n)

	create_array(); //���ͦa�ϰ}�C

	//f�N��Ӽh�Ai�N��row,j�N��column
	for (f=0;f<=1;f++)
	{
		for(i=0;i<m;i++)
		{
			fscanf(fptr,"%s\n",temp);

			for(j=0;j<n;j++)
			{
				maze[f][i+1][j+1] = temp[j];
			}
		}
		temp = temp2;
		fscanf(fptr,"%s\n",&temp_char); //����j�r��-���L
	}
fclose(fptr);
}

void search_path(void)
{
	element position; //�ŧi��m
	int col,row,floor,next_row,next_col,next_floor,dir;
	//------------------------------------------------------
	move[0].vert = 0;
	move[0].horiz = 1;
	move[0].floor = 0; //����

	move[1].vert = 0;
	move[1].horiz = -1;
	move[1].floor = 0; //�h��

	move[2].vert = -1;
	move[2].horiz = 0;
	move[2].floor = 0; //����

	move[3].vert = 1;
	move[3].horiz = 0;
	move[3].floor = 0; //�k��

	move[4].vert = 0;
	move[4].horiz = 0;
	move[4].floor = 1; //�W��

	move[5].vert = 0;
	move[5].horiz = 0;
	move[5].floor = -1; //�U��
    //-------------------------�ŧi���ب�����V---------------

	mark[0][1][1] = 1;
	top = 0;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].floor = 0;
	stack[0].dir = 0; //�Ĥ@�B

	while(top > -1 && !found)
	{
		position = pop();
		row = position.row;
		col = position.col;
		floor = position.floor;
		dir = position.dir;
		//Ū��stack�������

		while(dir < 6 && !found)
		{
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			next_floor = floor + move[dir].floor;

			if(next_floor < 0)
			{
				//�b0�ӫo�|�դU��
				dir++;
				continue;
			}
			else if(next_floor > 1)
			{
				//�b�@�ӫo�|�դW��
				dir++;
				continue;
			}

			if (next_row == exit_row && next_col == exit_col && next_floor == 1)
			{
				found = 1;

				position.row = row;
			 	position.col = col;
				position.floor = floor;
				position.dir = ++dir;

				push(position); //�s�Jstack��

				//���X�f
			}
			else if (maze[next_floor][next_row][next_col] == '0' && mark[next_floor][next_row][next_col] == 0 && dir !=4 && dir !=5)
			{
				//���D���i���B�����L�����|

				mark[next_floor][next_row][next_col] = 1;
				position.row = row;
			 	position.col = col;
				position.floor = floor;
				position.dir = ++dir;

				push(position); //�s�Jstack��

				row = next_row;
				col = next_col;
				floor = next_floor;
				dir = 0;
				//���ʨ�U�@�Ӧ�m
			}
			else if(maze[next_floor][next_row][next_col] == '*' && mark[next_floor][next_row][next_col] == 0)
			{
				//�Y���ӱ�B�����L�����|-->���ʨ�ӱ��m

				mark[next_floor][next_row][next_col] = 1;
				position.row = row;
			 	position.col = col;
				position.floor = floor;
				position.dir = ++dir;

				push(position); //�s�Jstack��

				row = next_row;
				col = next_col;
				floor = next_floor;
				dir = 0;
				//���ʨ�U�@�Ӧ�m
			}
			else if((next_floor == 1) && (floor == 0) && (dir == 4) && (maze[floor][row][col] == '*'))
			{
				//�i�H�W��
				mark[next_floor][next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				position.floor = floor;
				position.dir = ++dir;

				push(position); //�s�Jstack��

				row = next_row;
				col = next_col;
				floor = next_floor;
				dir = 0;
				//���ʨ�U�@�Ӧ�m
			}
			else if(next_floor == 0 && floor == 1 && dir == 5 && maze[floor][row][col] == '*')
			{
				//�i�H�U��
				mark[next_floor][next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				position.floor = floor;
				position.dir = ++dir;

				push(position); //�s�Jstack��

				row = next_row;
				col = next_col;
				floor = next_floor;
				dir = 0;
				//���ʨ�U�@�Ӧ�m
			}
			else
			{
				dir++;
			}
		}

	}

}

void print_ans(void)
{
	int i;

	if(found == 0)
	{
		//�������|
		printf("the maze does not have a path\n\n");
		return;
	}

	printf("Path:\n");
	for(i=0;i<=top;i++)
	{
		printf("%d(%d,%d,%d)\n",i+1,stack[i].floor,stack[i].col-1,stack[i].row-1);
	}
	printf("%d(1,%d,%d)\n",i+1,exit_col-1,exit_row-1); //�ɤW�X�f�y��
}
//-----------------------------�H�U���D�{���ŧi---------------------------------
void main(void)
{
	printf("hw4:maze\n");
	printf("Loading map from maze.txt\n\n");
	//�{���}�l

	read_map(); //Ū���a�϶i�Jarray

	search_path(); //�M����|

	print_ans(); //��ܵ���

}
