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

struct point {
    int x, y;
    bool operator < (const point &p) const {
      return x < p.x || (x == p.x && y < p.y);
    }
    bool operator == (const point &o) const {
      return x == o.x && y == o.y;
    }
};

int cross(const point &O, const point &A, const point &B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<point> convex_hull(vector<point> P){
    int n = P.size(), k = 0;
    vector<point> H(2 * n);

    sort(P.begin(), P.end());

    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) 
           k--;
        H[k] = P[i];
        k++;
    }

    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) 
            k--;
        H[k] = P[i];
        k++;
    }

    H.resize(k);
    return H;
}


int main(){
    
    int n;
    while(cin >> n && n != 0){
        vector<point> points;
        int camadas = 0;
        range(0, n){
            int x, y; cin >> x >> y;
            point ponto; ponto.x=x; ponto.y=y;
            points.push_back(ponto);
        }
        while(points.size() > 2){
            vector<point> s = convex_hull(points); 
            set<point> seen;
            while(!s.empty()){
                point p = s[0]; s.erase(s.begin());
                seen.insert(p);
            }
            for(auto &i : points)
                if(!seen.count(i))
                    s.push_back(i);
            points = s;
            camadas++;
	}
        if(camadas % 2 != 0)
            cout << "Take this onion to the lab!" << endl;
        else
            cout << "Do not take this onion to the lab!" << endl;

    }

    return 0;
}
