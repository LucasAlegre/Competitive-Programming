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

vector<ll> fat(101, -1);
vector<vector<ll>> comb(101, vector<ll>(101));

ll fatorial(ll n){
    if(n == 0 || n == 1)
        return 1;
    if(fat[n] != -1)
        return fat[n];
     
    ll num = n*fatorial(n-1);
    fat[n] = num;
    return num;
}

ll combination(ll n, ll k){
    if(comb[n][k] != -1)
        return comb[n][k];
    if(k > n)
        return 0;
    if(k == n || k == 0)
        return 1;
    ll num = combination(n-1, k-1) + combination(n-1,k);
    comb[n][k] = num;
    return num;

}



int main(){
    
    range(0,101)
        for(int j=0;j<101;j++)
            comb[i][j] = -1;
    ll n, m;
    comb[0][0] = 1;
    comb[0][1] = 0;
    comb[1][0] = 1;
    comb[1][1] = 1;
    while(cin >> n >> m && (n||m)){
        ll r = combination(n, m);
        cout << n <<" things taken " << m << " at a time is " << r << " exactly." << endl;  

    }       

    return 0;
}
