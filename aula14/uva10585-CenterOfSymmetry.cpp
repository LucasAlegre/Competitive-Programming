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
typedef pair<double,double> pdd;

int main(){
    
    int c;
    cin >> c;
    range(0, c){
        set<pdd> points;
        int n; cin >> n;
        range(0, n){
            double x, y; cin >> x >> y;
            points.insert(pdd(x,y));
        }
        pdd c = pdd(0,0);
        for(auto p : points){
            c.first += p.first;
            c.second += p.second;
        }
        c.first /= double(n);
        c.second /= double(n);
        bool ok = true;
        for(auto p : points){
            double x = 2*c.first - p.first;
            double y = 2*c.second - p.second;
            if(points.find(pdd(x,y)) == points.end()){
                ok = false;
                cout << "no" << endl;
                break;
            }
        }
        if(ok)
            cout << "yes" << endl;
    }

    return 0;
}
