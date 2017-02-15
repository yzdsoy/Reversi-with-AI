#define _CRT_SECURE_NO_WARNINGS
#define SIZE 8
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char s[8][8];
char ss[8][8];
int what;
char move[100];
char me, you;
int t=0;

int scoreO()
{
	int z = 0;
	int i, j;
	for (i = 0; i <= 7; i++) for (j = 0; j <= 7; j++) if(s[i][j] == 'O') z++;
	return z;
}
int scoreX()
{
	int z = 0;
	int i, j;
	for (i = 0; i <= 7; i++) for (j = 0; j <= 7; j++) if (s[i][j] == 'X') z++;
	return z;
}
int value(int i,int j)
{
	int inva[8][8] = 
	{
		390,-50, 30,15,15,30,-50,390,
		-50 ,-80,1,-5,-5,1,-80 ,-50,
		30,   1 ,5 ,1 ,1 ,5 ,1 ,30,
		15,   -5, 1, 1, 1, 1, -5,15,
		15,   -5, 1, 1, 1, 1, -5,15,
		30,   1, 5, 1, 1, 5, 1, 30,
		-50, -80,1,-5,-5,1,-80,-50,
		390, -50,30,15,15,30,-50,390

	};
	return inva[i][j];


}
int valuexnow(char sss[8][8])
{
	int thevalue = 0;
	int i, j;
	for (i = 0; i <= 7; i++) for (j = 0; j <= 7; j++) 
		if (sss[i][j] == 'X')thevalue = thevalue + value(i,j);
	return thevalue;
}
void printnask()
{
	int i;
	int j;
	for (i = 'a'; i <= 'h'; i++) printf("   %c", i);
	printf("\n +");
	for (i = 'a'; i <= 'h'; i++) printf("---+");
	for (i = 0; i <= 7; i++)
	{
		printf("\n%d|",i+1);
		for (j = 0; j <= 7; j++) printf(" %c |", s[i][j]);
		printf("\n +");
		for (j = 'a'; j <= 'h'; j++) printf("---+");
	}

	

}

int valid(char st[])
{
	me = 'O';
	you = 'X';
	if (strlen(st) == 2 && st[0] >= '1'&&st[0] <= '8'&&st[1] <= 'h'&&st[1] >= 'a')
	{
		return isvalid(st);
	}
	else return 0;
}

int isvalid(char st[])
{
	int i, j;
	t = 0;
	//for (i = 0; i <= 7; i++) for (j = 0; j <= 7; j++) ss[i][j]=s[i][j] ;
	int a = st[0] - '1';
	int b = st[1] - 'a';
	//////////////////////// 
	if (s[a][b] != ' ')return 0;
	else{
		if (b + 1 <= 7 && s[a][b + 1] == you)
		{
			for (i = b + 2; i <= 7; i++)
			{
				if (s[a][i] == ' ')break;
				if (s[a][i] == me)
				{
					t = t + 1;
					for (j = b; j <= i; j++) s[a][j] = me;
					break;

				}
			}
		}
		if (b - 1 >= 0 && s[a][b - 1] == you)
		{
			for (i = b - 2; i >= 0; i--)
			{
				if (s[a][i] == ' ')break;
				if (s[a][i] == me)
				{
					t = t + 1;
					for (j = b; j >= i; j--) s[a][j] = me;
					break;

				}
			}
		}
		if (a - 1 >= 0 && s[a - 1][b] == you)
		{
			for (i = a - 2; i >= 0; i--)
			{
				if (s[i][b] == ' ')break;
				if (s[i][b] == me)
				{
					t = t + 1;
					for (j = a; j >= i; j--) s[j][b] = me;
					break;

				}
			}
		}
		if (a + 1 <= 7 && s[a + 1][b] == you)
		{
			for (i = a + 2; i <= 7; i++)
			{
				if (s[i][b] == ' ')break;
				if (s[i][b] == me)
				{
					t = t + 1;
					for (j = a; j <= i; j++) s[j][b] = me;
					break;

				}
			}
		}
		if (a + 1 <= 7 && b + 1 <= 7 && s[a + 1][b + 1] == you)
		{
			for (i = 2; a + i <= 7 && b + i <= 7; i++)
			{
				if (s[a + i][b + i] == ' ')break;
				if (s[a + i][b + i] == me)
				{
					t = t + 1;
					for (j = 0; j <= i; j++) s[a + j][b + j] = me;
					break;

				}
			}
		}
		if (a - 1 >= 0 && b - 1 >= 0 && s[a - 1][b - 1] == you)
		{
			for (i = 2; a - i >= 0 && b - i >= 0; i++)
			{
				if (s[a - i][b - i] == ' ')break;
				if (s[a - i][b - i] == me)
				{
					t = t + 1;
					for (j = 0; j <= i; j++) s[a - j][b - j] = me;
					break;

				}
			}
		}
		if (a - 1 >= 0 && b + 1 <=7 && s[a - 1][b + 1] == you)
		{
			for (i = 2; a - i >= 0 && b + i <=7 ; i++)
			{
				if (s[a - i][b + i] == ' ')break;
				if (s[a - i][b + i] == me)
				{
					t = t + 1;
					for (j = 0; j <= i; j++) s[a - j][b + j] = me;
					break;

				}
			}
		}
		if (a + 1 >= 0 && b - 1 >= 0 && s[a + 1][b - 1] == you)
		{
			for (i = 2; a + i <=7 && b - i >= 0; i++)
			{
				if (s[a + i][b - i] == ' ')break;
				if (s[a + i][b - i] == me)
				{
					t = t + 1;
					for (j = 0; j <= i; j++) s[a + j][b - j] = me;
					break;

				}
			}
		}
		if (t > 0) return 1;
		else return 0;

	}
}

