#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct stack
{
	int arr[100][4];
	char c[100];
	int top;
} Undo;
void push(char c, int si, int sj, int pi, int pj)
{
	if (Undo.top == 99)
	{
		printf("error: stack is full ");
		return;
	}
	Undo.top++;
	Undo.c[Undo.top] = c;
	Undo.arr[Undo.top][0] = si;
	Undo.arr[Undo.top][1] = sj;
	Undo.arr[Undo.top][2] = pi;
	Undo.arr[Undo.top][3] = pj;
	return;
}
char pop(int *si, int *sj, int *pi, int *pj)
{
	if (Undo.top == -1)
	{
		return '\0';
	}
	char c = Undo.c[Undo.top];
	*si = Undo.arr[Undo.top][0];
	*sj = Undo.arr[Undo.top][1];
	*pi = Undo.arr[Undo.top][2];
	*pj = Undo.arr[Undo.top][3];
	Undo.top--;
	return c;
}
float calc_dist(int si, int sj, int pi, int pj)
{
	return (si - pi) * (si - pi) + (sj - pj) * (sj - pj);
}

void movesnake(int *si, int *sj, int pi, int pj, int m, int n, char *a[])
{
	float l = 3.4e+038, r = 3.4e+038, u = 3.4e+038, d = 3.4e+038;
	int i = 0, j = 0;
	float min = 3.4e+038;
	if (a[*si + 1][*sj] != '-' && a[*si + 1][*sj] != 'O' && a[*si + 1][*sj] != 'X')
	{
		d = calc_dist(*si + 1, *sj, pi, pj);
		min = d;
		i = 1;
		j = 0;
	}
	if (a[*si - 1][*sj] != '-' && a[*si - 1][*sj] != 'O' && a[*si - 1][*sj] != 'X')
	{
		u = calc_dist(*si - 1, *sj, pi, pj);
		if (min > u)
		{
			min = u;
			i = -1;
			j = 0;
		}
	}
	if (a[*si][*sj - 1] != '|' && a[*si][*sj - 1] != 'O' && a[*si][*sj - 1] != 'X')
	{
		l = calc_dist(*si, *sj - 1, pi, pj);
		if (min > l)
		{
			min = l;
			i = 0;
			j = -1;
		}
	}
	if (a[*si][*sj + 1] != '|' && a[*si][*sj + 1] != 'O' && a[*si][*sj + 1] != 'X')
	{
		r = calc_dist(*si, *sj + 1, pi, pj);
		if (min > r)
		{
			min = r;
			i = 0;
			j = 1;
		}
	}
	*si = *si + i;
	*sj = *sj + j;
	a[*si - i][*sj - j] = ' ';
	a[*si][*sj] = '~';
}
int main()
{
	FILE *fileptr;
	char option, ch, lm;
	int x, i = 0, j = 0, pi, pj, si, sj, wi, wj, q = 0;
	fileptr = fopen("map.txt", "r");
	Undo.top = -1;
  printf("\t WELCOME TO THE MAZE GAME! \t");
	printf(" \n\n RULES : ");
	printf(" \n  1.Press 'w' to move the player up ");
	printf(" \n  2.Press 's' to move the player down ");
	printf(" \n  3.Press 'a' to move the player left ");
	printf(" \n  4.Press 'd' to move the player right ");
  printf(" \n  5.Press 'u' for Undo ");
  printf(" \n  6.Press 'e' to exit the game! ");
	printf("\n");
	int ar;
	printf(" \n  Press Enter key to start the game: \n");

	ch = getch();
	system("CLS");
	fscanf(fileptr, "%d", &ar);
	int input[ar + 1][3];
	input[0][0] = ar;
	fscanf(fileptr, "%d", &input[0][1]);
	fscanf(fileptr, "%d", &input[0][2]);
	for (i = 1; i < ar + 1; i++)
	{
		fscanf(fileptr, "%d", &input[i][0]);
		fscanf(fileptr, "%d", &input[i][1]);
		fscanf(fileptr, "%d", &input[i][2]);
	}
	fclose(fileptr);
	char **a = (char **)malloc(input[0][1] * sizeof(char *));
	int w;
	for (w = 0; w < input[0][1]; w++)
	{
		a[w] = (char *)malloc(input[0][2] * sizeof(char));
	}
	for (i = 0; i < input[0][1]; i++)
	{
		for (j = 0; j < input[0][2]; j++)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == input[0][2] - 1) || (i == input[0][1] - 1 && j == 0) || (i == input[0][1] - 1 && j == input[0][2] - 1))
			{
				a[i][j] = '#';
			}
			else if (i == 0 && (j > 0 && j < input[0][2] - 1) || i == input[0][1] - 1 && (j > 0 && j < input[0][2] - 1))
			{
				a[i][j] = '-';
			}
			else if (j == 0 && (i > 0 && j < input[0][1] - 1) || ((j == input[0][2] - 1) && (i > 0 && i < input[0][1] - 1)))
			{
				a[i][j] = '|';
			}
			else
			{
				a[i][j] = ' ';
			}
		}
	}
	for (i = 1; i <= input[0][0]; i++)
	{
		if (input[i][2] == 0)
		{
			a[input[i][0]][input[i][1]] = '^';
			pi = input[i][0];
			pj = input[i][1];
		}
		else if (input[i][2] == 1)
		{
			a[input[i][0]][input[i][1]] = '~';
			si = input[i][0];
			sj = input[i][1];
		}
		else if (input[i][2] == 2)
		{
			a[input[i][0]][input[i][1]] = 'X';
			wi = input[i][0];
			wj = input[i][1];
		}
		else if (input[i][2] == 3)
		{
			a[input[i][0]][input[i][1]] = 'O';
		}
	}

	for (i = 0; i < input[0][1]; i++)
	{
		for (j = 0; j < input[0][2]; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	push('^', si, sj, pi, pj);
	int isi = si, isj = sj, ipi = pi, ipj = pj;
	while (1)
	{

		option = getch();
    if (option == 'e')
    {
       printf("Thanks for Playing!");
       exit(0);
     }
		switch (option)
		{
		case 'w':
		{
			if (a[pi - 1][pj] != '-' && a[pi - 1][pj] != 'O')
			{
				a[pi][pj] = ' ';
				a[--pi][pj] = '^';
			}
			push('^', si, sj, pi, pj);
			q = 0;
			break;
		}
		case 's':
		{
			if (a[pi + 1][pj] != '-' && a[pi + 1][pj] != 'O')
			{
				a[pi][pj] = ' ';
				a[++pi][pj] = 'v';
			}
			push('v', si, sj, pi, pj);
			q = 0;
			break;
		}
		case 'a':
		{
			if (a[pi][pj - 1] != '|' && a[pi][pj - 1] != 'O')
			{
				a[pi][pj] = ' ';
				a[pi][--pj] = '<';
			}
			push('<', si, sj, pi, pj);
			q = 0;
			break;
		}
		case 'd':
		{
			if (a[pi][pj + 1] != '|' && a[pi][pj + 1] != 'O')
			{
				a[pi][pj] = ' ';
				a[pi][++pj] = '>';
			}
			push('>', si, sj, pi, pj);
			q = 0;
			break;
		}
		case 'u':
		{
			int l = pi, m = pj, n = si, o = sj;
			if (q == 0)
			{
				char cl = pop(&si, &sj, &pi, &pj);
				q = 1;
			}
			char c1 = pop(&si, &sj, &pi, &pj);
			if (c1)
			{
				a[l][m] = ' ';
				a[n][o] = ' ';
				a[pi][pj] = c1;
				a[si][sj] = '~';
			}
			else
			{
				push('^', isi, isj, ipi, ipj);
				continue;
			}
			break;
		}
		default:
			continue;
		}
		if (pi == wi && pj == wj)
		{
			system("cls");
			int i, j;
			for (i = 0; i < input[0][1]; i++)
			{
				for (j = 0; j < input[0][2]; j++)
				{
					printf("%c", a[i][j]);
				}
				printf("\n");
			}
			printf("\nYOU WIN!\n");
			return 0;
		}
		if (si == pi && sj == pj)
		{
			system("cls");
			int i, j;
			for (i = 0; i < input[0][1]; i++)
			{
				for (j = 0; j < input[0][2]; j++)
				{
					printf("%c", a[i][j]);
				}
				printf("\n");
			}
			printf("\nYOU LOSE!\n");
			return 0;
		}
		int l = input[0][1], r = input[0][2];
		movesnake(&si, &sj, pi, pj, l, r, a);
		system("cls");
		int i, j;
		for (i = 0; i < input[0][1]; i++)
		{
			for (j = 0; j < input[0][2]; j++)
			{
				printf("%c", a[i][j]);
			}
			printf("\n");
		}

		if (si == pi && sj == pj)
		{
			printf("\nYOU LOSE!\n");
			return 0;
		}
	}
	return 0;
}
