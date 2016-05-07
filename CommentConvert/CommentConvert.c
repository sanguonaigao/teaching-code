#define _CRT_SECURE_NO_WARNINGS 1
#include "CommentConvert.h"

ConvertState state = NUL_STATE;

void DoNulState(FILE *pfIn, FILE *pfOut)
{
	char first = fgetc(pfIn);
	char second;
	switch (first)
	{
	case '/':
		second = fgetc(pfIn);
		if (second == '*')
		{
			fputc('/', pfOut);
			fputc('/', pfOut);
			state = C_STATE;
		}
		else if (second == '/')
		{
			fputc(first, pfOut);
			fputc(second, pfOut);
			state = CPP_STATE;
		}
		else
		{
			fputc(first, pfOut);
			fputc(second, pfOut);
		}
		break;
	case EOF:
		state = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}
void DoCState(FILE *pfIn, FILE *pfOut)
{
	char first = fgetc(pfIn);
	char second;
	switch (first)
	{
	case '*':
		second = fgetc(pfIn);
		if (second == '/')
		{
			//丢去*、/
			char next = fgetc(pfIn);
			if (next == '\n')
			{
				fputc(next, pfOut);
			}
			else
			{
				ungetc(next,pfIn);
				fputc('\n', pfOut);
			}
			state = NUL_STATE;
		}
		else
		{
			fputc(first, pfOut);
			ungetc(second, pfIn);
		}
		break;
	case EOF:
		state = END_STATE;
		break;
	case '\n':
		fputc(first, pfOut);
		fputc('/', pfOut);
		fputc('/', pfOut);
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}
void DoCppState(FILE *pfIn, FILE *pfOut)
{
	char first = fgetc(pfIn);
	char second;
	switch (first)
	{
	case '\n':
		fputc('\n', pfOut);
		state = NUL_STATE;
		break;
	case EOF:
		state = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}

void ConvertWork(FILE *pfIn, FILE *pfOut)
{
	while (state != END_STATE)
	{
		switch (state)
		{
		case NUL_STATE:
			DoNulState(pfIn, pfOut);
			break;
		case C_STATE:
			DoCState(pfIn, pfOut);
			break;
		case CPP_STATE:
			DoCppState(pfIn, pfOut);
			break;
		case END_STATE:
			break;
		}
	}
}
void CommentConvert()
{
	FILE * pfIn = NULL;
	FILE * pfOut = NULL;

	pfIn = fopen(INPUTFILE, "r");
	if (pfIn == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	pfOut = fopen(OUTPUTFILE, "w");
	if (pfOut == NULL)
	{
		perror("open file for write");
		fclose(pfIn);
		exit(EXIT_FAILURE);
	}
	ConvertWork(pfIn, pfOut);
	fclose(pfIn);
	fclose(pfOut);
}




