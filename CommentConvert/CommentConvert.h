#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//状态机定义
typedef enum CONVERT_STATE
{
	NUL_STATE,	//无状态
	C_STATE,	//C语言注释状态
	CPP_STATE,	//C++注释风格状态
	END_STATE	//文件结束状态
}ConvertState;

//输入文件名
#define INPUTFILE "input.c" 

//输出文件名
#define OUTPUTFILE "output.c" 

//处理无状态
void DoNulState(FILE *pfIn, FILE *pfOut);

//处理C语言注释状态
void DoCState(FILE *pfIn, FILE *pfOut);

//处理C++注释状态
void DoCppState(FILE *pfIn, FILE *pfOut);

//核心转换函数
void ConvertWOrk(FILE *in, FILE *out);

//注释转换
void CommentConvert();
