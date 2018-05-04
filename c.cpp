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
    while(cin >> n){
        vector<long int> v(n+1, 1);
        vi m {5,10,25,50};
        for(int moeda : m){
            for(int i=moeda; i <= n; i++){
                v[i] = v[i] + v[i-moeda];
            }
        }
        if(v[n] == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << v[n] << " ways to produce " << n << " cents change." << endl;

    }

    return 0;
}
