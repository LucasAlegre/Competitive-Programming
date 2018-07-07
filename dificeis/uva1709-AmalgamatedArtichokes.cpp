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
    
    cout.precision(17);
    int p, a, b, c, d, n;
    while(cin >> p >> a >> b >> c >> d >> n){
        double decline = 0;
        double maior = -DBL_MAX;
        for(int i = 1; i <= n; i++){   
            double price = p*(sin(a*i + b) + cos(c*i + d) + 2); 
            decline = max(decline, maior-price);
            maior = max(maior, price);
        }
        cout << decline << endl;
    }

    return 0;
}
