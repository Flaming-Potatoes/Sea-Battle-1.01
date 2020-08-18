#include "Header.h"
#pragma warning(disable : 4996);
#define fastio                                                 \
                             ios_base::sync_with_stdio(false); \
                             cin.tie(NULL);
#define ll                   long long
#define MOD                  1000000007
#define rep(i, k, n)         for (i = k; i <= n; i++)
#define repp(i, k, n, x)     for (i = k; i <= n; i = i + x)
#define irep(i, k, n)        for (i = k; i >= n; i--)
#define endl                 "\n"
#define cendl(k)             cout << k << endl;
#define cspace(k)            cout << k << " ";
#define No                   cendl("No");
#define Yes                  cendl("Yes");
#define newl                 cout << endl;
#define space                cout << " ";
#define sz(x)                ((ll)x.size())
#define test                 int tests; cin >> tests; while (tests--)
#define MAX(a, b)            ((a) > (b) ? (a) : (b))
#define MIN(a, b)            ((a) < (b) ? (a) : (b))
#define ABS(x)               ((x) < 0 ? - (x) : (x))
#define pmax(a, b)           if(a < b) swap(a, b);      
#define pmin(a, b)           if(a > b) swap(a, b);
#define c                    cout
#define fx                   cerr << "/////";
#define gcd                  __gcd
using namespace std;
extern char PlayerDefense[100][100];
extern char PlayerAttack[100][100];
extern char BotDefense[100][100];
extern char BotAttack[100][100];
void ShootInPlayer(ll x, ll y, char PD[100][100], char PA[100][100], bool bot);
extern char ch;
extern ll cordx, cordy;
extern int i, j;
void PrintFieldPlayerDefense();
void ChoosePos() {
    while (true) {
        ch = getch();
        if (ch == 'q' || ch == 'Q' || ch == 'é' || ch == 'É') {
            system("cls");
            cout << cordx << ' ' << cordy << endl;
            ShootInPlayer(cordx, cordy, BotDefense, PlayerAttack, false);
            break;
        }
        else if (ch == 'W' || ch == 'w' || ch == 'ö' || ch == 'Ö' || ch == 72) {
            cordx = max(1, cordx - 1);
        }
        else if (ch == 'D' || ch == 'd' || ch == 'â' || ch == 'Â' || ch == 77) {
            cordy = min(9, cordy + 1 - 1 + 1);
        }
        else if (ch == 'S' || ch == 's' || ch == 'û' || ch == 'Û' || ch == 75) {
            cordx = min(9, cordx + 1);
        }
        else if (ch == 'A' || ch == 'a' || ch == 'ô' || ch == 'Ô' || ch == 80) {
            cordy = max(1, cordy - 1);
        }
        system("cls");
        cout << cordx << ' ' << cordy << endl;
        PrintFieldPlayerDefense();
    }
}