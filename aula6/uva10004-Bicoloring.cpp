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

int main(){
    
    int n, l;
    while(cin >> n){
        if(n == 0) break;
        vector<vi> g(n);
        cin >> l;
        bool colorable = true;
        range(0, l){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vi color(n, -1);
        queue<int> q;
        q.push(0);
        color[0] = 1;
        while(!q.empty() && colorable){
            int node = q.front(); q.pop();
            for(int i : g[node]){
                if(color[node] == color[i])
                    colorable = false;
                else if(color[i] == -1){
                    q.push(i);
                    if(color[node] == 1)
                        color[i] = 0;
                    else if(color[node] == 0)
                        color[i] = 1;
                }

            }
        }
        if(colorable)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;

    }

    return 0;
}
