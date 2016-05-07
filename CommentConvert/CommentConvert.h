#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef enum CONVERT_STATE
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
}ConvertState;

#define INPUTFILE "input.c"
#define OUTPUTFILE "output.c"


void DoNulState(FILE *pfIn, FILE *pfOut);
void DoCState(FILE *pfIn, FILE *pfOut);
void DoCppState(FILE *pfIn, FILE *pfOut);
void ConvertWOrk(FILE *in, FILE *out);
void CommentConvert();
