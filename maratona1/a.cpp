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

int n, k, ci, si;

bool check(vector<pii> &carros)
{
    int c = 1;

    for(int i=carros.size()-2;i>=0;i--){
        if(carros[i].second > ci && si > carros[i].second)
            
            return false;
       
        if(carros[i].second > ci)
            c++;
          
    }
    if(c > k)
        return false;
    if(si < ci)
        return false;
    return true;
}


int main(){
     
    vector<pii> carros;
    
    while(cin >> n >> k){
        bool ok = true;
        carros.clear();
        if(!n && !k) break;
       
        cin >> ci >> si;
        carros.push_back(make_pair(ci, si));
        if(si < ci) ok = false;
        for(int i=1;i<n;i++){
            cin >> ci >> si;
            carros.push_back(make_pair(ci, si));
            if(ok)
                ok = check(carros);
        }
        if(ok)
            cout << "Sim" << endl;
        else
            cout << "Nao" << endl;

    }

    return 0;
}
