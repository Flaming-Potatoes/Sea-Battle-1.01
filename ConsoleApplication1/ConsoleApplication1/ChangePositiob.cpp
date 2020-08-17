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
void ShootInPlayer(ll x, ll y, char PD[100][100], char PA[100][100], bool bot);
extern char ch;
extern ll cordx, cordy;
extern int i, j;

void ChoosePos() {
    while (true) {
        ch = getch();
        if (ch == 'q' || ch == 'Q') {
            cout << cordx << ' ' << cordy << endl;
            ShootInPlayer(1, 1, PlayerDefense, PlayerAttack, false);
            break;
        }
        if (ch == 'W' || ch == 'w') {
            cordx--;
        }
        if (ch == 'D' || ch == 'd') {
            cordy++;
        }
        if (ch == 'S' || ch == 's') {
            cordx++;
        }
        if (ch == 'A' || ch == 'a') {
            cordy--;
        }
    }
}