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
    

    int n;
    cin >> n;
    for(int batata = 0; batata < n ; batata++){
        int m;
        cin >> m;
        vi coins(m);
        range(0,m){
            int num;
            cin >> num;
            coins[i]=num;
        }
        int total = accumulate(coins.begin(), coins.end(),0);
        int metade = total/2;
        int maior = 0;
        vector<vi> custo(m+1, vi(metade+1));
        for(int i=0; i <= m; i++){
            for(int w=0; w <= metade; w++){
                if(i == 0 || w == 0)
                    custo[i][w] = 0;
                else if(w >= coins[i-1]){
                    custo[i][w] = max(coins[i-1] + custo[i-1][w - coins[i-1]], custo[i-1][w]);
                }
                else
                    custo[i][w] = custo[i-1][w];
            }
        }
        cout << (total - 2*custo[m][metade]) << endl;
    }


    return 0;
}
