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

#define maxn 10010

vector<int> rankk(maxn);
vector<int> parent(maxn);
vector<int> level(maxn);
vector<int> levelCluster(maxn);
map<string, int> numero;

int find(int i){
    while(i != parent[i])
        i = parent[i];
    return i;
}

void union_set(int i, int j){
    int x = find(i);
    int y = find(j);

    if(x == y) return;

    if(rankk[x] > rankk[y]){
        parent[y] = x;
        levelCluster[x] = max(levelCluster[x], levelCluster[y]);
    }
    else{
        parent[x] = y;
        levelCluster[y] = max(levelCluster[y], levelCluster[x]);
        if(rankk[x] == rankk[y])
            rankk[y]++;
    }
}


int main(){
    
    int n, m, q; cin >> n >> m >> q;

    range(0, n){
        string nome; int l;
        cin >> nome >> l;
        numero[nome] = i;
        level[i] = l;
        levelCluster[i] = l;
        rankk[i] = 0;
        parent[i] = i;
    }
    range(0, m){
        string n1, n2; cin >> n1 >> n2;
        union_set(numero[n1], numero[n2]);
    }

    range(0, q){
        string nome; cin >> nome;
        int x = numero[nome];
        if(parent[x] == x && rankk[x] == 0)
            cout << "S" << endl;
        else if(level[x] >= 5)
            cout << "S" << endl;
        else if(levelCluster[find(x)] <= 5)
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }
    

    return 0;
}
