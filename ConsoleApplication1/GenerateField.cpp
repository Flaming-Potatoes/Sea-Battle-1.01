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
extern int w, x, y, xx, yy, k, savex, savey, nap, j, i;
extern bool flag;
char PlayerDefense[100][100];
char PlayerAttack[100][100];
char BotDefense[100][100];
char BotAttack[100][100];
bool checktruepos(char pol[100][100]) {
    rep(w, 1, k) {
        if (x <= 9 && x >= 1 && y <= 9 && y >= 1 && pol[x][y] == '.' && pol[x + 1][y] == '.' && pol[x - 1][y] == '.' && pol[x][y + 1] == '.' && pol[x][y - 1] == '.' &&
            pol[x + 1][y + 1] == '.' && pol[x - 1][y - 1] == '.' && pol[x + 1][y - 1] == '.' && pol[x - 1][y + 1] == '.') xx = xx;
        else return false;
        x = x + xx;
        y = y + yy;
    }
    x = savex;
    y = savey;
    rep(w, 1, k) {
        pol[x][y] = k + 48;
        x = x + xx;
        y = y + yy;
    }
    return true;
}
void generateplace(char poll[100][100]) {
    do {
        xx = 0;
        yy = 0;
        flag = true;
        nap = ll(rand()) % 4 + 1;
        if (nap == 1)  xx = -1;
        else if (nap == 2) yy = 1;
        else if (nap == 3) xx = 1;
        else if (nap == 4) yy = -1;
        x = ll(rand()) % 9 + 1;
        y = ll(rand()) % 9 + 1;
        savex = x;
        savey = y;
    } while (checktruepos(poll) != true);
}
void Generate()
{
    fastio;
    srand(time(NULL));
    rep(i, 0, 90) {
        rep(j, 0, 90) {
            PlayerDefense[i][j] = '.';
            BotDefense[i][j] = '.';
        }
    }
    irep(k, 4, 1) {
        rep(i, 1, abs(4 - k + 1)) {
            generateplace(PlayerDefense);
            generateplace(BotDefense);
        }
    }
    /*
    rep(i, 1, 9) {
        rep(j, 1, 9) {
            c << PlayerDefense[i][j]; space;
        }
        newl;
    }
    newl;*/
    cout << "BotDefense:" << endl;
    rep(i, 1, 9) {
        rep(j, 1, 9) {
            c << BotDefense [i] [j] ; space;
        }
        newl;
    }
}