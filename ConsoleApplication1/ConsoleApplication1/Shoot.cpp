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
	Length = PD[x][y] - 48;
	Kill = 1;
	cendl(PD[x][y]);
	if (PD[x][y] >= '1' && PD[x][y] <= '4') {
		if (PD[x][y] == '1') {
			PA[x][y] == 'q';
			PA[x - 1][y] == '~';
			PA[x - 1][y - 1] == '~';
			PA[x - 1][y + 1] == '~';
			PA[x + 1][y - 1] == '~';
			PA[x + 1][y + 1] == '~';
			PA[x + 1][y] == '~';
		}
		else if (PD[x][y] >= '1') {
			if (PD[x - 1][y] >= '1' || PD[x + 1][y] >= '1') {
				i = x;
				while (PD[i][y] >= '1') {
					if (PA[i][y] == 'x') {
						Kill++;
					}
					i--;
				}
				i = x + 1;
				while (PD[i][y] >= '1') {
					if (PA[i][y] == 'x') {
						Kill++;
					}
					i++;
				}
				if (Kill == Length) {
					KolSheepsPlayer--;
					i = x + 1;
					do {
						i--;
						PA[i][y - 1] = '~';
						PA[i][y + 1] = '~';
					}
					while (PD[i][y] >= '1');
					PA[i][y] = '~';
					i = x - 1;
					do {
						i++;
						PA[i][y - 1] = '~';
						PA[i][y + 1] = '~';
					}
					while (PD[i][y] >= '1');
					PA[i][y] = '~';
				}
			}
			else if (PD[x][y - 1] >= '1' || PD[x][y + 1] >= '1') {
				i = x;
				j = y;
				while (PD[i][j] >= '1') {
					if (PA[i][j] == 'x') {
						Kill++;
					}
					j--;
				}
				j = y + 1;
				while (PD[i][j] >= '1') {
					if (PA[i][j] == 'x') {
						Kill++;
					}
					i++;
				}
				if (Kill == Length) {
					KolSheepsPlayer--;
					i = x;
					j = y + 1;
					do {
						j--;
						PA[i - 1][j] = '~';
						PA[i + 1][j] = '~';
					} while (PD[i][j] >= '1');
					PA[i][j] = '~';
					j = y - 1;
					do {
						j++;
						PA[i - 1][j] = '~';
						PA[i + 1][j] = '~';
					} while (PD[i][j] >= '1');
					PA[i][j] = '~';
				}
			}
		}
		PA[x][y] = 'x';
	}
	else {
		PA[x][y] = '~';
	}
	cout << Length << " " << Kill << endl;
	if (bot == false) {
		rep(i, 1, 22) {
			rep(j, 1, 22) {
				PlayerAttack[i][j] = PA[i][j];
			}
		}
	}
	else {
		rep(i, 1, 22) {
			rep(j, 1, 22) {
				cendl(-2);
				BotAttack[i][j] = PA[x][y];
			}
		}
	}
}