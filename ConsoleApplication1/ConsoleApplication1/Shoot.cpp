#include"Header.h"
#define ll long long
#define rep(i, k, n) for(i=k;i<=n;i++)
#define irep(i, k, n) for(i=k;i>=n;i--)
#define rrep(i, k, n, j) for(i=k;i<=n;i+= j)
#define newl cout << "\n";
#define len(x) x.length()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define cendl(k) cout << k << endl;
#define cspace(k) cout << k << " ";
#define MIN(a, b) (a > b) ? b : a;
#define MAX(a, b) (a > b) ? a : b;

extern char PlayerDefense[100][100];
extern char BotDefense[100][100];
int KolSheepsPlayer = 10;
extern int i, j;
int Length, Kill;

void ShootInPlayer(int x, int y) {
	if (PlayerDefense[x][y] >= '1' && PlayerDefense[x][y] <= '4') {
		if (PlayerDefense[x][y] == '1') {
			KolSheepsPlayer--;
		}
		else if (PlayerDefense[x][y] >= '2') {
			i = 0;
			j = 0;
			Length = 0;
			Kill = 0;
			if (PlayerDefense[x - 1][y] >= '2' || PlayerDefense[x - 1][y] == 'x' || PlayerDefense[x + 1][y] >= '2' || PlayerDefense[x + 1][y] == 'x') {
				i = x;
				while (PlayerDefense[i][y] >= '2' || PlayerDefense[i][y] == 'x') {
					Length++;
					if (PlayerDefense[i][y] == 'x') {
						Kill++;
					}
					i--;
				}
				i = x + 1;
				while (PlayerDefense[i][y] >= '2' || PlayerDefense[i][y] == 'x') {
					Length++;
					if (PlayerDefense[i][y] == 'x') {
						Kill++;
					}
					i++;
				}

				if (Kill == Length) {
					KolSheepsPlayer--;
					i = x + 1;
					while (PlayerDefense[i][y] >= '2' || PlayerDefense[i][y] == 'x') {
						i--;
						PlayerDefense[i][y - 1] = '~';
						PlayerDefense[i][y + 1] = '~';
					}
					i = x - 1;
					while (PlayerDefense[i][y] >= '2' || PlayerDefense[i][y] == 'x') {
						i++;
						PlayerDefense[i][y - 1] = '~';
						PlayerDefense[i][y + 1] = '~';
					}
				}
			}
			else if (PlayerDefense[x][y - 1] >= '2' || PlayerDefense[x][y - 1] == 'x' || PlayerDefense[x][y + 1] >= '2' || PlayerDefense[x][y + 1] == 'x') {
				i = x;
				j = y;
				while (PlayerDefense[i][j] >= '2' || PlayerDefense[i][j] == 'x') {
					Length++;
					if (PlayerDefense[i][j] == 'x') {
						Kill++;
					}
					j--;
				}
				j = y + 1;
				while (PlayerDefense[i][j] >= '2' || PlayerDefense[i][j] == 'x') {
					Length++;
					if (PlayerDefense[i][j] == 'x') {
						Kill++;
					}
					i++;
				}
				if (Kill == Length) {
					KolSheepsPlayer--;
					i = x;
					j = y + 1;
					while (PlayerDefense[i][j] >= '2' || PlayerDefense[i][j] == 'x') {
						j--;
						PlayerDefense[i - 1][j] = '~';
						PlayerDefense[i + 1][j] = '~';
					}
					j = y - 1;
					while (PlayerDefense[i][j] >= '2' || PlayerDefense[i][j] == 'x') {
						j++;
						PlayerDefense[i - 1][j] = '~';
						PlayerDefense[i + 1][j] = '~';
					}
				}
			}
		}
		PlayerDefense[x][y] = 'x';
	}
}

void ShootInBot(int x, int y) {
	if (BotDefense[x][y] >= '1' && BotDefense[x][y] <= '4') {
		if (BotDefense[x][y] == '1') {
			KolSheepsPlayer--;
		}
		else if (BotDefense[x][y] >= '2') {
			i = 0;
			j = 0;
			Length = 0;
			Kill = 0;
			if (BotDefense[x - 1][y] >= '2' || BotDefense[x - 1][y] == 'x' || BotDefense[x + 1][y] >= '2' || BotDefense[x + 1][y] == 'x') {
				i = x;
				while (BotDefense[i][y] >= '2' || BotDefense[i][y] == 'x') {
					Length++;
					if (BotDefense[i][y] == 'x') {
						Kill++;
					}
					i--;
				}
				i = x + 1;
				while (BotDefense[i][y] >= '2' || BotDefense[i][y] == 'x') {
					Length++;
					if (BotDefense[i][y] == 'x') {
						Kill++;
					}
					i++;
				}

				if (Kill == Length) {
					KolSheepsPlayer--;
					i = x + 1;
					while (BotDefense[i][y] >= '2' || BotDefense[i][y] == 'x') {
						i--;
						BotDefense[i][y - 1] = '~';
						BotDefense[i][y + 1] = '~';
					}
					i = x - 1;
					while (BotDefense[i][y] >= '2' || BotDefense[i][y] == 'x') {
						i++;
						BotDefense[i][y - 1] = '~';
						BotDefense[i][y + 1] = '~';
					}
				}
			}
			else if (BotDefense[x][y - 1] >= '2' || BotDefense[x][y - 1] == 'x' || BotDefense[x][y + 1] >= '2' || BotDefense[x][y + 1] == 'x') {
				i = x;
				j = y;
				while (BotDefense[i][j] >= '2' || BotDefense[i][j] == 'x') {
					Length++;
					if (BotDefense[i][j] == 'x') {
						Kill++;
					}
					j--;
				}
				j = y + 1;
				while (BotDefense[i][j] >= '2' || BotDefense[i][j] == 'x') {
					Length++;
					if (BotDefense[i][j] == 'x') {
						Kill++;
					}
					i++;
				}
				if (Kill == Length) {
					KolSheepsPlayer--;
					i = x;
					j = y + 1;
					while (BotDefense[i][j] >= '2' || BotDefense[i][j] == 'x') {
						j--;
						BotDefense[i - 1][j] = '~';
						BotDefense[i + 1][j] = '~';
					}
					j = y - 1;
					while (BotDefense[i][j] >= '2' || BotDefense[i][j] == 'x') {
						j++;
						BotDefense[i - 1][j] = '~';
						BotDefense[i + 1][j] = '~';
					}
				}
			}
		}
		BotDefense[x][y] = 'x';
	}
}