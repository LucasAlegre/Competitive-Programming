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
    ll male[100];
    ll total[100];
    male[0] = 0;
    total[0] = 1;
    for(int i=1; i<100; i++){
        male[i] = total[i - 1];
        total[i] = male[i] + male[i - 1] + 1;
    }

    while(cin >> n){
        if(n == -1) break;
        cout << male[n] << " " << total[n] << endl;
    }

    return 0;
}
