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


ll catalan[11];
void catalanNumbers(){
    catalan[0] = 1;
    for(int i = 1; i <= 10; i++){
        int n = i - 1;
        catalan[i] = (2*catalan[n]*(2*n + 1))/(n + 2);
    }
}


int main(){
    
    catalanNumbers();
    int n;
    bool first = true;
    while(cin >> n){
        if(first)
            first = false;
        else
            cout << endl;
        cout << catalan[n] << endl;
    }

    return 0;
}
