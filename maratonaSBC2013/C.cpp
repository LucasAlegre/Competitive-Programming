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

    int N, M ,I, a,b,e; 
    map<int, vi> g;
    map<int, int> ids;
    map<int, int> idade;

int bfs(int a){
    vi vis(N+1, 0);
    int jovem = 1000;
    queue<int> q;
    
    q.push(a);
    while(!q.empty()){
        int p = q.front(); q.pop();
        for(int i : g[p]){
            if(vis[i] == 0){
                vis[i] = 1;
                q.push(i);
                if(idade[i] < jovem)
                    jovem = idade[i];
            }
        }
    }
    return jovem;
}


int main(){
    
    cin >> N >> M >> I;
    for(int i = 1; i <= N; i++){
        int id; cin >> id;
        idade[i] = id;  
        ids[i] = i;
    }
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        g[y].push_back(x);
    }
    for(int i = 0; i < I; i++){
        char ins; cin >> ins;
        if(ins == 'T'){
            cin >> a >> b;
            int ax, bx,ay,by;
            ax = ids[a]; bx = ids[b];
            ids[a] = bx; ids[b] = ax;
            
            ay = idade[ids[a]]; by = idade[ids[b]];
            idade[bx] = by; idade[ax] = ay;
        }
        else{
            int e; cin >> e;
            int jovem = bfs(ids[e]);
            if(jovem == 1000)
                cout << "*" << endl;
            else
                cout << jovem << endl;
        }

    }
    return 0;
}
