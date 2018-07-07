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

int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

int find_gcd(vi &a){
    int r = a[0];
    for(int i = 1; i < a.size(); i++){
        r = gcd(a[i], r);
    }
    return r;
}

int main(){
    
    int T, Q;
    while(cin >> T >> Q && T||Q){
        vi tele;
        range(0, T){
            int pos; cin >> pos;
            tele.push_back(pos);
        }
 
        int g = 2 * find_gcd(tele);

        range(0, Q){
            int S, D; cin >> S >> D;
            bool possible = false;
            if(T == 1){
                if(2*tele[0] - S == D)
                    possible = true;
            }
            else{
                if((D - S) % g == 0){
                    possible = true;
                }
                else{
                    for(int i = 0; i < T; i++){
                        if((2*tele[i] - S - D) % g == 0){
                            possible = true;
                            break;
                        }
                    }
                }
            }
            if(possible)
                cout << "Y";
            else
                cout << "N";
            if(i == Q-1)
                cout << endl;
            else
                cout << " ";
        }
    }

    return 0;
}
