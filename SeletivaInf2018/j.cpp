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

int terra[100][100];
int nterra[100][100];

int main(){
    
    vi vx = {1,-1,0,0};
    vi vy = {0,0,1,-1};
    int n, r, c, k;
    while(cin >> n >> r >> c >> k and n+r+c+k!=0){
        vi odeia(n);
        range(0,n-1){
            odeia[i] = i+1;
        }
        odeia[n-1] = 0;

        for(int i=0; i < r; i++){
            for(int j=0; j < c; j++){
                int x; cin >> x;
                terra[i][j] = x;
                nterra[i][j] = x;
            }
        }

        for(int b = 0; b < k; b++){

            for(int i=0; i < r; i++){
                for(int j=0; j < c; j++){
                    int h = terra[i][j];
                    for(int v=0; v < 4; v++){
                        int x = i + vx[v];
                        int y = j + vy[v];
                        if(x >= 0 && y >= 0 && x < r && y < c){
                            if(odeia[h] == terra[x][y])
                                nterra[x][y] = h;
                        }
                    }
                }
            }

            for(int i=0; i < r; i++){
                for(int j=0; j < c; j++){
                    terra[i][j] = nterra[i][j];
                }
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout << terra[i][j];
                if(j != c-1) cout << " ";
            }
            cout << endl;
        }

    }

    return 0;
}
