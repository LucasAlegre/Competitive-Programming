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

typedef struct{
    int r, x ,y;
}Circulo;

int main(){
    
    Circulo c;
    Circulo flor;
    int n;
    while(cin >> c.r >> c.x >> c.y >> flor.r >> flor.x >> flor.y){
        double distancia = sqrt(pow(c.x - flor.x, 2) + pow(c.y - flor.y, 2));
        if(distancia + flor.r <= c.r)
            cout << "RICO" << endl;
        else
            cout << "MORTO" << endl;
    }

    return 0;
}
