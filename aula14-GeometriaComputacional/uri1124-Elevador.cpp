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
    
    double l, c, r1, r2;
    while(cin >> l >> c >> r1 >> r2 && (l+c+r1+r2)>0){
        double dx = l - r1 - r2;
        double dy = c - r1 - r2;
        if(dx < 0 || dy < 0)
            cout << "N" << endl;
        else if((dx*dx + dy*dy) >= ((r1+r2)*(r1+r2)) && min(l,c) >= 2*max(r1,r2))
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }

    return 0;
}
