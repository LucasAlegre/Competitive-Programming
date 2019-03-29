#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<int> vi;

using namespace std;


int main(){
        
        ll aux,a, b;

        while(cin >> a >> b){
            if(a > b){
                swap(a, b); 
             }
            cout << b - a << endl; 
        }

        return 0;
}
