#ifndef _GAME_H_
#define _GAME_H_

#pragma warning(disable:4996)

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

//������������game.c��ʵ��
#define ROW 3
#define COL 3

#define P_CLR 'X'
#define C_CLR 'O'
#define INIT ' '

void menu();//�˵�
void Game();//��Ϸ����ʵ�ֲ���

void Initboard(char board[ROW][COL],int row,int col);//�����̳�ʼ��
void Showboard(char board[ROW][COL], int row, int col);//��ʾ����
char Judge(char board[ROW][COL], int row, int col);//�ж����Ӻ�������Ӯ
void Computermove(char board[ROW][COL], int row, int col);//��������

#endif