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
extern char PlayerAttack[100][100];
extern char BotAttack[100][100];
int KolSheepsPlayer = 10;
extern int i, j;
int Length, Kill;

void ShootInPlayer(ll x, ll y, char PD[100][100], char PA[100][100], bool bot = false) {
	i = 0;
	j = 0;
	Length = 0;
	Kill = 0;
	if (PD[x][y] >= '1' && PD[x][y] <= '4') {
		if (PD[x][y] == '1') {
			KolSheepsPlayer--;
		}
		else if (PD[x][y] >= '2') {
			if (PD[x - 1][y] >= '2' || PD[x - 1][y] == 'x' || PD[x + 1][y] >= '2' || PD[x + 1][y] == 'x') {
				i = x;
				while (PD[i][y] >= '2' || PD[i][y] == 'x') {
					Length++;
					if (PD[i][y] == 'x') {
						Kill++;
					}
					i--;
				}
				i = x + 1;
				while (PD[i][y] >= '2' || PD[i][y] == 'x') {
					Length++;
					if (PD[i][y] == 'x') {
						Kill++;
					}
					i++;
				}

				if (Kill == Length) {
					KolSheepsPlayer--;
					i = x + 1;
					while (PD[i][y] >= '2' || PD[i][y] == 'x') {
						i--;
						PA[i][y - 1] = '~';
						PA[i][y + 1] = '~';
					}
					i = x - 1;
					while (PD[i][y] >= '2' || PD[i][y] == 'x') {
						i++;
						PA[i][y - 1] = '~';
						PA[i][y + 1] = '~';
					}
				}
			}
			else if (PD[x][y - 1] >= '2' || PD[x][y - 1] == 'x' || PD[x][y + 1] >= '2' || PD[x][y + 1] == 'x') {
				i = x;
				j = y;
				while (PD[i][j] >= '2' || PD[i][j] == 'x') {
					Length++;
					if (PD[i][j] == 'x') {
						Kill++;
					}
					j--;
				}
				j = y + 1;
				while (PD[i][j] >= '2' || PD[i][j] == 'x') {
					Length++;
					if (PD[i][j] == 'x') {
						Kill++;
					}
					i++;
				}
				if (Kill == Length) {
					KolSheepsPlayer--;
					i = x;
					j = y + 1;
					while (PD[i][j] >= '2' || PD[i][j] == 'x') {
						j--;
						PA[i - 1][j] = '~';
						PA[i + 1][j] = '~';
					}
					j = y - 1;
					while (PD[i][j] >= '2' || PD[i][j] == 'x') {
						j++;
						PA[i - 1][j] = '~';
						PA[i + 1][j] = '~';
					}
				}
			}
		}
		PA[x][y] = 'x';
	}
	else {
		PA[x][y] = '~';
	}
	if (bot == false) {
		rep(i, 1, 22) {
			rep(j, 1, 22) {
				PlayerAttack[i][j] = PA[x][y];
			}
		}
	}
	else {
		rep(i, 1, 22) {
			rep(j, 1, 22) {
				BotAttack[i][j] = PA[x][y];
			}
		}
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