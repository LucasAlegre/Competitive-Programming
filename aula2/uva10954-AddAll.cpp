#include <bits/stdc++.h> 

typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;

using namespace std;


int main(){
    
    vi x;
    int c;
    while(cin >> c){
        if(c == 0) break;
        x.clear();
        int sum = 0;
        for(int i = 0; i < c; i++){
            int n; cin >> n;
            x.push_back(n);
        }
 
        while(x.size() > 1){
            sort(x.begin(),x.end());
            x[0] += x[1] ;x.erase(x.begin()+1);
            sum += x[0];
        }
        
        cout << sum << endl;



    }

    return 0;
}
