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

int pai[10100];

struct Edge{
    int a;
    int b;
    int w;
};

bool comp(Edge e1, Edge e2){
    return e1.w < e2.w;
}

int findPai(int u){
    if(pai[u] == u) return u;
    else return pai[u] = findPai(pai[u]);
}

void addPai(int x, int y){
    pai[findPai(y)] = findPai(x);
}

int main(){
    int caso = 1;
    int T, N, M, A; cin >> T;
    range(0, T){
        cin >> N >> M >> A;
        vector<Edge> g;
        range(0, N+1) pai[i] = i;
        range(0, M){
            int X, Y, C;
            cin >> X >> Y >> C;
            Edge e; e.a = X; e.b = Y; e.w = C;
            if(C < A) 
                g.push_back(e);
        }
        sort(g.begin(), g.end(), comp);
        int custo = N*A;
        int airports = N;
        for(int i = 0; i < g.size(); i++){
            if(findPai(g[i].a) != findPai(g[i].b)){
                addPai(g[i].a, g[i].b);
                custo = custo - A + g[i].w;
                airports--;
            }
        }
        cout << "Case #" << caso++ << ": " << custo << " " << airports << endl;
    }

    return 0;
}
