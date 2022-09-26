#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <conio.h> /*键盘输入获取getch和putch函数*/

bool gameOver;
bool stop = false;
bool hit = false;
/*游戏的边框大小*/
const int width = 50;
const int height = 20;
/*蛇的坐标，食物的坐标还有分数*/
int x,y,fruitX,fruitY,score;
/*蛇每个点的坐标*/
int tailX[200],tailY[200];
/*蛇的默认长度*/
int ntail=3;
/*控制台屏幕缓冲区句柄*/
HANDLE hOutput, hOutBuf;
COORD coord = { 0,0 };
/*双缓冲处理显示*/
DWORD bytes = 0;
char data[height+2][width+2];

typedef enum  
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
}Direction;

Direction Dir;
/*开始菜单*/
void menu()
{
    int a;
    printf("------------------------------------------------------------------\n");
    printf("|                              贪吃蛇游戏                        |\n");
    printf("|                              1) 新游戏                         |\n");
    printf("|                              2) 开始边界                       |\n");
    printf("|                              3) 退出游戏                       |\n");
    printf("------------------------------------------------------------------\n");
    printf("---->请输入你的选择:");
    scanf("%d", &a);
}

/*初始化状态*/
void setup()
{
    gameOver = false;
    /*根据当前时间设置“随机数种子”*/
    srand(time(NULL));
    Dir = STOP;
    
    /*贪吃蛇头的位置,固定在中间*/
    x= width/2;
    y= height/2;
    /*食物的位置，位置是随机的*/
    fruitX = rand()%width;
    fruitY = rand()%height;
    score = 0;
}

bool switchover = false;
#define BORDER_SHOWS (1)

/*绘制界面*/
void draw()
{
	int i;
	int j;
	if(stop == true)
	{
		return;
	}
    //system("cls");/*清除屏幕*/
    //printf("分数:%d",score);
    //printf("\n");
#if BORDER_SHOWS    
	/*第一行*/
    for(i= 0 ;i<width+1;i++)
	{ 
        //printf("-");
        data[0][i] = '-';
    }
    printf("\n");
#endif    
    /*画中间的画面*/ 
    int p;
    char a = 'a';
    for(p= 1 ;p<height+1;p++)/*高度*/
	{
        int q;
        for(q= 0 ;q<width;q++)/*宽度*/
		{
			/*第一行最后已给字符*/
            if(q==0 || q==width-1)
			{ 
				a = '|';
                //printf("|");
            }
            else
			{
				if(p == fruitY && q == fruitX)/*食物的随机坐标*/
				{
	                //printf("O");
	                a = '$';
	            }
				else
				{
	                    int k=0;
	                    bool print = false;
	                    /*贪吃蛇的长度 默认长度是 3*/
						for(k=0;k<ntail;k++)
						{
	                        if(tailX[k]==q && tailY[k]==p)
							{
	                            //printf("*");
	                            a = '*';
	                            print = true;
	                        }
	                    }
	                    /*如果这个位置打印了 * 就不要打印空格了*/
	                    if(!print)
						{
							//printf(" ");
							a = ' ';
						}
	            }
        	}
            data[p][q] = a;
        }
        //printf("\n");
    }
#if BORDER_SHOWS
	/*最后一行*/
    for(j= 0 ;j<width+1;j++)
	{
        //printf("-");
        data[height+1][j] = '-';
    }
#endif
	/*双buff切换显示*/
	if(switchover == true)
	{
	    for (i = 0; i < height+2; i++)
	    {
	        coord.Y = i;
	        WriteConsoleOutputCharacterA(hOutBuf, data[i], width+2, coord, &bytes);
	    }
	    /*设置新的缓冲区为活动显示缓冲*/
	    SetConsoleActiveScreenBuffer(hOutBuf);	 
	}
	else
	{
		for (i = 0; i < height+2; i++)
	    {
	        coord.Y = i;
	        WriteConsoleOutputCharacterA(hOutput, data[i], width+2, coord, &bytes);
	    }
	    //设置新的缓冲区为活动显示缓冲
	    SetConsoleActiveScreenBuffer(hOutput);	
	}
	
	Sleep(100);
	switchover = !switchover;

}
/*按键输入控制*/
void input()
{
	/*如果有案件按下*/
    if(_kbhit())
	{
		/*获取键盘的输入字符*/
        switch(_getch())
		{
            case 'a':/*左键*/
                Dir = LEFT;
                hit= true;
                break;
            case 'w':/*上键*/
                Dir = UP;
                hit= true;
                break;
            case 'd':/*右键*/
                Dir = RIGHT;
                hit= true;
                break;
            case 's':/*向下键盘键 */
                Dir = DOWN;
                hit= true;
                break;
            case 27:/*ESE*/
                gameOver = true;
                break;
            case 32:/*空格 暂停键*/
				stop = !stop;
				break; 
        }
    }
	else if(!hit && stop == false)/*如果刚开始没有点击案件改变方向的话*/
	{
        x++;
        //y++;
    }
}
/*判断贪吃蛇的长度*/ 
void logic()
{
	if(stop == true)
	{
		return;
	}
	
	/*把上一个位置记下*/
    int lastX = tailX[0];
    int lastY = tailY[0];
    int last2X, last2Y;
    /*重新获取当前的位置*/
	tailX[0]=x;
    tailY[0]=y;
    int i=0;
    /*遍历整条蛇的长度 把 0 的位置空出来，其余蛇的位置往后面的空间移动*/
    for(i=1; i<ntail;i++)
	{
        last2X = tailX[i];
        last2Y = tailY[i];
        tailX[i]=lastX; 
        tailY[i]=lastY;
        lastX = last2X; 
        lastY = last2Y;
    }
    
    /*根据方向来改变x y 的值*/
    switch(Dir)
	{
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
    }
    if(x<0 || width<x || y<0 || height<y)
	{
        gameOver = true;
        /*清除屏幕*/
        system("cls");
        printf("------------------------------------------------------------------\n");
	    printf("|                             分数:%d                            |\n",score);
	    printf("|                             游戏结束                           |\n");
	    printf("------------------------------------------------------------------\n");
    }
    if(x==fruitX && y==fruitY)
	{
		/*吃了一个食物，蛇的长度增加1*/
        ntail++;
        score+=10;
        /*更新下一个食物的位置*/
        fruitX = rand()%width;
        fruitY = rand()%height;
    }
}

/*双缓冲技术解决闪屏问题*/
void double_buff_init(void)
{
   	/*创建新的控制台缓冲区*/
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,/*定义进程可以往缓冲区写数据*/
        FILE_SHARE_WRITE,/*定义缓冲区可共享写权限*/
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,/*定义进程可以往缓冲区写数据*/
        FILE_SHARE_WRITE,/*定义缓冲区可共享写权限*/
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    
    /*隐藏两个缓冲区的光标*/
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);	
} 

int main()
{
#if 0
	while(1)
	{
		printf("%d\n",_getch());
	} 
#endif
	double_buff_init();
    menu();
    setup();
    logic();
    draw();

    /*循环画贪吃蛇的界面*/
	while(!gameOver)
	{
        draw();
        input();
        logic(); 
    }

    return 0;
}