AIgo()
{	
	int i, j;
	for (i = 0; i <= 7; i++) for (j = 0; j <= 7; j++) ss[i][j] = s[i][j];
	int meaningless = 0;
	me = 'X';
	you = 'O';
	int validd = 0;

	char k[2];
	char * kk;
	//*kk = '0a';
	//if (isvalid(*kk) == 1)meaningless = 0;
	//else if (isvalid('0a') == 1)meaningless = 0;
	//else if (isvalid('7a') == 1)meaningless = 0;
	//else if (isvalid('7h') == 1)meaningless = 0;
	//else{
	char valuetable[8][8];
	for (i = 0; i <= 7; i++) for (j = 0; j <= 7; j++) valuetable[i][j]=-10000000;
	char which[2];
	int nvalue=-1000000;
		for (i = 0; i <= 7; i++)
		{
			for (j = 0; j <= 7; j++)
			{
				int ii, jj;
				for (ii = 0; ii <= 7; ii++) for (jj = 0; jj <= 7; jj++) s[ii][jj] = ss[ii][jj];
				k[0] = i + '1';
				k[1] = j + 'a';			
				
				if (isvalid(k) == 1)
				{
					if (valuexnow(s) > nvalue)
					{
						nvalue = valuexnow(s);
						which[0] = i+'1'; which[1] = j+'a';
					}
				}
			}
			
		}
		for (i = 0; i <= 7; i++) for (j = 0; j <= 7; j++) s[i][j] = ss[i][j];
		isvalid(which);
}



main()
{
	printf("\nRevers GoGoGo!\n\n\n");
	printf("Claim before start: You can not easily beat me!\n");
	printf("You can start first-<O> you are stupid egg.\n");
	printf("I go then.But I am X-man -<X>\n");
	printf("enter to start\n");
	char enter[1];
	gets(enter);
	int i;
	int j;
	for (i = 0; i <= 7; i++) for (j = 0; j <= 7; j++) s[i][j] = ' ';
	s[3][3] = s[4][4] = 'O';
	s[3][4] = s[4][3] = 'X';
	printnask();
	while (scoreO() + scoreX() <= 63 && scoreO()>0 && scoreX()>0)
	{
		printf("\nPLease enter your move:");
		scanf("%s", &move);
		if (valid(move) == 0) printf("Not a valid move, try again\n");
		else {
			AIgo();
			printnask();
		}
	}
	printf("\nhahahaha!!");
	printf("you =: %d\n", scoreO());
	printf("me =: %d\n", scoreX());
	if (scoreO() > scoreX()) printf("you win!");
	else printf("you fail to win");
	getch();
}
