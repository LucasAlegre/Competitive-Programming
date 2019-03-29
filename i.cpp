/**
 *  Lucas Alegre - 00274693
 *  Computer Science - UFRGS
 *
 *  C++ Competitive Programming Template
 *
 */
#include <bits/stdc++.h> 

using namespace std;

#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())               
#define range(a,b) for(int i=a;i<b;i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

int n, m, k, t;
int matriz[21][21][2001];
int dp[21][21][2001];
int dx[9] = {0,0,0,1,1,1,-1,-1,-1};
int dy[9] = {0,-1,1,0,1,-1,0,1,-1};

int rec(int x, int y, int tempo){
    if(tempo > t) return 0;
    if(x < 1 || x > n || y < 1 || y > m) return 0;
    
    if(dp[x][y][tempo] != -1) return dp[x][y][tempo];
    int value = 0;

    for(int i=0; i<9; i++)
        value = max(value, rec(x+dx[i],y+dy[i], tempo+1));

    if(matriz[x][y][tempo])
        dp[x][y][tempo] = value + 1;
    else
    	dp[x][y][tempo] = value;

    return dp[x][y][tempo];   
}

int main(){
    
    while(cin >> n >> m >> k && (n||m||k)){
        memset(dp, -1, sizeof dp);
	memset(matriz, 0, sizeof matriz);
        range(0, k){
            int x, y; cin >> x >> y >> t;
            matriz[x][y][t] = true;
        }
        int x, y; cin >> x >> y;
        cout << rec(x, y, 0) << endl;
    }

    return 0;
}
