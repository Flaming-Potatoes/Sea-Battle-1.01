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
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
#pragma warning(disable : 4996);
const long long inf = (long long)1e18 + 111;
const int iinf = (int)1e9 + 111;

char c = 'w';
extern char ch;
bool ind = 1;
// Generate Field 
int w, x, y, xx, yy, k, savex, savey, nap, j, i;
bool flag;
//
void PrintFieldPlayerDefense();
void Generate();
void GAME();

int main() {
	setlocale(0, "RUS");
	cout << setw(10)  << "Пожалуйста используйте английскую раскладку." << endl;
	cout << setw(30) << "> > > Enter < < <";
	while(ch != 13)
	ch = getch();
	system("cls");
	cout << setw(31) << "> > >START< < <" << endl << endl;
	cout << setw(25) << "EXIT";
	while (true) {
		char c = getch();
		if (ch != c) {
			if (c == 'W' || c == 'w' || c == 72){
				ind = true;
				system("cls");
				cout << setw(31) << "> > >START< < <" << endl << endl;
				cout << setw(25) << "EXIT";
			}
			else if (c == 'S' || c == 's' || c == 80) {
				ind = false;
				system("cls");
				cout << setw(26) << "START" << endl << endl;
				cout << setw(30) << "> > >EXIT< < <";
			}
		}
		 if (c == 13) {
			if (ind) {
				system("cls");
				GAME();
				return 0;
			}
			else {
				return 0;
			}
		}
		ch = c;
	}
}