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
    

    ll n, k;
    unsigned long long quant[101][101];
    while(cin >> n >> k && (k||n)){
       
       for(int i=0; i <= n; i++)
           quant[i][1] = 1;
       for(int i=0; i<=k; i++)
           quant[0][i] = 1;
       for(int i=1; i<=n; i++){
           for(int j=2; j<=k; j++){
              quant[i][j] = (quant[i-1][j] + quant[i][j-1]) % 1000000;
           }
       }
       cout << quant[n][k] << endl;

    }

    return 0;
}
