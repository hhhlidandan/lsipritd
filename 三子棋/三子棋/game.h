#ifndef _GAME_H_
#define _GAME_H_

#pragma warning(disable:4996)

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

//函数声明，在game.c中实现
#define ROW 3
#define COL 3

#define P_CLR 'X'
#define C_CLR 'O'
#define INIT ' '

void menu();//菜单
void Game();//游戏具体实现部分

void Initboard(char board[ROW][COL],int row,int col);//对棋盘初始化
void Showboard(char board[ROW][COL], int row, int col);//显示棋盘
char Judge(char board[ROW][COL], int row, int col);//判断落子后是输是赢
void Computermove(char board[ROW][COL], int row, int col);//电脑落子

#endif