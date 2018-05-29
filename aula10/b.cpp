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

int N, n, m, S, T;

int dijkstra(map<int, vector<ii>> &g, int a, int b){

    priority_queue<ii, vector<ii>, greater<ii>> q;
    vi d(n, -1);
    ii p; int v, w;
    q.push(make_pair(0,a));
    while(!q.empty()){
        p = q.top(); q.pop();
        v = p.second;
        w = p.first;
        if(d[v] != -1) continue;
        if(v == b) return w;
        d[v] = w;
        for(int i = 0; i < g[v].size(); i++){
            if(d[g[v][i].first] == -1){
                q.push(make_pair(w+g[v][i].second, g[v][i].first));
            }
        }
    }
    return -1;
}

int main(){
    int caso = 1;
    cin >> N;
    range(0, N){
        map<int, vector<ii>> g;
        cin >> n >> m >> S >> T;
        range(0, m){
            int a, b, w;
            cin >> a >> b >> w;
            g[a].push_back(make_pair(b, w));
            g[b].push_back(make_pair(a, w));
        }
        int d = dijkstra(g, S, T);
        if(d != -1)
            cout << "Case #"<<caso++<<": "<<d<< endl;
        else
            cout << "Case #"<<caso++<<": "<<"unreachable"<< endl;
    }

    return 0;
}
