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
    

    int n, r;
    cin >> n >> r;

    vi p(n+1, 0);
    for(int i = 0; i < r; i++){
        int z; cin >> z;
        p[z] = 1;
    }
    
    if(n == r){
        cout << "*" << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        if(p[i] == 0)
            cout << i << " ";
    }
    cout << endl;


    return 0;
}
