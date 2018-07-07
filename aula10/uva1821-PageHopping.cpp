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
typedef pair<int,int> ii;
typedef map<int,int> mii;
typedef set<int> si;

int bfs(map<int, vi> g, int o, int d){
    map<int, int> dist;
    dist[o] = 0;
    queue<int> q; q.push(o);
    bool found = false;
    while(!q.empty() && !found){
        int u = q.front(); q.pop();
        for(int j = 0; j < g[u].size(); j++){
            int v = g[u][j];
            if(!dist.count(v)){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            if(v == d){
                found = true;
                break;
            }
        }
    }
    return dist[d];
}


int main(){
    int caso = 1;
    int a, b;
    while(cin >> a >> b && (a || b)){
        vector<vi> g(101, vi(101, 1000));
        g[a][b] = 1;
        while(cin >> a >> b && (a || b)){
            g[a][b] = 1;
        }
        
        for(int k = 1; k <= 100; k++){
            for(int i = 1; i <= 100; i++){
                for(int j = 1; j <= 100; j++){
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        int c = 0;
        int total = 0;
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++){
                if(i != j && g[i][j] != 1000){
                    total += g[i][j];
                    c++;
                }
            }
        }

        printf("Case %d: average length between pages = %.3f clicks\n", caso++, (double)total/c);
    }

    return 0;
}
