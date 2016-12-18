#ifndef SNAKE_H
#define SNAKE_H
#include "snake_list.h"

class cSnake
{
public:
	cSnake(void);
	~cSnake(void);
	//游戏地图
	void m_showmap();
	bool m_showsnake();
	//sanke 行为
	void m_snakefood();
	


	
	bool IsSnake(int x,int y);//判断food在不在蛇身上
	snake_list snake;
	bool gameover;//游戏结束标识
	int operate;//记录snake的移动方向，默认向右
	char sanke_food;
	bool eat_flag;//是否吃掉的标识 


};
#endif
