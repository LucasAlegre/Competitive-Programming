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

ll n = 10000000;
std::vector<bool> is_prime((n+1)>>1,true);

int main(){
    for(auto divisor=3; divisor*divisor <= n; divisor+=2)
        if(is_prime[divisor>>1])
             for(auto candidate=divisor*divisor; candidate <= n; candidate+=2*divisor)
                 is_prime[candidate>>1]=false;

    int t; cin >> t;
    while(t--){
        set<ll> s;
	ll r = 2;
        int N; cin >> N;
        range(0,N){
            ll x; cin >> x;
            s.insert(x);
        }

	if(s.find(1) == s.end()){
	    cout << 0 << endl;
	}
	else if(s.find(2) == s.end()){
	    cout << 1 << endl;
	}
	else{
            for(auto candidate=3; candidate <= n; candidate+=2){
                  if(is_prime[candidate>>1]){
                        r = candidate -1;
			if(s.find(candidate) == s.end()){
                             break;
                        }
		  }	
             }
             cout << r << endl;
				
	}	

    }

    return 0;
}
