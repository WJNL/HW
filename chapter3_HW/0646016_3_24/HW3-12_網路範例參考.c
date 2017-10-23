/*
通訊工程系
姓名：盧科文
學號：492430027

HW4：maze

---已經用助教給的範例:maze.txt測試過可以輸出正確答案---

offset結構宣告的move陣列：定義6種移動方式，包含上下樓
maze陣列：零樓&一樓的地圖array，索引值之意義為[樓][row][col]
mark陣列：零樓&一樓的"紀錄是否走過的"地圖array

move:
[0]==>向前直走一步
[1]==>向後直走一步
[2]==>向左直走一步
[3]==>向右直走一步
[4]==>上樓
[5]==>下樓


宣告地圖時在邊界都各加一格，這樣就不需要針對邊界再特殊處理
==>出入口條件：左上角(0,1,1)是迷宮的入口,1樓右下角(1,m,n)是迷宮的出口

程式簡述：
利用兩個動態三維陣列分別儲存地圖資料以及標示已走的地方，依序測試六種行走方向，
若成功就存入push，若所有方向皆不行就pop出來。

輸入部分：利用fscanf讀入一整行分割後存入陣列

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int found = 0; //是否找到出口

char ***maze;
int ***mark; //動態宣告三維陣列

typedef struct
{
	int vert;  //垂直方向
	int horiz; //水平方向
	int floor; //樓層
}offsets;

typedef struct
{
	int row;
	int col;
	int floor;
	int dir;
}element;

offsets move[6];
//6種移動方向，包含上樓&下樓

int max_row,max_col;
//地圖的大小=input的地圖大小各別再加二

int top = -1; //stack的top

element stack[500]; //stack

int exit_row,exit_col; //出口位置，位於一樓

char file_name[] = "maze.txt";
//檔案名稱

//-----------------------------以下為函式宣告-----------------------------------
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
	//動態產生maze&mark陣列，皆為三維陣列：[樓][row][col]

	//產生maze陣列
	maze = malloc(2 * sizeof(char**));
	maze[0] = malloc(max_row * sizeof(char*));
	maze[1] = malloc(max_row * sizeof(char*));

	for (i=0;i<=max_row;i++)
	{
		maze[0][i] = malloc(max_col * sizeof(char));
		maze[1][i] = malloc(max_col * sizeof(char));
	}

	//產生mark陣列
	mark = malloc(2 * sizeof(int**));
	mark[0] = malloc(max_row * sizeof(int*));
	mark[1] = malloc(max_row * sizeof(int*));

	for (i=0;i<=max_row;i++)
	{
		mark[0][i] = malloc(max_col * sizeof(int));
		mark[1][i] = malloc(max_col * sizeof(int));
	}

	//初始化陣列內容

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
	//讀取地圖內容進入array
	int m,n,i,j,f; //m,n為地圖大小
	char temp1[20],temp2[20],temp_char; //輸入資料暫存區
	char *temp;
	temp = temp1;


	fptr = fopen(file_name,"r");

	if(fptr ==NULL)
	{
		printf("open file error! can not open the file");
		return;
		//若開啟檔案失敗則顯示錯誤訊息
	}

	fscanf(fptr,"%d %d\n",&m,&n);
	//讀入地圖大小

	max_row = m + 2;
	max_col = n + 2;
	//計算實際地圖陣列大小

	exit_row = m;
	exit_col = n; //出口位置(1,m,n)

	create_array(); //產生地圖陣列

	//f代表樓層，i代表row,j代表column
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
		fscanf(fptr,"%s\n",&temp_char); //把分隔字元-跳過
	}
fclose(fptr);
}

void search_path(void)
{
	element position; //宣告位置
	int col,row,floor,next_row,next_col,next_floor,dir;
	//------------------------------------------------------
	move[0].vert = 0;
	move[0].horiz = 1;
	move[0].floor = 0; //直走

	move[1].vert = 0;
	move[1].horiz = -1;
	move[1].floor = 0; //退後

	move[2].vert = -1;
	move[2].horiz = 0;
	move[2].floor = 0; //左轉

	move[3].vert = 1;
	move[3].horiz = 0;
	move[3].floor = 0; //右轉

	move[4].vert = 0;
	move[4].horiz = 0;
	move[4].floor = 1; //上樓

	move[5].vert = 0;
	move[5].horiz = 0;
	move[5].floor = -1; //下樓
    //-------------------------宣告六種走路方向---------------

	mark[0][1][1] = 1;
	top = 0;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].floor = 0;
	stack[0].dir = 0; //第一步

	while(top > -1 && !found)
	{
		position = pop();
		row = position.row;
		col = position.col;
		floor = position.floor;
		dir = position.dir;
		//讀取stack中的資料

		while(dir < 6 && !found)
		{
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			next_floor = floor + move[dir].floor;

			if(next_floor < 0)
			{
				//在0樓卻嚐試下樓
				dir++;
				continue;
			}
			else if(next_floor > 1)
			{
				//在一樓卻嚐試上樓
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

				push(position); //存入stack中

				//找到出口
			}
			else if (maze[next_floor][next_row][next_col] == '0' && mark[next_floor][next_row][next_col] == 0 && dir !=4 && dir !=5)
			{
				//有道路可走且未走過此路徑

				mark[next_floor][next_row][next_col] = 1;
				position.row = row;
			 	position.col = col;
				position.floor = floor;
				position.dir = ++dir;

				push(position); //存入stack中

				row = next_row;
				col = next_col;
				floor = next_floor;
				dir = 0;
				//移動到下一個位置
			}
			else if(maze[next_floor][next_row][next_col] == '*' && mark[next_floor][next_row][next_col] == 0)
			{
				//若有樓梯且未走過此路徑-->移動到樓梯位置

				mark[next_floor][next_row][next_col] = 1;
				position.row = row;
			 	position.col = col;
				position.floor = floor;
				position.dir = ++dir;

				push(position); //存入stack中

				row = next_row;
				col = next_col;
				floor = next_floor;
				dir = 0;
				//移動到下一個位置
			}
			else if((next_floor == 1) && (floor == 0) && (dir == 4) && (maze[floor][row][col] == '*'))
			{
				//可以上樓
				mark[next_floor][next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				position.floor = floor;
				position.dir = ++dir;

				push(position); //存入stack中

				row = next_row;
				col = next_col;
				floor = next_floor;
				dir = 0;
				//移動到下一個位置
			}
			else if(next_floor == 0 && floor == 1 && dir == 5 && maze[floor][row][col] == '*')
			{
				//可以下樓
				mark[next_floor][next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				position.floor = floor;
				position.dir = ++dir;

				push(position); //存入stack中

				row = next_row;
				col = next_col;
				floor = next_floor;
				dir = 0;
				//移動到下一個位置
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
		//未找到路徑
		printf("the maze does not have a path\n\n");
		return;
	}

	printf("Path:\n");
	for(i=0;i<=top;i++)
	{
		printf("%d(%d,%d,%d)\n",i+1,stack[i].floor,stack[i].col-1,stack[i].row-1);
	}
	printf("%d(1,%d,%d)\n",i+1,exit_col-1,exit_row-1); //補上出口座標
}
//-----------------------------以下為主程式宣告---------------------------------
void main(void)
{
	printf("hw4:maze\n");
	printf("Loading map from maze.txt\n\n");
	//程式開始

	read_map(); //讀取地圖進入array

	search_path(); //尋找路徑

	print_ans(); //顯示答案

}
