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
    

    int l, n;
    while(cin >> l){
        if(l == 0) break;
        cin >> n;
        int c[n+2];
        range(1, n+1)
            cin >> c[i];
        c[0] = 0;
        c[n+1] = l;
        int cost[n+2][n+2];
        for(int j = 1; j <= n + 1; j++){
            for(int i = j - 1; i >= 0; i--){
                if(i + 1 == j)
                    cost[i][j] = 0;
                else{
                    cost[i][j] = INT_MAX;
                    for(int k = i + 1; k < j; k++){
                        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                    }
                    cost[i][j] += c[j] - c[i];
                }
            }
        }
        cout << "The minimum cutting is " << cost[0][n+1] << "." << endl;
    }

    return 0;
}
